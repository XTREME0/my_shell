/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:38:19 by ariyad            #+#    #+#             */
/*   Updated: 2025/04/13 16:27:28 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_tokens	*ft_newtoken(char *tok_val)
{
	t_tokens	*new;

	new = malloc(sizeof(t_tokens));
	if (!new)
		return (NULL);
	new->tok_val = tok_val;
	new->tok_type = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_token_add(t_tokens **head, t_tokens *new)
{
	t_tokens	*tmp;

	if (head && new)
	{
		if (!(*head))
		{
			(*head) = new;
			return ;
		}
		tmp = (*head);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
	return ;
}

void	ft_firsttok(t_tokens **head)
{
	if (!head || !(*head))
		return ;
	while ((*head)->prev)
		(*head) = (*head)->prev;
	return ;
}

void	ft_cleartoks(t_tokens **head)
{
	t_tokens	*tmp;

	while ((*head))
	{
		tmp = (*head);
		(*head) = (*head)->next;
		free(tmp->tok_val);
		free(tmp);
	}
}

// void	ft_token_replace(t_tokens **head, t_tokens *new_lst)
// {
// 	t_tokens	*tmp;

// 	if (!head || !(*head) || !new_lst)
// 		return ;
// 	tmp = (*head);
// 	if (tmp->prev)
// 	{
// 		tmp->prev->next = new_lst;
// 		new_lst->prev = tmp->prev;
// 	}
// 	while (new_lst->next)
// 		new_lst = new_lst->next;
// 	if (tmp->next)
// 	{
// 		new_lst->next = tmp->next;
// 		tmp->next->prev = new_lst;
// 	}
// 	(*head) = new_lst;
// 	free(tmp->tok_val);
// 	free(tmp);
// }
