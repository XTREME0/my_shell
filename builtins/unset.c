/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:46:41 by ataai             #+#    #+#             */
/*   Updated: 2025/03/19 21:17:57 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	unset(t_cmd *cmd, t_env **env)
{
	t_env	*tmp;

	if (env == NULL || *env == NULL || cmd == NULL)
		return (-1);
	if (cmd->kwargs[1] == NULL)
		return (-1);
	tmp = *env;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, cmd->kwargs[1]) == 0)
		{
			if (tmp->prev)
				tmp->prev->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = tmp->prev;
			free(tmp->key);
			free(tmp->val);
			free(tmp);
			break ;
		}
		tmp = tmp->next;
	}
	return (0);
}
