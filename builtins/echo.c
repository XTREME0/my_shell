/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:05:44 by ataai             #+#    #+#             */
/*   Updated: 2025/03/20 00:34:03 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
}
