/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:57:32 by ataai             #+#    #+#             */
/*   Updated: 2025/04/11 11:02:00 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	my_exit(t_cmd *cmd, t_env **env)
{
	int	x;

	if (cmd == NULL || env == NULL)
		return ;
	x = 0;
	if (cmd->kwargs[1])
		x = ft_atoi(cmd->kwargs[1]);
	while (cmd->prev)
		cmd = cmd->prev;
	ft_clearcmds(&cmd);
	env_clear(*env);
	exit(x);
}
