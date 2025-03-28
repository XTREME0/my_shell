#include "../minishell.h"

t_cmd	*ft_newcmd(void)
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->kwargs = NULL;
	new->fd_in = 0;
	new->fd_out = 1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_addcmd(t_cmd **head, t_cmd *new)
{
	t_cmd	*tmp;

	if (!head || !new)
		return ;
	if (!(*head))
	{
		(*head) = new;
		return ;
	}
	tmp = (*head);
	while (tmp->next)
		tmp = tmp->next;
	new->prev = tmp;
	tmp->next = new;
}

void	ft_delcmd(t_cmd *cmd)
{
	size_t	i;

	if (cmd == NULL)
		return ;
	i = 0;
	if (cmd->fd_in > 0)
		close(cmd->fd_in);
	//if (cmd->fd_out > 0)
	//	close(cmd->fd_out);
	free_table(cmd->kwargs);
	//if (cmd->heredoc_file)
	//	free(cmd->heredoc_file);
	//if (cmd->delim)
	//	free(cmd->delim);
	free(cmd);
}

void	ft_clearcmds(t_cmd **head)
{
	t_cmd	*nxt;
	t_cmd	*tmp;
	
	if (head == NULL || *head == NULL)
		return ;
	tmp = *head;
	while (tmp)
	{
		nxt = tmp->next;
		ft_delcmd(tmp);
		tmp = nxt;
	}
}

t_cmd	*ft_firstcmd(t_cmd *cmd)
{
	while (cmd->prev)
		cmd = cmd->prev;
	return (cmd);
}
