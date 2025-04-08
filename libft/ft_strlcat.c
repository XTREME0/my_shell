/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:33:54 by ataai             #+#    #+#             */
/*   Updated: 2024/10/23 18:56:56 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	src_l;

	j = ft_strlen(dst);
	src_l = ft_strlen(src);
	if (j >= dstsize || dstsize == 0)
		return (src_l + dstsize);
	i = 0;
	while (src[i] && (i + j) < dstsize - 1)
	{
		dst[i + j] = src[i];
		i++;
	}
	dst[i + j] = '\0';
	return (src_l + j);
}
