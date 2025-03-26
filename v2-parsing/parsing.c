#include "parser.h"

t_cmd	*construct_cmds(char *str)
{
	t_tokens	*toks;
	t_cmd		*cmds;

	toks = tokenize(str);
	if (!toks)
		return (NULL);
	// while (toks)
	// {
	// 	printf("%d\n", toks->tok_type);
	// 	toks = toks->next;
	// }
	// exit(0);
	cmds = create_nodes(toks);
	if (!cmds)
		return (ft_cleartoks(&toks), NULL);
	if (!set_args(cmds, toks))
		return (ft_cleartoks(&toks), NULL);
	redir_pipe(cmds);
	if (!open_redirs(cmds, toks))
		return (ft_cleartoks(&toks), NULL);
	return (ft_cleartoks(&toks), cmds);
}

int main(int ac, char **av, char **env)
{
// 	char *str = readline("$ ");
// 	t_tokens	*inp = input_split(str);
// 	char *str2 = readline("2$ ");
// 	t_tokens	*new = input_split(str2);
// 	ft_token_replace(&inp, new);
// 	ft_firsttok(&inp);
// 	t_tokens	*tmp = inp;
// 	while (inp)
// 	{
// 		printf("%s\n", inp->tok_val);
// 		inp = inp->next;
// 	}
// 	ft_cleartoks(&tmp);
// 	free(str);
// 	free(str2);

	char *str = readline("$ ");
	t_cmd	*cmds = construct_cmds(str);
	t_cmd	*head = cmds;
	// while (cmds)
	// {
	// 	for (int i = 0; cmds->kwargs[i]; i++)
	// 	{
	// 		printf("%s ", cmds->kwargs[i]);
	// 	}
	// 	// printf("%s ", cmds->kwargs[0]);
	// 	printf("\n");
	// 	cmds = cmds->next;
	// }
	ft_clearcmds(&head);
	free(str);
}
