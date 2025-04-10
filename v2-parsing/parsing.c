/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:40:40 by ariyad            #+#    #+#             */
/*   Updated: 2025/04/10 15:30:25 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_cmd	*construct_cmds(char *str)
{
	t_tokens	*toks;
	t_cmd		*cmds;

	toks = tokenize(str);
	if (!toks)
		return (NULL);
	cmds = create_nodes(toks);
	if (!cmds)
		return (ft_cleartoks(&toks), NULL);
	if (!set_args(cmds, toks))
		return (ft_cleartoks(&toks), NULL);
	redir_pipe(cmds);
	if (!open_redirs(cmds, toks))
		return (ft_cleartoks(&toks), NULL);
	return (ft_cleartoks(&toks), cmds);
}
