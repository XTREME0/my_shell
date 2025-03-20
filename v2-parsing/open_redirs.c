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
