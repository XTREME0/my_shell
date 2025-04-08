/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:22:07 by ataai             #+#    #+#             */
/*   Updated: 2024/10/22 12:59:46 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	hh;

	i = 0;
	hh = (char)c;
	while (s[i])
	{
		if (s[i] == hh)
			return ((char *)(s + i));
		i++;
	}
	if (hh == '\0')
		return ((char *)(s + i));
	return (NULL);
}
