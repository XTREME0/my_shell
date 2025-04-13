#include "parser.h"

int	treat_strs(t_tokens **toks)
{
	t_tokens	*token;

	while ((*toks))
	{
		if ((*toks)->tok_val && is_expan((*toks)->tok_val)
			&& ((*toks)->tok_type != DELIM || (*toks)->tok_type != FILES))
		{
			rm_q_n_expand(); // expand and remove Quotes
		}
		(*toks) = (*toks)->next;
	}
	return (1);
}
