/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:45:01 by ataai             #+#    #+#             */
/*   Updated: 2024/11/01 22:45:51 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	l1;
	size_t	l2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	ptr = (char *)malloc(l1 + l2 + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[0] = '\0';
	ft_strlcat(ptr, s1, l1 + 1);
	ft_strlcat(ptr, s2, l1 + l2 + 1);
	return (ptr);
}
