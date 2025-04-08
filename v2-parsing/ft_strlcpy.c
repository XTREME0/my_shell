/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:builtins/echo.c
/*   Created: 2025/02/17 12:05:44 by ataai             #+#    #+#             */
/*   Updated: 2025/03/20 00:34:03 by ataai            ###   ########.fr       */
=======
/*   Created: 2024/10/22 10:33:54 by ataai             #+#    #+#             */
/*   Updated: 2025/03/13 12:57:30 by ariyad           ###   ########.fr       */
>>>>>>> v2-parsing:v2-parsing/ft_strlcpy.c
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

<<<<<<< HEAD:builtins/echo.c
//int	echo(char *str, int option)
int	echo(t_cmd *cmd)
{
	int	option;
	int	i;

	if (cmd == NULL)
		return (-1);
	option = 0;
	if (cmd->kwargs && cmd->kwargs[0])
	{
		if (ft_strcmp(cmd->kwargs[1], "-n") == 0)
			option = 1;
		i = option + 1;
		while (cmd->kwargs[i])
		{
			write(1, cmd->kwargs[i], ft_strlen(cmd->kwargs[i]));
			i++;
			if (cmd->kwargs[i])
				write(1, " ", 1);
		}
	}
	if (option == 0)
		write(1, "\n", 1);
	return (0);
=======
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize <= 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
>>>>>>> v2-parsing:v2-parsing/ft_strlcpy.c
}
