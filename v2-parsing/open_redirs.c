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

int	get_redir(t_cmd *cmd, t_tokens **head)
{
	t_tokens	*toks;
	t_redirs	*redirs;

	toks = (*head);
	while (toks && toks->tok_type != PIPE)
	{
		if (toks->tok_type == DELIM || toks->tok_type == FILES)
		{
			if (!create_redir(toks, redirs))
				return (0);
		}
		toks = toks->next;
	}
}

int	open_redirs(t_cmd *cmd, t_tokens *toks)
{
	t_tokens	*head;
	t_redirs	*redirs;

	if (!cmd || !toks)
		return (0);
	head = toks;
	while (cmd)
	{
		if (!get_redir(cmd, &toks))
		{
			toks = head;
			return (0);
		}		
		cmd = cmd->next;
	}
	toks = head;
	return (1);
}
