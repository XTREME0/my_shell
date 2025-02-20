/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:21:09 by ataai             #+#    #+#             */
/*   Updated: 2024/10/25 21:29:19 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wc(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*fucknorm(char const *s, char c, size_t	*start)
{
	char	*word;
	size_t	i;

	while (s[*start] && s[*start] == c)
		*(start) += 1;
	i = *start;
	while (s[*start] && s[*start] != c)
		*(start) += 1;
	word = (char *)malloc(*start - i + 1);
	if (word == NULL)
		return (NULL);
	ft_strlcpy(word, s + i, *start - i + 1);
	return (word);
}

static void	safe_free(char	**big_pp, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		free(big_pp[i++]);
	free(big_pp);
}

char	**ft_split(char const *s, char c)
{
	char	**big_pp;
	size_t	word_c;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	word_c = wc(s, c);
	big_pp = (char **)malloc((word_c + 1) * sizeof(char *));
	if (big_pp == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < word_c)
	{
		big_pp[i] = fucknorm(s, c, &j);
		if (big_pp[i] == NULL)
		{
			safe_free(big_pp, i);
			return (NULL);
		}
		i++;
	}
	big_pp[i] = NULL;
	return (big_pp);
}
