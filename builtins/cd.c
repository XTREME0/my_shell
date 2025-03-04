/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:43:12 by ataai             #+#    #+#             */
/*   Updated: 2025/03/04 16:16:41 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//just absolute for now

int	set_by_key(t_env **env, char *key, const char *val)
{
	char	**pair;

	pair = malloc(sizeof(char *) * 2);
	if (pair == NULL)
		return (-1);
	pair[0] = ft_strdup(key);
	pair[1] = ft_strdup(val);
	if (pair[0] == NULL || pair[1] == NULL)
	{
		free(pair[0]);
		free(pair[1]);
		free(pair);
	}
	export_add_replace(&env, pair);
	return (0);
}

int	cd(t_env **env, char *str)
{
	char	wd[PATH_MAX];

	if (str == NULL || chdir(str) == -1)
		return (-1);
	getcwd(wd, PATH_MAX);
	set_by_key(env, "PWD", wd);
	// to be continued
	return (0);
}
