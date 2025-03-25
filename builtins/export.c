/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:03:25 by ataai             #+#    #+#             */
/*   Updated: 2025/03/19 15:36:46 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*add_env(char **pair)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (env == NULL)
		return (NULL);
	env->key = pair[0];
	env->val = pair[1];
	env->next = NULL;
	env->prev = NULL;
	free(pair);
	return (env);
}

int	export_add_replace(t_env **env, char **pair)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, pair[0]) == 0)
		{
			free(tmp->val);
			tmp->val = pair[1];
			return (free(pair[0]), free(pair), 0);
		}
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	tmp = add_env(pair);
	if (tmp == NULL)
		return (free(pair[0]), free(pair[1]), free(pair), -1);
	env_add_back(env, tmp);
	return (0);
}

int	sanitize_key(char *key)
{
	int	i;

	i = 0;
	if (ft_isalpha(key[0]) != 1)
		return (-1);
	while (key[i])
	{
		if (key[i] == '+')
		{
			if (key[i + 1] == '\0')
				return (key[i] = '\0', 1);
			return (-1);
		}
		if (!ft_isalnum(key[i]))
			return (-1);
		i++;
	}
	return (0);
}

int	my_export_write(t_env *env, char *arg)
{
	char	**pair;
	char	**args;
	int		flag;
	int		i;

	args = ft_split(arg, ' ');
	if (args == NULL)
		return (-1);
	i = 0;
	while (args[i])
	{
		pair = split_by_two(args[i], '=');
		if (pair == NULL)
			return (free_tab(args), -1);
		flag = sanitize_key(pair[0]);
		if (flag == -1)
			env_error(pair);
		else if (flag == 0)
			export_add_replace(&env, pair);
		else
			append_env(&env, pair);
		i++;
	}
	return (free_tab(args), 0);
}

int	my_export(t_cmd *cmd_node, t_env *my_env)
{
	int	i;

	i = 1;
	if (cmd_node->kwargs[1] == NULL)
		print_export(my_env);
	while (cmd_node->kwargs[i])
	{
		my_export_write(my_env, cmd_node->kwargs[i]); //check failure
		i++;
	}
	return (0);
}
