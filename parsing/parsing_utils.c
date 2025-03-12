#include "../minishell.h"

int	create_nodes(t_tokens *toks, t_cmd	**cmds)
{
	int		i;
	t_cmd	*cmd;

	i = 0;
	while (toks)
	{
		if (toks->tok_type == CMD)
		{
			cmd = ft_newcmd();
			if (!cmd)
				return (0);
			ft_addcmd(cmds, cmd);
		}
		toks = toks->next;
	}
	return (1);
}

int	set_redirs(t_tokens *toks, t_cmd **cmds)
{
	while (toks)
	{
		if (toks->tok_type == REDIR_IN)
			open_in(toks->next->tok_val, cmds);
		if (toks->tok_type == REDIR_OUT)
			open_out(toks->next->tok_val, cmds);
		if (toks->tok_type == HEREDOC)
			open_heredoc(toks->next->tok_val, cmds);
		if (toks->tok_type == PIPE)
			set_pipe(cmds);
		if (toks->tok_type == APPEND)
			open_append(toks->next->tok_val, cmds);
		if (toks->tok_type == HEREDOC)
		{
			if (!open_heredoc(toks->next->tok_val, cmds))
				return (0);
		}
		toks = toks->next;
	}
	(*cmds) = ft_firstcmd((*cmds));
	return (1);
}

int	redir_next(char	*str)
{
	if (!ft_strcmp(str, ">"))
		return (1);
	if (!ft_strcmp(str, ">>"))
		return (1);
	if (!ft_strcmp(str, "|"))
		return (1);
	return (0);
}

int	join_args(t_tokens *toks, t_cmd *cmd, int words)
{
	char		**args;
	int			i;
	t_tokens	*tmp;

	args = malloc(sizeof(char *) * (words + 1));
	if (!args)
		return (0);
	while (tmp && tmp->tok_type != CMD)
		tmp = tmp->next;
	args[0] = ft_strdup(tmp->tok_val);
	if (!args[0])
		return (free_table(args), 0);
	i = 1;
	while (i < words)
	{
		if (toks->tok_type == WORD)
		{
			args[i] = ft_strdup(tmp->tok_val);
			if (!args[i])
				return (free_table(args), 0);
		}
		toks = toks->next;
	}
	return (1);
}

int	set_args(t_tokens *toks, t_cmd *cmds)
{
	t_tokens	*tmp;
	int			words;

	tmp = toks;
	words = 0;
	while (toks)
	{
		if (toks->tok_type == CMD || toks->tok_type == WORD)
			words++;
		if (redir_next(toks->tok_val) || !toks->next)
		{
			if (!join_args(tmp, cmds, words))
				return (0);
			tmp = toks->next;
			cmds = cmds->next;
			words = 0;
		}
		toks = toks->next;
	}
	return (1);
}
