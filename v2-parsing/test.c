#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct s_stb
{
	char			*str;
	struct s_stb	*next;
	struct s_stb	*prev;
}	t_stb;

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


void	skip_expand(char *str, size_t *i)
{
	while (str[*i] && !ft_isspace(str[*i]) && !is_redir(str[*i])
		&& !is_quote(str[*i]) && str[*i] != '.')
		*i += 1;
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	l;
	char	*str;

	if (s == NULL)
		return (NULL);
	l = strlen(s);
	if (l <= start)
		return (NULL);
	i = 0;
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (s[i + start] && i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize <= 0)
		return (strlen(src));
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (strlen(src));
}


char	*ft_strdup(const char *s1)
{
	char	*ptr;

	ptr = (char *)malloc((strlen(s1) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strcpy(ptr, s1);
	return (ptr);
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
	l1 = strlen(s1);
	l2 = strlen(s2);
	ptr = (char *)malloc(l1 + l2 + 1);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1, l1 + 1);
	ft_strlcpy(ptr + l1, s2, l2 + 1);
	return (ptr);
}

t_stb	*stb_new(char *str)
{
	t_stb	*new;

	new = malloc(sizeof(t_stb));
	if (!new)
		return (NULL);
	new->str = str;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	stb_addfront(t_stb **head, t_stb *new)
{
	t_stb	*tmp;

	if (!head)
		return ;
	if (!(*head))
	{
		(*head) = new;
		return ;
	}
	tmp = (*head);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

void	stb_addback(t_stb **head, t_stb *new)
{
	t_stb	*tmp;

	if (!head)
		return ;
	if (!(*head))
	{
		(*head) = new;
		return ;
	}
	tmp = (*head);
	while (tmp->prev)
		tmp = tmp->prev;
	tmp->prev = new;
	new->next = tmp;
	(*head) = new;
}

void	stb_clear(t_stb **head)
{
	t_stb	*tmp;

	if (!head)
		return ;
	while ((*head))
	{
		tmp = (*head);
		(*head) = (*head)->next;
		free(tmp->str);
		free(tmp);
	}
}

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
	last = ft_substr(*s, end + 1, strlen(&(*s)[end + 1]));
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

char	*reg_expand(char *str, int tf)
{
	char	*new;
	size_t	i;
	size_t	j;
	char	*val;

	if (!tf || !is_expan(str))
		return (ft_strdup(str));
	i = 0;
	new = NULL;
	while (str[i])
	{
		j = i;
		if (str[i] == '$')
		{
			skip_expand(str, &j);
			val = ft_substr(str, i, j - i);
			if (!val)
				return (NULL);
			replace(&str, i, j - 1, strdup("userhh"));
			i = j - 1;
		}
		i++;
	}
	return (new);
}

int main()
{
    char *str = ft_strdup("hello$USER");
    char *new = reg_expand(str, 1);
    printf("%s\n", new);

    return 0;
}
