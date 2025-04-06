#include "parser.h"

void	set_pipe(t_cmd **cmd)
{
	(*cmd)->fd_out = -1;
	if (!(*cmd)->next)
		(*cmd)->next->fd_in = -1;
	(*cmd) = (*cmd)->next;
}

int	open_any(t_redirs *redir, t_cmd *cmd, t_redirs *in, t_redirs *out)
{
	int	fd;

	fd = open(redir->filename, redir->perm, 0644);
	if (fd < 0)
		printf(FD_ERR, redir->filename, strerror(errno));
	if (redir->io)
	{
		cmd->fd_in = fd;
		in = redir;
	}
	else
	{
		cmd->fd_out = fd;
		out = redir;
	}
	if (redir->delim)
		cmd->heredoc_file = redir->filename;
	else
		cmd->heredoc_file = NULL;
	if (fd < 0 && redir->io)
		return (0);
	return (1);
}
