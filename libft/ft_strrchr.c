/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:48:11 by ataai             #+#    #+#             */
/*   Updated: 2024/10/22 12:59:57 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	hh;

	i = 0;
	hh = (char)c;
	while (s[i])
		i++;
	if (hh == '\0')
		return ((char *)(s + i));
	i--;
	while (i >= 0)
	{
		if (s[i] == hh)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
