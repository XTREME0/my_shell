/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:36:37 by ariyad            #+#    #+#             */
/*   Updated: 2025/04/12 12:48:30 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	set_pipe(t_cmd **cmd)
{
	(*cmd)->fd_out = -1;
	if (!(*cmd)->next)
		(*cmd)->next->fd_in = -1;
	(*cmd) = (*cmd)->next;
}

int	open_check(t_redirs *redir, int perm)
{
	char	*msg;

	redir->fd = open(redir->filename, perm, 0644);
	if (redir->fd == -1)
	{
		msg = strerror(errno);
		fd_printf(2, FD_ERR, redir->filename, msg);
		free(msg);
		return (0);
	}
	return (1);
}
