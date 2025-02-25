/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:42:46 by ataai             #+#    #+#             */
/*   Updated: 2025/02/24 21:59:39 by ataai            ###   ########.fr       */
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
		ft_putstr(tmp->key);
		ft_putstr("=");
		ft_putstr(tmp->val);
		ft_putstr("\n");
		tmp = tmp->next;
	}
	return (0);
}
