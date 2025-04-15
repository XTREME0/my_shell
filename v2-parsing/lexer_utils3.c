#include "parser.h"

t_tokens	*split_expan(t_tokens **tok, char **str, t_env *env)
{
	char		*exp;
	t_tokens	*new;
	size_t		i;
	size_t		j;

	if (!tok || !(*tok) || !str || !(*str))
		return (0);
	if (str[0][0] == '$' && (str[0][1] == '.' || !str[0][1]))
		return (input_split("$"));
	i = 0;
	while (str[0][i])
	{
		j = 0;
		if (str[0][i] == '$')
		{
			while (str[0][j] && str[0][j] != '.')
				j++;
			exp = ft_substr(*str, i, i - j);
			break ;
		}
		i++;
	}
	return (input_split(env_val(env, exp)));
}

void	expan_tailor(t_tokens **tok, t_tokens *new_lst)
{
	t_tokens	*tmp;

	if (!tok || !(*tok) || !new_lst || !new_lst->next)
		return ;
	tmp = new_lst->next;
	assign_words(new_lst);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*tok)->next;
	(*tok)->next->prev = tmp;
	(*tok)->next = new_lst->next;
	new_lst->next->prev = (*tok);
}

// int	rm_q_n_expand(t_tokens *tok, t_env *env)
// {
// 	t_stb	*builder;


// }

/*
plan is build strings without quotes, with reg expanding and split expanding
*/

// int	treat_strs(t_tokens **toks, t_env *env)
// {
// 	t_tokens	*head;

// 	head = (*toks);
// 	while ((*toks))
// 	{
// 		if ((*toks)->tok_val && ((*toks)->tok_type != DELIM
// 			|| (*toks)->tok_type != FILES))
// 		{
// 			rm_q_n_expand((*toks), env); // expand and remove Quotes
// 		}
// 		(*toks) = (*toks)->next;
// 	}
// 	(*toks) = head;
// 	return (1);
// }
