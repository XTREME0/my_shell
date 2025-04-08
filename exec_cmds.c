/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:29:40 by ataai             #+#    #+#             */
/*   Updated: 2025/04/08 19:22:16 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//int	here_doc(t_cmd *cmd_node)
//{
//	
//}

int	exec_builtin(t_cmd *cmd_node, t_env **my_env)
{
	if (cmd_node == NULL || cmd_node->kwargs == NULL)
		return (-1);
	if (cmd_node->kwargs[0] && ft_strcmp(cmd_node->kwargs[0], "cd") == 0)
		return (cd(my_env, cmd_node->kwargs[1]), 0);
	else if (cmd_node->kwargs[0] && ft_strcmp(cmd_node->kwargs[0], "pwd") == 0)
		return (pwd(), 0);
	else if (cmd_node->kwargs[0] && ft_strcmp(cmd_node->kwargs[0], "env") == 0)
		return (print_env(*my_env), 0);
	else if (cmd_node->kwargs[0] && ft_strcmp(cmd_node->kwargs[0], "echo") == 0)
		return (echo(cmd_node), 0);
	else if (cmd_node->kwargs[0] && ft_strcmp(cmd_node->kwargs[0], "exit") == 0)
		return (my_exit(cmd_node, my_env), 0);
	else if (cmd_node->kwargs[0] && ft_strcmp(cmd_node->kwargs[0], "export") == 0)
		return (my_export(cmd_node, *my_env), 0);
	else if (cmd_node->kwargs[0] && ft_strcmp(cmd_node->kwargs[0], "unset") == 0)
		return (unset(cmd_node, my_env), 0);
	return (1);
}

char	**get_path(t_env *env)
{
	char	**path;

	if (env == NULL)
		return (NULL);
	while (env)
	{
		if (ft_strncmp(env->key, "PATH", 4) == 0)
		{
			path = ft_split(env->val, ':');
			if (path == NULL)
				exit(1);
			return (path);
		}
		env = env->next;
	}
	return (NULL);
}

char	*add_path_tocmd(char *cmd, t_env *my_env)
{
	char	*full_cmd;
	size_t	i;
	char	**path;

	full_cmd = NULL;
	if (access(cmd, X_OK) == 0)
		return (cmd);
	path = get_path(my_env);
	if (path == NULL)
		return (cmd);
	i = 0;
	while (path[i])
	{
		full_cmd = free_join(full_cmd, ft_strdup(path[i]));
		full_cmd = free_join(full_cmd, ft_strdup("/"));
		full_cmd = free_join(full_cmd, ft_strdup(cmd));
		if (access(full_cmd, X_OK) == 0)
			return (free_table(path), full_cmd);
		free(full_cmd);
		full_cmd = NULL;
		i++;
	}
	return (free_table(path), cmd);
}

//char	**nodes_to_table(t_env *my_env)
//{
//	t_env	*tmp;
//	char	**env;
//	int	i;
//
//	if (my_env == NULL)
//		return (NULL);
//	tmp = *my_env;
//	i = 0;
//	while (tmp)
//	{
//		i++;
//		tmp = tmp->next;
//	}
//	env = malloc((i + 1) * sizeof(char *));
//	env[i] = NULL;
//	//to be continued ...
//
//}

int	exec_cmd(t_cmd *cmd_node, t_env **my_env)
{
	int	f;
	int	builtin;
	int	err;

	if (cmd_node == NULL)
		return (-1);
	builtin = exec_builtin(cmd_node, my_env);
	if (builtin != 1)
		return (builtin);
	f = fork();
	if (f == 0)
	{
		if (dup2(cmd_node->fd_in, 0) < 0 || dup2(cmd_node->fd_out, 1) < 0)
			return (-1);
		if (access(cmd_node->kwargs[0], X_OK) != 0)
			cmd_node->kwargs[0] = add_path_tocmd(cmd_node->kwargs[0], *my_env);
		//if (cmd_node->kwargs[0] == NULL)
		//	write(2, "command not found\n", 18); //add the correct error message here and clear mem to exit
		execve(cmd_node->kwargs[0], cmd_node->kwargs, NULL); //env set as NULL for now. to be changed after!
		err = errno;
		perror(strerror(err)); // no free?
		//my_close(1, 0, -1, -1);
		close(1);
		close(0);
		exit(err);
	}
	return (0);
}

int	exec_setup(t_cmd **cmd_node, t_env **my_env)
{
	int	pfd[2];
	t_cmd	*cmd;
	t_cmd	*tmp;
	int	status;

	cmd = *cmd_node;
	if (cmd == NULL)
		return (-1);
	while (cmd)
	{
		if (cmd->next && cmd->fd_out == -1)
		{
			pipe(pfd);
			cmd->fd_out = pfd[1];
			cmd->next->fd_in = pfd[0];
		}
		exec_cmd(cmd, my_env);
		tmp = cmd;
		cmd = cmd->next;
	}
	while(wait(NULL) != -1)
		;
	printf("-----------------exit status = %d\n", status);
	//close(tmp->fd_in);
	tmp->fd_in = -1;
	return (0);
}
