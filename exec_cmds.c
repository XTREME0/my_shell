/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:29:40 by ataai             #+#    #+#             */
/*   Updated: 2025/03/13 21:17:27 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//int	here_doc(t_cmd *cmd_node)
//{
//	
//}

//int	exec_builtin(t_cmd *cmd_node)
//{
//	if (cmd_node == NULL || cmd_node->cmd_args == NULL)
//		return (-1);
//	while (cmd_node
//}

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
		return (free(cmd), NULL);
	i = 0;
	while (path[i])
	{
		full_cmd = free_join(full_cmd, ft_strdup(path[i]));
		full_cmd = free_join(full_cmd, ft_strdup("/"));
		full_cmd = free_join(full_cmd, ft_strdup(cmd));
		if (access(full_cmd, X_OK) == 0)
			return (free(cmd), free_table(path), full_cmd);
		free(full_cmd);
		full_cmd = NULL;
		i++;
	}
	return (free_table(path), free(cmd), NULL);
}

int	exec_cmd(t_cmd *cmd_node, t_env *my_env)
{
	int	f;
//	int	builtin;

	if (cmd_node == NULL)
		return (-1);
	//builtin = exec_builtin(cmd_node);
//	if (builtin != 1)
//		return (builtin);
	f = fork();
	if (f == 0)
	{
		if (dup2(cmd_node->fd_in, 0) < 0 || dup2(cmd_node->fd_out, 1) < 0)
			return (-1);
		if (access(cmd_node->kwargs[0], X_OK) != 0)
			cmd_node->kwargs[0] = add_path_tocmd(cmd_node->kwargs[0], my_env);
		if (cmd_node->kwargs[0] == NULL)
			write(2, "command not found\n", 18); //add the correct error message here and clear mem to exit
		execve(cmd_node->kwargs[0], cmd_node->kwargs, NULL); //end set as NULL for now. to be changed after!
		printf("execve makhdmatch hh\n\n"); // remove
		//my_close(1, 0, -1, -1);
		close(1);
		close(0);
	}
	return (0);
}

int	exec_setup(t_cmd **cmd_node, t_env *my_env)
{
	int	pfd[2];
	t_cmd	*cmd;

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
		cmd = cmd->next;
	}
	return (0);
}
