#include "parser.h"

t_redirs	*ft_newredir(char *filename)
{
	t_redirs	*new;

	new = malloc(sizeof(t_redirs));
	if (!new)
		return (NULL);
	new->fd = -1;
	new->delim = NULL;
	new->filename = filename;
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
	while (!(*head))
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

void	clear_n_keep_redir(t_redirs **head, t_redirs *keep)
{
	t_redirs	*tmp;

	if (!head)
		return ;
	while (!(*head))
	{
		tmp = (*head);
		if (tmp == keep)
			continue ;
		(*head) = (*head)->next;
		if (tmp->delim)
			unlink(tmp->filename);
		free(tmp->delim);
		free(tmp->filename);
		close(tmp->fd);
		free(tmp);
	}
	free(keep->delim);
	free(keep);
}

t_redirs	*ft_lastredir(t_redirs	*head)
{
	if (!head)
		return (NULL);
	while (head->next)
	{
		head = head->next;
	}
	return (head);
}
