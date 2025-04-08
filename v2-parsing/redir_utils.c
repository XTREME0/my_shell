#include "parser.h"

int	create_redir(t_tokens *toks, t_redirs **redirs)
{
	t_redirs	*new_redir;
	char		*name;

	new_redir = ft_newredir();
	if (!new_redir)
		return (0);
	if (toks->tok_type == FILES)
	{
		name = ft_strdup(toks->tok_val);
		if (!name)
			return (free(new_redir), 0);
	}
	else
	{
		name = ft_mkhtmp();
		if (!name)
			return (free(new_redir), 0);
		new_redir->delim = ft_strdup(toks->tok_val);
		if (!new_redir->delim)
			return (free(new_redir), free(name), 0);
	}
	new_redir->filename = name;
	ft_addredir(redirs, new_redir);
	return (1);
}

int	create_heredocs(t_redirs *redirs)
{
	while (redirs)
	{
		if (redirs->delim)
		{
			if (!read_heredoc(redirs))
				return (0);
		}
		redirs = redirs->next;
	}
	return (1);
}

void	open_files(t_redirs *redirs, t_cmd *cmd)
{
	t_redirs	*head;
	t_redirs	*in;
	t_redirs	*out;

	if (!redirs)
		return ;
	in = NULL;
	out = NULL;
	head = redirs;
	while (redirs->next)
	{
		if (!open_any(redirs, cmd, in, out))
			break ;
		redirs = redirs->next;
	}
	clear_n_keep_redir(&head, in, out);
}

// find a way to keep the node with fd_out and node with fd_in
// their FDs must be kept open and kept 