#include "parser.h"

void	redir_pipe(t_cmd *cmds)
{
	while (cmds)
	{
		if (cmds->fd_out == 1 && cmds->next)
			cmds->fd_out = -1;
		if (cmds->prev && cmds->fd_in == 0)
			cmds->fd_in = -1;
		cmds = cmds->next;
	}
}

static void	which_perm(t_tokens *toks, t_redirs *redir)
{
	t_redirs	*last;

	if (!toks)
		return ;
	last = ft_lastredir(redir);
	if (!last)
		return ;	
	if (toks->tok_type == HEREDOC || toks->tok_type == REDIR_IN)
		redir->io = 1;
	if (toks->tok_type == REDIR_OUT)
		redir->perm = O_RDWR | O_CREAT;
	if (toks->tok_type == APPEND)
		redir->perm = O_RDWR | O_CREAT | O_APPEND;
}

static int	get_io(t_tokens **head, t_redirs **redirs)
{
	t_tokens	*toks;

	toks = (*head);
	while (toks && toks->tok_type != PIPE)
	{
		if (toks->tok_type == DELIM || toks->tok_type == FILES)
		{
			if (!create_redir(toks, redirs))
				return (0);
			which_perm(toks->prev, (*redirs));
		}
		toks = toks->next;
	}
	if (toks)
		toks = toks->next;
	return (1);
}

int	open_redirs(t_cmd *cmd, t_tokens *toks)
{
	t_tokens	*head;
	t_redirs	*redirs;

	if (!cmd || !toks)
		return (0);
	head = toks;
	redirs = NULL;
	while (cmd)
	{
		if (!get_io(&toks, &redirs) || !create_heredocs(redirs))
			return (toks = head, 0);
		open_files(redirs, cmd); // complete this. open files and quite if infile is invalid
		cmd = cmd->next;
	}
	// open io files
	// ft_clearredir(&redirs);
	return (toks = head, 1);
}
