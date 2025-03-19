#include "parser.h"

t_cmd	*construct_cmds(char *str)
{
	t_tokens	*toks;
	t_tokens	*cmds;

	toks = tokenize(str);
	if (!toks)
		return (NULL);
	if (!create_nodes(toks))
		return (ft_cleartoks(&toks), NULL);
	if (!set_args(cmds, toks))
		return (ft_cleartoks(&toks), NULL);
}
