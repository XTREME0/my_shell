/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:34:29 by ataai             #+#    #+#             */
/*   Updated: 2025/03/05 15:39:29 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_export(t_env *env)
{
	t_env	*tmp;
	t_env	*small;
	int		i;

	set_flag(env, 0);
	i = node_lst_len(env);
	while (i)
	{
		tmp = env;
		while (tmp && tmp->flag)
			tmp = tmp->next;
		small = tmp;
		while (tmp)
		{
			if (tmp->key && ft_strcmp(small->key, tmp->key) > 0 \
					&& tmp->flag == 0)
				small = tmp;
			tmp = tmp->next;
		}
		small->flag = 1;
		put_export(small);
		i--;
	}
}

int	put_export(t_env *env)
{
	if (env == NULL)
		return (-1);
	if (env->key)
	{
		if (ft_strcmp(env->key, "_") == 0)
			return (0);
		ft_putstr("declare -x ");
		ft_putstr(env->key);
	}
	if (env->val)
	{
		ft_putstr("=\"");
		ft_putstr(env->val);
		ft_putstr("\"");
	}
	ft_putstr("\n");
	return (0);
}
