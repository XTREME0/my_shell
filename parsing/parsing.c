#include "../minishell.h"

//t_cmd	*construct_cmds(char *str, t_env **env)
//{
//	t_cmd		*cmds;
//	t_tokens	*toks;
//
//	toks = tokenize(str, env);
//	if (!toks)
//		return (NULL);
//	cmds = NULL;
//	if (!create_nodes(toks, &cmds))
//		return (ft_cleartoks(&toks), NULL);
//	if (!set_redirs(toks, &cmds))
//		return (ft_cleartoks(&toks), NULL);
//	if (!set_args(toks, cmds))
//		return (ft_cleartoks(&toks), NULL);
//	ft_cleartoks(&toks);
//	return (cmds);
//}

t_cmd    *construct_cmds(char *str, t_env **env)
{
    t_cmd    *cmds;
    char    **split_cmds;
    int        i;

    if (str == NULL || env == NULL || *env == NULL)
	    return (NULL);
    cmds = NULL;
    split_cmds = ft_split(str, '|');
    if (split_cmds == NULL)
	    return (NULL);
    i = 0;
    while (split_cmds[i])
    {
        ft_addcmd(&cmds, ft_newcmd()); // risky, check for failure
	if (cmds == NULL)
		return (NULL); // not freeing for now
        i++;
    }
    i = 0;
    while (split_cmds[i])
    {
        cmds->kwargs = ft_split(split_cmds[i], ' ');
	if (cmds->kwargs == NULL)
		return (NULL);
        if (split_cmds[i + 1])
        {
            cmds->fd_out = -1;
            cmds->next->fd_in = -1;
            cmds = cmds->next;
        }
        i++;
    }
    free_table(split_cmds);
    while (cmds->prev)
        cmds = cmds->prev;
    return (cmds);
}
