/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:37:04 by ariyad            #+#    #+#             */
/*   Updated: 2025/04/15 19:47:49 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	has_quotes(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			return (1);
		i++;
	}
	return (0);
}

int	is_expan(char *val)
{
	size_t	i;

	if (!val)
		return (0);
	i = 0;
	while (val[i])
	{
		if (val[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

char	*env_val(t_env *env, char *exp)
{
	while (env)
	{
		if (ft_strcmp(env->key, exp))
		{
			env = env->next;
			continue ;
		}
		if (!env->val)
			return (NULL);
		return (ft_strdup(env->val));
	}
	return (NULL);
}