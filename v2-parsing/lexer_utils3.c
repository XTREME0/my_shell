#include "parser.h"

int	treat_strs(t_tokens **toks)
{
	t_tokens	*token;

	while ((*toks))
	{
		if (is_expan((*toks)->tok_val) && ((*toks)->tok_type != DELIM
			|| (*toks)->tok_type != FILES))
		{
			rm_q_n_expand(); // expand and remove Quotes
		}
		else
		{
			if(!remove_quote(&(*toks)->tok_val))
				return (0);
		}
		(*toks) = (*toks)->next;
	}
	return (1);
}
