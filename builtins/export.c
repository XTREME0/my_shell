/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:03:25 by ataai             #+#    #+#             */
/*   Updated: 2025/03/04 14:42:31 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
			break;
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
		if (tmp->next == NULL)
			break;
		tmp = tmp->next;
	}
	tmp = add_env(pair);
	if (tmp == NULL)
		return (free(pair[0]), free(pair[1]), free(pair), -1);
	env_add_back(env, tmp);
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

int	my_export_write(t_env *env, char *arg)
{
	char	**pair;
	char	**args;
	int	flag;
	int	i;

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
		{
			env_error(pair);
			i++;
			continue;
		}
		else if (flag == 0)
			export_add_replace(&env, pair);
		else
			append_env(&env, pair);
		i++;
	}
	return (free_tab(args), 0);
}
