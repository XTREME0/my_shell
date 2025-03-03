/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:42:46 by ataai             #+#    #+#             */
/*   Updated: 2025/02/26 16:26:42 by ataai            ###   ########.fr       */
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
				ft_putstr(tmp->key);
			ft_putstr("=");
			ft_putstr(tmp->val);
			ft_putstr("\n");
		}
		tmp = tmp->next;
	}
	return (0);
}

void	flag_init(t_env *env)
{
	if (env == NULL)
		return ;
	while (env)
	{
		env->flag = 0;
		env = env->next;
	}
}

void	sort_env(t_env *env)
{
	return ;
}

int	print_export(t_env *env)
{
	t_env	*tmp;

	if (env == NULL)
		return (-1);
	sort_env(env);
	tmp = env;
	while (tmp)
	{
		if (tmp->key)
		{
			ft_putstr("declare -x ");
			ft_putstr(tmp->key);
		}
		if (tmp->val)
		{
			ft_putstr("=\"");
			ft_putstr(tmp->val);
			ft_putstr("\"");
		}
		ft_putstr("\n");
		tmp = tmp->next;
	}
	return (0);
}
