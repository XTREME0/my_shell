/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:28:25 by ataai             #+#    #+#             */
/*   Updated: 2025/03/05 23:55:18 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	set_flag(t_env *env, int f)
{
	while (env)
	{
		env->flag = f;
		env = env->next;
	}
}

void	env_error(char **pair)
{
	free(pair[0]);
	free(pair[1]);
	free(pair);
	write(1, "error hh ghleti or sumn\n", 24); //set correct mesage here
}

int	append_env(t_env **env, char **pair)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, pair[0]) == 0)
		{
			tmp->val = free_join(tmp->val, pair[1]);
			return (free(pair[0]), free(pair), 0);
		}
		tmp = tmp->next;
	}
	tmp = add_env(pair);
	if (tmp == NULL)
		return (free(pair[0]), free(pair[1]), free(pair), -1);
	env_add_back(env, tmp);
	return (0);
}
