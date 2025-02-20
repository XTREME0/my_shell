/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:43:19 by ataai             #+#    #+#             */
/*   Updated: 2024/10/25 16:18:28 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_banned(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	while (is_banned(s1[i], set))
		i++;
	j = ft_strlen(s1) - 1;
	while (is_banned(s1[j], set))
		j--;
	return (ft_substr(s1, i, j + 1 - i));
}
