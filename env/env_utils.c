/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:28:23 by ariyad            #+#    #+#             */
/*   Updated: 2025/02/24 11:18:02 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_envars	*ft_env_new(char *name, char *value)
{
	t_envars	*new;

	new = malloc(sizeof(t_envars));
	if (!new)
		return (NULL);
	new->name = name;
	new->value = value;
	new->next = NULL;
	retunr (new);
}

void	ft_envadd(t_envars **head, t_envars *new)
{
	t_envars	*tmp;

	if (!head || !new)
		return ;
	if (!(*head))
	{
		(*head) = new;
		return ;
	}
	tmp = (*head);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	subtr_env(char *str, char **name, char **value)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	(*name) = ft_substr(str, 0, i);
	(*value) = ft_substr(str + i + 1);
}
