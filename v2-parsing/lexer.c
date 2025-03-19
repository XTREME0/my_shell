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
