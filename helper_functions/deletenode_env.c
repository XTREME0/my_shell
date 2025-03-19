/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deletenode_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:35:36 by ataai             #+#    #+#             */
/*   Updated: 2025/03/19 21:19:20 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//void    del_env_node(t_env **head, t_env *new_lst)
//{
//	t_env    *tmp;
//
//	if (!head || !(*head) || !new_lst)
//		return ;
//	tmp = (*head);
//	if (tmp->prev)
//	{
//		tmp->prev->next = new_lst;
//		new_lst->prev = tmp->prev;
//	}
//	while (new_lst->next)
//		new_lst = new_lst->next;
//	if (tmp->next)
//	{
//		new_lst->next = tmp->next;
//		tmp->next->prev = new_lst;
//	}
//	(*head) = new_lst;
//	free(tmp->tok_val);
//	free(tmp);
//}

void	del_env_node(t_env *node) // this func is still unused in the project hh
{
	t_env	*nxt;
	t_env	*prv;

	if (node == NULL)
		return ;
	nxt = node->next;
	prv = node->prev;
	if (node->prev)
		node->prev->next = nxt;
	if (node->next)
		node->next->prev = prv;
	free(node->key);
	free(node->val);
}
