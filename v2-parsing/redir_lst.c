/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:37:55 by ariyad            #+#    #+#             */
/*   Updated: 2025/04/09 17:32:07 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_redirs	*ft_newredir(void)
{
	t_redirs	*new;

	new = malloc(sizeof(t_redirs));
	if (!new)
		return (NULL);
	new->fd = -1;
	new->perm = O_RDWR;
	new->io = 0;
	new->delim = NULL;
	new->filename = NULL;
	new->next = NULL;
	return (new);
}

void	ft_addredir(t_redirs **head, t_redirs *new)
{
	t_redirs	*tmp;

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

void	ft_clearredir(t_redirs **head)
{
	t_redirs	*tmp;

	if (!head)
		return ;
	while ((*head))
	{
		tmp = (*head);
		(*head) = (*head)->next;
		if (tmp->delim)
			unlink(tmp->filename);
		free(tmp->delim);
		free(tmp->filename);
		close(tmp->fd);
		free(tmp);
	}
}

void	clear_n_keep_redir(t_redirs **head, t_redirs *in, t_redirs *out)
{
	t_redirs	*tmp;

	if (!head)
		return ;
	while ((*head))
	{
		tmp = (*head);
		(*head) = (*head)->next;
		if (tmp == in || tmp == out)
			continue ;
		if (tmp->delim)
			unlink(tmp->filename);
		free(tmp->delim);
		free(tmp->filename);
		if (tmp->fd > 2)
			close(tmp->fd);
		free(tmp);
	}
	if (out)
		free(out->delim);
	if (in)
		free(in->delim);
	free(out);
	free(in);
	//leak when infile does not exist
}

t_redirs	*ft_lastredir(t_redirs	**head)
{
	t_redirs	*last;

	if (!head || !(*head))
		return (NULL);
	last = (*head);
	while (last->next)
		last = last->next;
	return (last);
}
