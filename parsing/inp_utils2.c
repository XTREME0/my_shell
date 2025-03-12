#include "../minishell.h"

static int	s_q_content(char *str, size_t *i, t_inp **head)
{
	char	*chunk;
	int		start;

	*i += 1;
	start = *i;
	while (str[*i] && str[*i] != '\'')
		*i += 1;
	chunk = ft_substr(str, start, *i - start);
	if (!chunk)
		return (0);
	*i += 1;
	return (append_inp(head, chunk, 0));
}

static int	d_q_content(char *str, size_t *i, t_inp **head, t_env *env)
{
	char	*chunk;
	int		start;

	*i += 1;
	start = *i;
	while (str[*i] && str[*i] != '\"')
	{
		if (str[*i] == '$')
		{
			chunk = ft_substr(str, start, *i - start);
			if (!chunk || !get_expans(str, i, head, env)
				|| !append_inp(head, chunk, 0))
				return (0);
			start = *i;
		}
		*i += 1;
	}
	chunk = ft_substr(str, start, *i - start + 1);
	if (!chunk)
		return (0);
	*i += 1;
	return (append_inp(head, chunk, 0));
}

int	get_q_content(char *str, size_t *i, t_inp **head, t_env *env)
{
	if (str[*i] == '\"')
	{
		if (!d_q_content(str, i, head, env))
			return (0);
	}
	else
	{
		if (!s_q_content(str, i, head))
			return (0);
	}
	return (1);
}
