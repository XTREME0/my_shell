#include "../minishell.h"

t_cmd	*construct_cmds(char *str, t_env **env)
{
	t_cmd		*cmds;
	t_tokens	*toks;

	toks = tokenize(str, env);
	if (!toks)
		return (NULL);
	cmds = NULL;
	if (!create_nodes(toks, &cmds))
		return (ft_cleartoks(&toks), NULL);
	if (!set_redirs(toks, &cmds))
		return (ft_cleartoks(&toks), NULL);
	if (!set_args(toks, cmds))
		return (ft_cleartoks(&toks), NULL);
	ft_cleartoks(&toks);
	return (cmds);
}
