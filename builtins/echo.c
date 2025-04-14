/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:05:44 by ataai             #+#    #+#             */
/*   Updated: 2025/04/14 18:22:05 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	int check_for_option(char *cmd)
{
	int	i;

	if (!cmd || cmd[0] != '-' || cmd[1] != 'n')
		return (0);
	i = 2;
	while (cmd[i])
	{
		if (cmd[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	echo(t_cmd *cmd)
{
	int	option;
	int	i;

	if (cmd == NULL)
		return (1);
	option = check_for_option(cmd->kwargs[1]);
	if (cmd->kwargs && cmd->kwargs[0])
	{
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
