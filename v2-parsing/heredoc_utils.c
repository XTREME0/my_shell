/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:38:44 by ariyad            #+#    #+#             */
/*   Updated: 2025/04/13 17:55:21 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*ft_mkhtmp(void)
{
	char	*def;
	char	*random;
	char	*filename;

	def = "/tmp/heredoc_tmp_";
	random = ft_utoa((size_t) & random);
	if (!random)
		return (NULL);
	filename = custom_join(def, random);
	if (!filename)
		return (free(random), NULL);
	free(random);
	return (filename);
}

static int	hereline(t_redirs *redirs, t_env *env, int tf)
{
	char	*line;
	
	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			printf(HD_EOF, redirs->delim);
			break ;
		}
		if (ft_strcmp(line, redirs->delim) == 0)
			break ;
		reg_expand(&line, env, tf);
		fd_printf(redirs->fd, "%s\n", line);
		free(line);
	}
	free(line);
	return (1);
}

int	read_heredoc(t_redirs *redirs, t_env *env)
{
	int	tf;

	tf = has_quotes(redirs->delim);
	if (!remove_quote(&redirs->delim))
		return (0);
	if (!open_check(redirs, O_CREAT | O_RDWR))
		return (0);
	hereline(redirs, env, tf);
	return (close(redirs->fd), 1);
}
