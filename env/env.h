/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:16:10 by ariyad            #+#    #+#             */
/*   Updated: 2025/02/24 12:18:48 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

typedef struct s_envars
{
	char			*name;
	char			*value;
	struct s_envars	*next;
}	t_envars;

typedef struct s_env
{
	t_envars	*genv;
	t_envars	*tenv;
}	t_env;

void		subtr_env(char *str, char **name, char **value);
void		ft_envadd(t_envars **head, t_envars *new);
t_envars	*ft_env_new(char *name, char *value);

#endif
