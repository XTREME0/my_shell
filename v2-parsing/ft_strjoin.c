#include "parser.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	l1;
	size_t	l2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	ptr = (char *)malloc(l1 + l2 + 1);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1, l1 + 1);
	ft_strlcpy(ptr + l1, s2, l2 + 1);
	return (ptr);
}
