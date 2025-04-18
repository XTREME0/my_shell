/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:36:37 by ariyad            #+#    #+#             */
/*   Updated: 2025/04/15 14:39:58 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_pipe(t_cmd **cmd)
{
	(*cmd)->fd_out = -1;
	if (!(*cmd)->next)
		(*cmd)->next->fd_in = -1;
	(*cmd) = (*cmd)->next;
}

int	open_check(t_redirs *redir, int perm)
{
	redir->fd = open(redir->filename, perm, 0644);
	if (redir->fd == -1)
	{
		fd_printf(2, FD_ERR, redir->filename, strerror(errno));
		return (0);
	}
	return (1);
}
