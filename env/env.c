/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:23:10 by ariyad            #+#    #+#             */
/*   Updated: 2025/02/24 11:26:10 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static void	get_envp(t_envars **genv, char **envp)
{
	size_t	i;
	char	*name;
	char	*value

	i = 0;
	while (envp[i])
	{
		subtr_env(envp[i], &name, &value);
		ft_envadd(genv, ft_env_new(name, value));
		i++;
	}
	
}

t_env	*env_init(char **envp)
{
	static t_env	*env;

	env->genv = NULL;
	env->tenv = NULL;
	get_envp(&env->genv, envp);
	return (env);
}
