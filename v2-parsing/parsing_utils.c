#include "parser.h"

t_cmd	*create_nodes(t_tokens *toks)
{
	t_cmd	*cmds;
	t_cmd	*new;

	cmds = NULL;
	while (toks)
	{
		if (toks->tok_type == PIPE)
		{
			new = ft_newcmd();
			if (!new)
				return (ft_clearcmds(&cmds), NULL);
			ft_addcmd(&cmds, new);
		}
		toks = toks->next;
	}
	new = ft_newcmd();
	if (!new)
		return (ft_clearcmds(&cmds), NULL);
	ft_addcmd(&cmds, new);
	return (cmds);
}
