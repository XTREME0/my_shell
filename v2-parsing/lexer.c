#include "parser.h"

t_tokens	*tokenize(char *str)
{
	t_tokens	*toks;

	toks = input_split(str);
	if (!toks)
		return (NULL);
	assign_redirs(toks);
	assign_files(toks);
	assign_expans(toks);
	assign_cmds(toks);
	// if (!remove_quote(toks))
	// 	return (ft_cleartoks(&toks), NULL);
	assign_words(toks);
	// replace_export(toks);
	// if (!expand(toks))
	// 	return (ft_cleartoks(&toks), NULL);
	assign_cmds(toks);
	assign_words(toks);
	return (toks);
}

// expand and remove quotes at the same time
// if there is no expan, remove quotes
// if expan is not in quotes, expand and split to new token
// else, just expand in double quotes