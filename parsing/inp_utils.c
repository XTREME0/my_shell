#include "../minishell.h"

static int	get_chunk(char *str, size_t *i, t_inp **head)
{
	int		start;
	char	*chunk;
	t_inp	*node;

	start = *i;
	while (str[*i] && !ft_isspace(str[*i]) && !is_quote(str[*i])
		&& str[*i] != '$')
		*i += 1;
	chunk = ft_substr(str, start, *i - start);
	if (!chunk)
		return (0);
	return (append_inp(head, chunk, 0));
}

int	get_expans(char *str, size_t *i, t_inp **head, t_env *env)
{
	t_inp	*node;
	int		start;
	char	*key;
	char	*val;
	int		exp_split;

	exp_split = 0;
	if (*i != 0 && (str[*i - 1] == '\'' || str[*i - 1] == '\"'))
		exp_split = 1;
	*i += 1;
	start = *i;
	while (str[*i] && !ft_isspace(str[*i]) && !is_redir(&str[*i])
		&& !is_quote(str[*i]) )
		*i += 1;
	key = ft_substr(str, start, *i - start);
	if (!key)
		return (0);
	val = get_val(env, key);
	return (append_inp(head, val, exp_split));
}

static int	get_redir(char *str, size_t *i, t_inp **head)
{
	char	*chunk;
	int		len;

	if ((str[*i] == '>' || str[*i] == '>') && str[*i + 1] == str[*i])
	{
		chunk = ft_substr(str, *i, 2);
		*i += 2;
	}
	else
	{
		chunk = ft_substr(str, *i, 1);
		*i += 1;
	}
	if (!chunk)
		return (0);
	return (append_inp(head, chunk, 0));
}

static int	assemble(char *str, size_t *i, t_inp **head, t_env *env)
{
	while (str[*i] && !ft_isspace(str[*i]) && !is_redir(&str[*i]))
	{
		if (is_quote(str[*i]))
		{
			if (!get_q_content(str, i, head, env))
				return (0);
		}
		else if (str[*i] == '$')
		{
			if (!get_expans(str, i, head, env))
				return (0);
		}
		else if (is_redir(&str[*i]))
		{
			if (!get_redir(str, i, head))
				return (0);
		}
		else
		{
			if (!get_chunk(str, i, head))
				return (0);
		}
	}
	return (1);
}

int	filter_line(const char *str, t_env **env, t_tokens **toks)
{
	size_t		i;
	t_inp		*inp;
	char		*s;

	if (!str)
		return (0);
	i = 0;
	s = ft_strtrim(str, WHITE_SP);
	if (!s)
		return (0);
	while (s[i])
	{
		if (!assemble(s, &i, &inp, (*env)))
			return (ft_clearinp(&inp), 0);
		if (!join_inps(toks, &inp))
			return (ft_clearinp(&inp), 0);
	}
	return (1);
}
