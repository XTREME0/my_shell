/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:42:46 by ataai             #+#    #+#             */
/*   Updated: 2025/03/04 14:17:22 by ataai            ###   ########.fr       */
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

void	set_flag(t_env *env, int f)
{
	while (env)
	{
		env->flag = f;
		env = env->next;
	}
}

int	node_lst_len(t_env *env)
{
	int	i;

	i = 0;
	while (env)
	{
		i++;
		env = env->next;
	}
	return (i);
}

void	print_export(t_env *env)
{
	t_env	*tmp;
	t_env	*small;
	int	i;

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
			if (tmp->key && ft_strcmp(small->key, tmp->key) > 0 && tmp->flag == 0)
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

//int	print_export(t_env *env)
//{
//	t_env	*tmp;
//
//	if (env == NULL)
//		return (-1);
//	sort_env(env);
//	tmp = env;
//	while (tmp)
//	{
//		if (tmp->key)
//		{
//			ft_putstr("declare -x ");
//			ft_putstr(tmp->key);
//		}
//		if (tmp->val)
//		{
//			ft_putstr("=\"");
//			ft_putstr(tmp->val);
//			ft_putstr("\"");
//		}
//		ft_putstr("\n");
//		tmp = tmp->next;
//	}
//	return (0);
//}
