/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:48:50 by ariyad            #+#    #+#             */
/*   Updated: 2025/04/15 18:48:51 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	main(int ac, char **av, char **envp)
{
	t_env	*env;

	env = my_setenv(envp);
	char *str = readline("$> ");
	t_cmd	*cmds = construct_cmds(str, env);
	ft_clearcmds(&cmds);
	env_clear(env);
	free(str);
}
