#include "parser.h"

static int	count_args(t_tokens *toks)
{
	int	i;

	i = 0;
	while (toks && toks->tok_type != PIPE)
	{
		if (toks->tok_type == CMD
			|| toks->tok_type == WORD)
			i++;
		toks = toks->next;
	}
	return (i);
}	

static int	copy_args(t_tokens *toks, char **arr)
{
	t_tokens	*tmp;
	int			pos;

	tmp = toks;
	while (tmp && tmp->tok_type != CMD && tmp->tok_type != PIPE)
		tmp = tmp->next;
	if (!tmp || tmp->tok_type == PIPE)
		return (free_table(arr), 1);
	arr[0] = ft_strdup(tmp->tok_val);
	if (!arr[0])
		return (free_table(arr), 0);
	pos = 1;
	while (toks && toks->tok_type != PIPE)
	{
		if (toks->tok_type == WORD)
		{
			arr[pos++] = ft_strdup(toks->tok_val);
			if (!arr[pos - 1])
				return (free_table(arr), 0);
		}
		toks = toks->next;
	}
	arr[pos] = NULL;
	return (1);
}

static int	join_args(t_cmd *cmd, t_tokens *toks)
{
	char	**args;

	args = malloc((count_args(toks) + 1) * sizeof(char *));
	if (!args)
		return (0);
	if (!copy_args(toks, args))
		return (0);
	cmd->kwargs = args;
	return (1);
}

int	set_args(t_cmd *cmds, t_tokens *toks)
{
	t_cmd	*head;

	head = cmds;
	while (cmds)
	{
		if (!join_args(cmds, toks))
			return (ft_clearcmds(&head), 0);
		while (toks && toks->tok_type != PIPE)
			toks = toks->next;
		if (toks)
			toks = toks->next;
		cmds = cmds->next;
	}
	return (1);
}
