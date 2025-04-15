/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:38:22 by ariyad            #+#    #+#             */
/*   Updated: 2025/04/15 19:38:37 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	skip_spaces(char *s, size_t *i)
{
	while (s[*i] && ft_isspace(s[*i]))
		*i += 1;
}

void	skip_q_content(char *s, size_t *i)
{
	char	quote;

	quote = s[*i];
	*i += 1;
	while (s[*i] && s[*i] != quote)
		*i += 1;
}

int	get_redir(char *s, size_t *i, t_tokens **head)
{
	char		*word;
	t_tokens	*new;

	if (!is_redir(s[*i]))
		return (1);
	if ((s[*i] == '>' || s[*i] == '<') && s[*i + 1] == s[*i])
	{
		word = ft_substr(s, *i, 2);
		if (!word)
			return (0);
		*i += 2;
	}
	else
	{
		word = ft_substr(s, *i, 1);
		if (!word)
			return (0);
		*i += 1;
	}
	new = ft_newtoken(word);
	if (!new)
		return (0);
	ft_token_add(head, new);
	return (1);
}

int	get_word(char *s, size_t *i, t_tokens **head)
{
	size_t		start;
	char		quote;
	char		*word;
	t_tokens	*new;

	if (is_redir(s[*i]))
		return (1);
	start = *i;
	while (s[*i] && !is_redir(s[*i]) && !ft_isspace(s[*i]))
	{
		if (is_quote(s[*i]))
			skip_q_content(s, i);
		*i += 1;
	}
	word = ft_substr(s, start, *i - start);
	if (!word)
		return (0);
	new = ft_newtoken(word);
	if (!new)
		return (0);
	ft_token_add(head, new);
	return (1);
}

void	skip_expand(char *str, size_t *i)
{
	while (str[*i] && !ft_isspace(str[*i]) && !is_redir(str[*i])
		&& !is_quote(str[*i]) && str[*i] != '.' && str[*i] != '$')
		*i += 1;
}
