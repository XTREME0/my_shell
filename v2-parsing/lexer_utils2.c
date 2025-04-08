/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:38:10 by ariyad            #+#    #+#             */
/*   Updated: 2025/04/08 15:38:11 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	new_str(char *src, char *dst)
{
	size_t	i;
	size_t	j;
	char	quote;

	i = 0;
	j = 0;
	while (src[i])
	{
		if (is_quote(src[i]))
		{
			quote = src[i];
			i++;
			while (src[i] && src[i] != quote)
			{
				dst[j] = src[i];
				i++;
				j++;
			}
		}
		else
			dst[j++] = src[i];
		i++;
	}
	dst[j] = 0;
}

static void	q_content(char *s, size_t *i, size_t *j)
{
	char	quote;

	quote = s[*i];
	*i += 1;
	while (s[*i] && s[*i] != quote)
	{
		*i += 1;
		*j += 1;
	}
	*j -= 1;
}

static int	concat_str(t_tokens *toks)
{
	char	*new;
	size_t	i;
	size_t	j;
	char	quote;

	i = 0;
	j = 0;
	while (toks->tok_val[i])
	{
		if (is_quote(toks->tok_val[i]))
			q_content(toks->tok_val, &i, &j);
		i++;
		j++;
	}
	new = malloc(j + 1 * sizeof(char));
	if (!new)
		return (0);
	i = 0;
	new_str(toks->tok_val, new);
	free(toks->tok_val);
	toks->tok_val = new;
	return (1);
}

int	remove_quote(t_tokens *toks)
{
	while (toks)
	{
		if (has_quotes(toks->tok_val))
		{
			if (!concat_str(toks))
				return (0);
		}
		toks = toks->next;
	}
	return (1);
}
