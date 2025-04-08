/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:builtins/env.c
/*   Created: 2025/02/24 10:42:46 by ataai             #+#    #+#             */
/*   Updated: 2025/03/19 14:04:56 by ataai            ###   ########.fr       */
=======
/*   Created: 2024/10/23 16:57:30 by ataai             #+#    #+#             */
/*   Updated: 2025/03/13 12:57:58 by ariyad           ###   ########.fr       */
>>>>>>> v2-parsing:v2-parsing/ft_strdup.c
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
<<<<<<< HEAD:builtins/env.c
		if (tmp->val)
		{
			if (tmp->key)
				ft_printf("%s=%s\n", tmp->key, tmp->val);
		}
		tmp = tmp->next;
=======
		dst[i] = src[i];
		i++;
>>>>>>> v2-parsing:v2-parsing/ft_strdup.c
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;

	ptr = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strcpy(ptr, s1);
	return (ptr);
}
