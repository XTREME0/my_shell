/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:00:37 by ataai             #+#    #+#             */
/*   Updated: 2024/11/01 18:35:30 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*p;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	node = NULL;
	while (lst != NULL)
	{
		p = ft_lstnew((*f)(lst->content));
		if (p == NULL)
		{
			ft_lstclear(&node, del);
			return (NULL);
		}
		ft_lstadd_back(&node, p);
		lst = lst->next;
	}
	return (node);
}
