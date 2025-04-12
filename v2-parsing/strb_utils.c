#include "parser.h"

char	*stb_merge(t_stb *build)
{
	char	*new;
	char	*tmp;

	if (!build)
		return (NULL);
	new = NULL;
	while (build)
	{
		tmp = new;
		new = custom_join(tmp, build->str);
		if (!new)
			return (free(tmp), new);
		free(tmp);
		build = build->next;
	}
	return (new);
}

void	replace(char **s, size_t start, size_t end, char *replace)
{
	t_stb	*build;
	char	*base;
	char	*last;
	char	*str;
	t_stb	*new;

	if (!s || !(*s))
		return ;
	base = ft_substr(*s, 0, start);
	last = ft_substr(*s, end + 1, ft_strlen(&(*s)[end + 1]));
	build = stb_new(base);
	if (!build)
		return (free(base), free(last));
	new = stb_new(replace);
	if (!new)
		return (free(base), free(last));
	stb_addfront(&build, new);
	new = stb_new(last);
	if (!new)
		return (free(base), free(last));
	stb_addfront(&build, new);
	free(*s);
	*s = stb_merge(build);
	stb_clear(&build);
}
