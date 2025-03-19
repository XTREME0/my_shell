#include "parser.h"

void	assign_redirs(t_tokens *toks)
{
	while (toks)
	{
		if (!ft_strcmp(toks->tok_val, ">"))
			toks->tok_type = REDIR_OUT;
		else if (!ft_strcmp(toks->tok_val, ">>"))
			toks->tok_type = APPEND;
		if (!ft_strcmp(toks->tok_val, "<"))
			toks->tok_type = REDIR_IN;
		else if (!ft_strcmp(toks->tok_val, "<<"))
			toks->tok_type = HEREDOC;
		else if (!ft_strcmp(toks->tok_val, "|"))
			toks->tok_type = PIPE;
		toks = toks->next;
	}
}

void	assign_files(t_tokens *toks)
{
	while (toks)
	{
		if (toks->tok_type == REDIR_IN || toks->tok_type == REDIR_OUT
			|| toks->tok_type == APPEND)
		{
			if (toks->next)
				toks->next->tok_type = FILES;
		}
		toks = toks->next;
	}
}

void	assign_cmds(t_tokens *toks)
{
	int	sw;

	sw = 1;
	while (toks)
	{
		if (!toks->tok_type && sw)
		{
			sw = 0;
			toks->tok_type = CMD;
		}
		if (toks->tok_type == PIPE)
			sw = 1;
		toks = toks->next;
	}
}

void	assign_words(t_tokens *toks)
{
	int	delim;

	while (toks)
	{
		delim = 0;
		if (toks->tok_type == HEREDOC)
			delim = 0;
		if (!toks->tok_type && delim)
			toks->tok_type = DELIM;
		else if (!toks->tok_type)
			toks->tok_type = WORD;
		toks = toks->next;
	}
}

void	assign_expans(t_tokens *toks)
{}
