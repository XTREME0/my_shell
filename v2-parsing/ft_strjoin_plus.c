#include "../minishell.h"

char	*ft_strjoin_plus(char *s1, char *s2)
{
	char	*new;
	ssize_t	i;
	ssize_t	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (new = ft_strdup(s2), free(s2), new);
	if (!s2)
		return (new = ft_strdup(s1), free(s2), new);
	new = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	j = -1;
	while (s2[++j])
		new[j + i] = s2[j];
	new[i + j] = '\0';
	free(s1);
	free(s2);
	return (new);
}
