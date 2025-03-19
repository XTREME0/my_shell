#include "parser.h"

void	free_table(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	*custom_join(char *s1, char *s2)
{
	char	*ptr;
	size_t	l1;
	size_t	l2;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (!s2)
		return (ft_strdup(s1));
	if (!s1)
		return (ft_strdup(s2));
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	ptr = (char *)malloc(l1 + l2 + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[0] = '\0';
	ft_strlcat(ptr, s1, l1 + 1);
	ft_strlcat(ptr, s2, l1 + l2 + 1);
	return (ptr);
}

int	ft_isspace(char c)
{
	return (c == '\r' || c == '\v' || c == '\f' || c == '\t'
		|| c == '\n' || c == ' ');
}

int	is_quote(char c)
{
	return (c == '\'' || c == '\"');
}

int	is_redir(char c)
{
	return (c == '>' || c == '<' || c == '|');
}
