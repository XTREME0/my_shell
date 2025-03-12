#include "../minishell.h"

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
