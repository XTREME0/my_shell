/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:37:58 by ariyad            #+#    #+#             */
/*   Updated: 2025/04/15 14:32:20 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_cmd	*create_nodes(t_tokens *toks)
{
	t_cmd	*cmds;
	t_cmd	*new;

	cmds = NULL;
	while (toks)
	{
		if (toks->tok_type == PIPE)
		{
			new = ft_newcmd();
			if (!new)
				return (ft_clearcmds(&cmds), NULL);
			ft_addcmd(&cmds, new);
		}
		toks = toks->next;
	}
	new = ft_newcmd();
	if (!new)
		return (ft_clearcmds(&cmds), NULL);
	ft_addcmd(&cmds, new);
	return (cmds);
}

void	del_other_cmds(t_cmd *cmd)
{
	t_cmd	*prev;
	t_cmd	*tmp;

	ft_clearcmds(&cmd->next);
	prev = cmd->prev;
	while (prev)
	{
		tmp = prev;
		prev = prev->prev;
		ft_delcmd(tmp);
	}
}

void	advance(t_cmd **head)
{
	t_cmd	*tmp;

	if (!head || !(*head))
		return ;
	tmp = (*head);
	(*head) = (*head)->next;
	ft_delcmd(tmp);
}
