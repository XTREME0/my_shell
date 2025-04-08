/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:37:07 by ariyad            #+#    #+#             */
/*   Updated: 2025/04/08 15:37:08 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	free_table(char **strs)
{
	size_t	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i] != NULL)
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
	ft_strlcpy(ptr, s1, l1 + 1);
	ft_strlcpy(ptr + l1, s2, l2 + 1);
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
