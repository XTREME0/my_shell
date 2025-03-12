/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:29:40 by ataai             #+#    #+#             */
/*   Updated: 2025/03/12 23:08:59 by ataai            ###   ########.fr       */
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

int	exec_cmd(t_cmd *cmd_node)
{
	int	f;
//	int	builtin;

	if (cmd_node == NULL)
		return (-1);
	//builtin = exec_builtin(cmd_node);
//	if (builtin != 1)
//		return (builtin);
	f = fork();
	ft_printf("kwarg = %s\n", cmd_node->kwargs[0]);
	if (f == 0)
	{
		if (dup2(cmd_node->fd_in, 0) < 0 || dup2(cmd_node->fd_out, 1) < 0)
			return (-1);
		execve(cmd_node->kwargs[0], cmd_node->kwargs, NULL); //end set as NULL for now. to be changed after!
		//my_close(1, 0, -1, -1);
	}
	return (0);
}

int	exec_setup(t_cmd *cmd_node)
{
	int	pfd[2];

	if (cmd_node == NULL)
		return (-1);
	while (cmd_node)
	{
		//if (cmd->hd_delim)
		//	cmd_node->fd_in = here_doc(cmd_node);
		if (cmd_node->next && cmd_node->fd_out == -1)
		{
			pipe(pfd);
			cmd_node->fd_out = pfd[1];
			cmd_node->next->fd_in = pfd[0];
		}
		exec_cmd(cmd_node);
		cmd_node = cmd_node->next;
	}
	return (0);
}
