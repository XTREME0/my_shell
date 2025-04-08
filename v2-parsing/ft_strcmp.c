/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:builtins/pwd.c
/*   Created: 2025/02/17 15:36:43 by ataai             #+#    #+#             */
/*   Updated: 2025/03/17 22:40:03 by ataai            ###   ########.fr       */
=======
/*   Created: 2025/02/17 15:54:23 by ataai             #+#    #+#             */
/*   Updated: 2025/03/13 12:58:18 by ariyad           ###   ########.fr       */
>>>>>>> v2-parsing:v2-parsing/ft_strcmp.c
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_strcmp(char *str1, char *str2)
{
<<<<<<< HEAD:builtins/pwd.c
	char	wd[PATH_MAX];

	if (getcwd(wd, PATH_MAX) == NULL)
		return (-1);
	write(1, wd, ft_strlen(wd));
	write(1, "\n", 1);
	return (0);
=======
	while (*str1 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
>>>>>>> v2-parsing:v2-parsing/ft_strcmp.c
}
