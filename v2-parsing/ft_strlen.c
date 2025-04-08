/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:builtins/exit.c
/*   Created: 2025/02/24 10:57:32 by ataai             #+#    #+#             */
/*   Updated: 2025/03/19 13:07:31 by ataai            ###   ########.fr       */
=======
/*   Created: 2024/10/21 17:42:38 by ataai             #+#    #+#             */
/*   Updated: 2025/03/13 13:00:38 by ariyad           ###   ########.fr       */
>>>>>>> v2-parsing:v2-parsing/ft_strlen.c
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

<<<<<<< HEAD:builtins/exit.c
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
=======
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
>>>>>>> v2-parsing:v2-parsing/ft_strlen.c
}
