#include "parser.h"

t_tokens	*tokenize(char *str)
{
	t_tokens	*toks;

	toks = input_split(str);
	if (!toks)
		return (NULL);
	assign_redirs(toks);
	assign_files(toks);
	assign_cmds(toks);
	assign_words(toks);
	return (toks);
}

// int main(int ac, char **av, char **env)
// {
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
// }
