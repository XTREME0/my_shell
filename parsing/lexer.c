#include "../minishell.h"

void	assign_redirs(t_tokens *toks)
{
	while (toks)
	{
		if (ft_strcmp(toks->tok_val, ">"))
			toks->tok_type = REDIR_OUT;
		else if (ft_strcmp(toks->tok_val, ">>"))
			toks->tok_type = APPEND;
		if (ft_strcmp(toks->tok_val, "<"))
			toks->tok_type = REDIR_IN;
		else if (ft_strcmp(toks->tok_val, "<<"))
			toks->tok_type = HEREDOC;
		else if (ft_strcmp(toks->tok_val, "|"))
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

t_tokens	*tokenize(char *str, t_env **env)
{
	t_tokens *toks;

	if (!filter_line(str, env, &toks))
		return (NULL);
	assign_redirs(toks);
	assign_files(toks);
	assign_cmds(toks);
	assign_words(toks);
	return (toks);
}

// get string (chunk) splitted; assmue delimited by quotes
// stop at space outside the quotes
// join all the strings in the t_inp
// put the final string in a lex list to be lexed later
// after having the list, where each node has command + its arguments + redirections
// send to exec

/* 

to think about:
	use a switch_flag, if a single quote is there, copy everything

*/


/*
		TODO !!!!!!

if an expansion is outside quotes, split it,
put each string as a token and join the last element with the next inp node

*/