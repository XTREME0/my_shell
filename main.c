/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:24:30 by ataai             #+#    #+#             */
/*   Updated: 2025/02/20 11:55:25 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	*prompt;

	while (1)
	{
		prompt = readline("$");
		if (prompt == NULL)
			break ;
		printf("%s\n", prompt);
		free(prompt);
	}
	return (0);
}
