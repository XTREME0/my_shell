# include "parser.h"

int	has_quotes(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			return (1);
		i++;
	}
	return (0);
}

int	is_expan(char *val)
{
	size_t	i;

	i = 0;
	while (val[i])
	{
		if (val[i] == '$')
			return (1);
		i++;
	}
	return (0);
}
