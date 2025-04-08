/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:33:54 by ataai             #+#    #+#             */
/*   Updated: 2025/03/13 13:00:03 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
