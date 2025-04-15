/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:38:06 by ariyad            #+#    #+#             */
/*   Updated: 2025/04/15 14:42:19 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_tokens	*tokenize(char *str)
{
	t_tokens	*toks;
	t_tokens	*head;

	toks = input_split(str);
	if (!toks)
		return (NULL);
	head = toks;
	assign_redirs(toks);
	assign_files(toks);
	assign_cmds(toks);
	assign_words(toks);
	// assign_expans(toks);
	// if (!rm_q_n_expand(toks))
	// 	return (ft_cleartoks(&head), NULL);
	// assign_cmds(toks);
	// assign_words(toks);
	return (toks);
}

// expand and remove quotes at the same time
// if there is no expan, remove quotes
// if expan is not in quotes, expand and split to new token
// else, just expand in double quotes
