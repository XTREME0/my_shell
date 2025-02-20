/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:36:43 by ataai             #+#    #+#             */
/*   Updated: 2025/02/17 16:48:15 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	pwd(char **env)
{
	char	*wd;
	
	if (env == NULL)
		return (-1);
	wd = getcwd();
	while (*env)
	{
		if (ft_strncmp(*env, "PWD=", 4) == 0)
		{
			write(1, *env + 4, ft_strlen(*env) - 4);
			return (0);
		}
		env++;
	}
	return (-1);
}

int	main(int argc, char **argv, char **env)
{
	pwd(env);
	write(1, "\n", 1);
}
