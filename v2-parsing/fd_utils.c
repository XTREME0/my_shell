#include "parser.h"

void	set_pipe(t_cmd **cmd)
{
	(*cmd)->fd_out = -1;
	if (!(*cmd)->next)
		(*cmd)->next->fd_in = -1;
	(*cmd) = (*cmd)->next;
}
