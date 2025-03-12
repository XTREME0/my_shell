#include "../minishell.h"

t_inp	*ft_newinp(char *str)
{
	t_inp	*new;

	new = malloc(sizeof(t_inp));
	if (!new)
		return (NULL);
	new->str = str;
	new->exp_split = 0;
	new->exported = 0;
	new->next = NULL;
	return (new);
}

void	ft_addinp(t_inp **head, t_inp *new)
{
	t_inp	*tmp;

	if (head)
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
	}
	return ;
}

int	append_inp(t_inp **head, char *str, int exp_split)
{
	t_inp	*node;

	node = ft_newinp(str);
	if (!node)
		return (0);
	if (exp_split)
		node->exp_split = 1;
	ft_addinp(head, node);
	return (1);
}

void	ft_clearinp(t_inp **head)
{
	t_inp	*tmp;

	if (!head || !(*head))
		return ;
	while ((*head))
	{
		tmp = (*head);
		(*head) = (*head)->next;
		free(tmp->str);
		free(tmp);
	}
	(*head) = NULL;
}
