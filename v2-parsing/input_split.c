/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:38:27 by ariyad            #+#    #+#             */
/*   Updated: 2025/04/08 15:38:28 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_tokens	*input_split(char *str)
{
	size_t		i;
	t_tokens	*toks;

	if (!str)
		return (NULL);
	i = 0;
	toks = NULL;
	while (str[i])
	{
		skip_spaces(str, &i);
		if (!get_word(str, &i, &toks))
			return (ft_cleartoks(&toks), NULL);
		skip_spaces(str, &i);
		if (!get_redir(str, &i, &toks))
			return (ft_cleartoks(&toks), NULL);
	}
	return (toks);
}
