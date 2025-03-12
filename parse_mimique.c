/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mimique.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:54:53 by ataai             #+#    #+#             */
/*   Updated: 2025/03/11 13:24:43 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*add_cmd(char **cmd_args)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (cmd == NULL)
		return (NULL);
	//cmd->cmd = str_cmd;
	cmd->args = cmd_args;
	cmd->fd_in = 0;
	cmd->fd_out = 1;
	cmd->is_append = 0;
	cmd->is_heredoc = 0;
	cmd->heredoc_delim = NULL;
	cmd->next = NULL;
	cmd->prev = NULL;
	return (cmd);
}

void	cmd_add_back(t_cmd **lst, t_cmd *new)
{
	if (lst != NULL)
	{
		if (*lst == NULL)
		{
			*lst = new;
		}
		else
		{
			new->prev = cmdlast(*lst);
			if (cmdlast(*lst) != NULL)
				cmdlast(*lst)->next = new;
		}
	}
}

t_cmd	*cmdlast(t_cmd *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

