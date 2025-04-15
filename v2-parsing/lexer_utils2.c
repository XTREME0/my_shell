/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:38:10 by ariyad            #+#    #+#             */
/*   Updated: 2025/04/13 17:52:54 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// static void	new_str(char *src, char *dst)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	quote;

// 	i = 0;
// 	j = 0;
// 	while (src[i])
// 	{
// 		if (is_quote(src[i]))
// 		{
// 			quote = src[i];
// 			i++;
// 			while (src[i] && src[i] != quote)
// 			{
// 				dst[j] = src[i];
// 				i++;
// 				j++;
// 			}
// 		}
// 		else
// 			dst[j++] = src[i];
// 		i++;
// 	}
// 	dst[j] = 0;
// }

// static void	q_content(char *s, size_t *i, size_t *j)
// {
// 	char	quote;

// 	quote = s[*i];
// 	*i += 1;
// 	while (s[*i] && s[*i] != quote)
// 	{
// 		*i += 1;
// 		*j += 1;
// 	}
// 	*j -= 1;
// }

// static int	concat_str(t_tokens *toks)
// {
// 	char	*new;
// 	size_t	i;
// 	size_t	j;
// 	char	quote;

// 	i = 0;
// 	j = 0;
// 	while (toks->tok_val[i])
// 	{
// 		if (is_quote(toks->tok_val[i]))
// 			q_content(toks->tok_val, &i, &j);
// 		i++;
// 		j++;
// 	}
// 	new = malloc(j + 1 * sizeof(char));
// 	if (!new)
// 		return (0);
// 	i = 0;
// 	new_str(toks->tok_val, new);
// 	free(toks->tok_val);
// 	toks->tok_val = new;
// 	return (1);
// }

// int	remove_quote(t_tokens *toks)
// {
// 	while (toks)
// 	{
// 		if (has_quotes(toks->tok_val))
// 		{
// 			if (!concat_str(toks))
// 				return (0);
// 		}
// 		toks = toks->next;
// 	}
// 	return (1);
// }

// int	replace_expan(char **new, char *str, size_t	*i, t_env *env)
// {
// 	char		*s;
// 	char		*tmp;
// 	static int	j; // will not work on more than one string

// 	s = *new;
// 	*i += 1;
// 	if (str[*i] == 0)
// 	{
// 		tmp = *new;
// 		return (*new = custom_join(tmp, "$"), free(tmp), 1);
// 	}
// 	while (str[*i] && !is_quote(str[*i]) && !ft_isspace(str[*i])
// 		&& !is_redir(str[*i]))
// 	{
// 		*i += 1;
// 		j++;
// 	}
// 	*new = ft_substr(str, *i - j, j);
// 	if (!(*new))
// 		return (free(s), 0);
// 	tmp = *new;
// 	*new = ft_strjoin_plus(s, env_val(env, *new));
// 	return (1);
// }

void	reg_expand(char **s, t_env *env, int tf)
{
	char	*str;
	size_t	i;
	size_t	j;
	char	*val;

	str = *s;
	if (tf || !is_expan(str))
		return ;
	i = 0;
	while (str[i])
	{
		j = i;
		if (str[i] == '$')
		{
			skip_expand(str, &j);
			val = ft_substr(str, i, j - i);
			if (!val)
				return ;
			replace(s, i, j - 1, env_val(env, val));
			i = j - 1;
		}
		i++;
	}
}

int	count_q_words(char	*str)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (!is_quote(str[i]))
			len++;
		i++;
	}
	return (len);
}

int	remove_quote(char **token)
{
	char	*new;
	char	*tok;
	size_t	i;

	new = malloc(count_q_words(*token) + 1);
	if (!new)
		return (0);
	tok = *token;
	i = 0;
	while (*tok)
	{
		if (!is_quote(*tok))
		{
			new[i] = *tok;
			i++;
		}
		tok++;
	}
	new[i] = 0;
	free(*token);
	*token = new;
	return (1);
}
