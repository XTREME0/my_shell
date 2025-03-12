#include "../minishell.h"

void	skip_white_sp(const char *str, size_t *i)
{
	while (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13))
		*i += 1;
}

int	is_quote(char c)
{
	return (c == '\'' || c == '\"');
}

int	ft_isspace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	is_redir(char *str)
{
	if (!ft_strncmp(str, ">>", 2))
		return (1);
	if (!ft_strncmp(str, ">", 1))
		return (1);
	// if (!ft_strncmp(str, "<<", 2))
	// 	return (0);
	// if (!ft_strncmp(str, "<", 1))
	// 	return (1);
	if (!ft_strncmp(str, "<", 1))
		return (1);
	if (!ft_strncmp(str, "|", 1))
		return (1);
	return (0);
}
