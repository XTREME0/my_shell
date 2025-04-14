/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:29:40 by ataai             #+#    #+#             */
/*   Updated: 2025/04/14 17:44:25 by ataai            ###   ########.fr       */
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
		return (cd(my_env, cmd_node->kwargs[1]));
	else if (cmd_node->kwargs[0] && ft_strcmp(cmd_node->kwargs[0], "pwd") == 0)
		return (pwd());
	else if (cmd_node->kwargs[0] && ft_strcmp(cmd_node->kwargs[0], "env") == 0)
		return (print_env(*my_env));
	else if (cmd_node->kwargs[0] && ft_strcmp(cmd_node->kwargs[0], "echo") == 0)
		return (echo(cmd_node));
	else if (cmd_node->kwargs[0] && ft_strcmp(cmd_node->kwargs[0], "exit") == 0)
		return (my_exit(cmd_node, my_env), 0);
	else if (cmd_node->kwargs[0] && ft_strcmp(cmd_node->kwargs[0], "export") == 0)
		return (my_export(cmd_node, *my_env));
	else if (cmd_node->kwargs[0] && ft_strcmp(cmd_node->kwargs[0], "unset") == 0)
		return (unset(cmd_node, my_env));
	return (-1);
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

char	**nodes_to_table(t_env *my_env)
{
	t_env	*tmp;
	char	**env;
	int	len;
	int	i;

	if (my_env == NULL)
		return (NULL);
	len = node_lst_len(my_env);
	env = malloc((len + 1) * sizeof(char *));
	env[len] = NULL;
	i = 0;
	while (i < len)
	{
		env[i] = ft_strdup(my_env->key);
		env[i] = free_join(env[i], ft_strdup("="));
		env[i] = free_join(env[i], ft_strdup(my_env->val));
		i++;
		my_env = my_env->next;
	}
	return (env);
}

void	go_back_clear_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;

	if (cmd == NULL)
		return ;
	while (cmd->prev)
		cmd = cmd->prev;
	while (cmd)
	{
		tmp = cmd->next;
		ft_delcmd(cmd);
		cmd = tmp;
	}
}
void	print_cmd_err(char *cmd)
{
	if (cmd && (cmd[0] == '/' || cmd[0] == '.'))
	{
		write(2, "minishell: ", 11);
		write(2, cmd, ft_strlen(cmd));
		write(2, ": No such file or directory\n", 28);
	}
	else
	{
		if (cmd)
			write(2, cmd, ft_strlen(cmd));
		write(2, ": command not found\n", 20);
	}
}

int	exec_cmd(t_cmd *cmd_node, t_env **my_env)
{
	int	f;
	int	builtin;
	int	err;
	char	**tab_env;
	char	*val;

	if (cmd_node == NULL || cmd_node->kwargs[0] == NULL)
		return (-1);
	builtin = -1;
	if (cmd_node->prev == NULL && cmd_node->next == NULL)
		builtin = exec_builtin(cmd_node, my_env);
	if (builtin != -1)
	{
		val = ft_itoa(builtin);
		set_by_key(my_env, "?", val);
		free(val);
		return (builtin);
	}
	f = fork();
	if (f == 0)
	{
		if (dup2(cmd_node->fd_in, 0) < 0 || dup2(cmd_node->fd_out, 1) < 0)
			return (-1);
		builtin = exec_builtin(cmd_node, my_env);
		if (builtin != -1)
		{
			go_back_clear_cmd(cmd_node);
			env_clear(*my_env);
			exit(0);
		}
		if (access(cmd_node->kwargs[0], X_OK) != 0 && cmd_node->kwargs[0][0] != '.' && cmd_node->kwargs[0][0] != '/')
			cmd_node->kwargs[0] = add_path_tocmd(cmd_node->kwargs[0], *my_env);
		del_other_cmds(cmd_node);
		//if (cmd_node->kwargs[0] == NULL)
		//	write(2, "command not found\n", 18); //add the correct error message here and clear mem to exit
		tab_env = nodes_to_table(*my_env);
		execve(cmd_node->kwargs[0], cmd_node->kwargs, tab_env); //env set as NULL for now. to be changed after!
		free_tab(tab_env);
		err = errno;
		//perror(strerror(err)); // no free?
		print_cmd_err(cmd_node->kwargs[0]);
		//my_close(1, 0, -1, -1);
		close(0);
		close(1);
		close(cmd_node->fd_in);
		close(cmd_node->fd_out);
		exit(err);
	}
	return (f);
}

void	set_exit_status(t_env **my_env, int status)
{
	char	*val;

	val = ft_itoa(status);
	set_by_key(my_env, "?", val);
	free(val);
}

int	exec_setup(t_cmd **cmd_node, t_env **my_env)
{
	int	pfd[2];
	t_cmd	*cmd;
	t_cmd	*tmp;
	int	status;
	int	cpid;

	cmd = *cmd_node;
	if (cmd == NULL)
		return (-1);
	while (cmd)
	{
		if (cmd->next)
		{
			pipe(pfd);
			if (cmd->fd_out == -1)
				cmd->fd_out = pfd[1];
			else
				close(pfd[1]);
			if (cmd->next->fd_in == -1)
				cmd->next->fd_in = pfd[0];
			else
				close(pfd[0]);
		}
		cpid = exec_cmd(cmd, my_env);
		tmp = cmd;
		cmd = cmd->next;
		if (tmp && tmp->fd_in > 2)
			close(tmp->fd_in);
		if (tmp && tmp->fd_out > 2)
			close(tmp->fd_out);
	}
	waitpid(cpid, &status, 0);
	while(wait(NULL) != -1)
		;
	//set_exit_status(my_env, WEXITSTATUS(status));
	//set_exit_status(my_env, status);
	return (0);
}
