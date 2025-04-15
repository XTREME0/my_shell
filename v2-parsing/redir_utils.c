/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:37:51 by ariyad            #+#    #+#             */
/*   Updated: 2025/04/15 14:49:58 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	open_any(t_redirs *redir, t_cmd *cmd, t_redirs **in, t_redirs **out)
{
	int	fd;

	if (!open_check(redir, redir->perm))
		fd = -2;
	if (redir->io)
	{
		cmd->fd_in = fd;
		(*in) = redir;
	}
	else
	{
		cmd->fd_out = fd;
		(*out) = redir;
	}
	if (redir->delim)
		cmd->heredoc_file = redir->filename;
	else
		cmd->heredoc_file = NULL;
	if (fd < 0 && redir->io)
		return (0);
	return (1);
}

int	create_redir(t_tokens *toks, t_redirs **redirs)
{
	t_redirs	*new_redir;
	char		*name;

	new_redir = ft_newredir();
	if (!new_redir)
		return (0);
	if (toks->tok_type == FILES)
	{
		name = ft_strdup(toks->tok_val);
		if (!name)
			return (free(new_redir), 0);
	}
	else
	{
		name = ft_mkhtmp();
		if (!name)
			return (free(new_redir), 0);
		new_redir->delim = ft_strdup(toks->tok_val);
		if (!new_redir->delim)
			return (free(new_redir), free(name), 0);
	}
	new_redir->filename = name;
	ft_addredir(redirs, new_redir);
	return (1);
}

int	create_heredocs(t_redirs *redirs, t_env *env)
{
	while (redirs)
	{
		if (redirs->delim)
		{
			if (!read_heredoc(redirs, env))
				return (0);
		}
		redirs = redirs->next;
	}
	return (1);
}

void	open_files(t_redirs *redirs, t_cmd *cmd)
{
	t_redirs	*head;
	t_redirs	*in;
	t_redirs	*out;

	if (!redirs)
		return ;
	in = NULL;
	out = NULL;
	head = redirs;
	while (redirs)
	{
		if (!open_any(redirs, cmd, &in, &out))
			break ;
		redirs = redirs->next;
	}
	clear_n_keep_redir(&head, in, out);
}

// find a way to keep the node with fd_out and node with fd_in
// their FDs must be kept open
