/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:59:56 by ataai             #+#    #+#             */
/*   Updated: 2024/10/22 17:46:35 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	hh;
	unsigned char	*pp;

	hh = (unsigned char)c;
	pp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (pp[i] == hh)
			return (pp + i);
		i++;
	}
	return (NULL);
}
