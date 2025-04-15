/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:36:37 by ariyad            #+#    #+#             */
/*   Updated: 2025/04/15 19:33:29 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	set_pipe(t_cmd **cmd)
{
	(*cmd)->fd_out = -1;
	if (!(*cmd)->next)
		(*cmd)->next->fd_in = -1;
	(*cmd) = (*cmd)->next;
}

int	open_check(t_redirs *redir, int perm)
{
	redir->fd = open(redir->filename, perm, 0644);
	if (redir->fd == -1)
	{
		fd_printf(2, FD_ERR, redir->filename, strerror(errno));
		return (0);
	}
	return (1);
}

// int	file_expand(t_tokens **token, char **str, t_env *env)
// {
// 	t_stb	*builder;
// 	t_tokens	*lst;
// 	char	*new;
// 	size_t	i;
// 	size_t	j;
// 	int		in_quote;

// 	if (!is_expan(*str))
// 		return (remove_quote(str), 1);
// 	i = 0;
// 	j = 0;
// 	builder = NULL;
// 	while (str[0][j])
// 	{
// 		if (is_quote(str[0][j]))
// 		{
// 			in_quote = 1;
// 			chunkate(&builder, i, j, *str);
// 			i = j + 1;
// 		}
// 		if (str[0][j] == '$' && in_quote)
// 			reg_expand(str, env, 0);
// 		if (str[0][j] == '$' && !in_quote)
// 		{
// 			lst = split_expan(token, str, env);
// 		}
// 		j++;
// 	}
// 	chunkate(&builder, i, j, *str);
// }
