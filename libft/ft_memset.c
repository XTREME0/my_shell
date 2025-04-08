/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:41:27 by ataai             #+#    #+#             */
/*   Updated: 2024/11/01 17:05:01 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	hh;
	unsigned char	*p;

	hh = (unsigned char)c;
	p = (unsigned char *)b;
	while (len > 0)
	{
		*p = hh;
		p++;
		len--;
	}
	return (b);
}
