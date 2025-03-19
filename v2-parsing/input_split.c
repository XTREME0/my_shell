# include "parser.h"

t_tokens	*input_split(char *str)
{
	size_t		i;
	t_tokens	*toks;

	if (!str)
		return (NULL);
	i = 0;
	toks = NULL;
	while (str[i])
	{
		skip_spaces(str, &i);
		if(!get_word(str, &i, &toks))
			return (ft_cleartoks(&toks), NULL);
		skip_spaces(str, &i);
		if(!get_redir(str, &i, &toks))
			return (ft_cleartoks(&toks), NULL);
	}
	return (toks);
}
