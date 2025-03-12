#include "../minishell.h"

t_tokens	*ft_newtoken(char *str)
{
	t_tokens	*new;

	new = malloc(sizeof(t_tokens));
	if (!new)
		return (NULL);
	new->tok_val = str;
	new->tok_type = 0;
	new->next = NULL;
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
	}
	return ;
}

t_tokens	*ft_lasttoken(t_tokens *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

int	join_inps(t_tokens **toks_head, t_inp **inp_head)
{
	char		*str;
	char		*tmp;
	t_tokens	*tok;
	t_inp		*inp;

	if (!toks_head || !inp_head)
		return (0);
	inp = (*inp_head);
	tmp = NULL;
	while (inp)
	{
		str = ft_strjoin(tmp, inp->str);
		if (!str)
			return (0);
		free(tmp);
		tmp = str;
	}
	free(tmp);
	tok = ft_newtoken(str);
	if (!tok)
		return (0);
	ft_token_add(toks_head, tok);
	return (1);
}
