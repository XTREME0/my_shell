/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:42:46 by ataai             #+#    #+#             */
/*   Updated: 2025/03/05 23:36:56 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	print_env(t_env *env)
{
	t_env	*tmp;

	if (env == NULL)
		return (-1);
	tmp = env;
	while (tmp)
	{
		if (tmp->val)
		{
			if (tmp->key)
			{
				ft_putstr(tmp->key);
				ft_putstr("=");
				ft_putstr(tmp->val);
				ft_putstr("\n");
			}
		}
		tmp = tmp->next;
	}
	return (0);
}
