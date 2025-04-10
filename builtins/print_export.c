/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:34:29 by ataai             #+#    #+#             */
/*   Updated: 2025/04/08 19:21:26 by ataai            ###   ########.fr       */
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
		printf("declare -x %s", env->key);
	}
	if (env->val)
		printf("=\"%s\"", env->val);
	printf("\n");
	return (0);
}
