#include "../minishell.h"

t_stb	*stb_new(char *str)
{
	t_stb	*new;

	new = malloc(sizeof(t_stb));
	if (!new)
		return (NULL);
	new->str = str;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	stb_addfront(t_stb **head, t_stb *new)
{
	t_stb	*tmp;

	if (!head)
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
	new->prev = tmp;
}

void	stb_addback(t_stb **head, t_stb *new)
{
	t_stb	*tmp;

	if (!head)
		return ;
	if (!(*head))
	{
		(*head) = new;
		return ;
	}
	tmp = (*head);
	while (tmp->prev)
		tmp = tmp->prev;
	tmp->prev = new;
	new->next = tmp;
	(*head) = new;
}

void	stb_clear(t_stb **head)
{
	t_stb	*tmp;

	if (!head)
		return ;
	while ((*head))
	{
		tmp = (*head);
		(*head) = (*head)->next;
		free(tmp->str);
		free(tmp);
	}
}
