/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:33:47 by ataai             #+#    #+#             */
/*   Updated: 2024/10/23 18:28:07 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;

	if (dst == NULL && src == NULL)
		return (NULL);
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (d > s)
	{
		while (len--)
			d[len] = s[len];
		return (dst);
	}
	return (ft_memcpy(dst, src, len));
}

#include <stdio.h>
int main(){
	char m[10] = "hello";
	ft_memmove(m + 3, m, 5);
	printf("%s", m + 3);
}
