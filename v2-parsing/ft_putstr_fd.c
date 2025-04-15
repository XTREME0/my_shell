#include "parser.h"

void	ft_pustr_fd(int fd, const char *s)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(fd, s[i]);
		i++;
	}
	return ;
}
