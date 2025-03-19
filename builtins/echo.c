/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:05:44 by ataai             #+#    #+#             */
/*   Updated: 2025/03/18 17:14:45 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//int	echo(char *str, int option)
int	echo(t_cmd *cmd)
{
	int	option;

	if (cmd == NULL)
		return (-1);
	option = 0;
	if (cmd->kwargs && cmd->kwargs[0])
	{
		if (ft_strcmp(cmd->kwargs[1], "-n") == 0)
			option = 1;
		write(1, cmd->kwargs[option + 1], ft_strlen(cmd->kwargs[option + 1]));
	}
	if (!option)
		write(1, "\n", 1);
	return (0);
}
