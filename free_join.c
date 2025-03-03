/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_join.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <ataai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:45:01 by ataai             #+#    #+#             */
/*   Updated: 2025/03/03 14:34:22 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*free_join(char *s1, char *s2)
{
	char	*ptr;
	size_t	l1;
	size_t	l2;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (s2);
	if (s2 == NULL)
		return (s1);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	ptr = (char *)malloc(l1 + l2 + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[0] = '\0';
	ft_strlcat(ptr, s1, l1 + 1);
	ft_strlcat(ptr, s2, l1 + l2 + 1);
	free(s1);
	free(s2);
	return (ptr);
}
