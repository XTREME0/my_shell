#include "parser.h"

void	open_in(char *filename, t_cmd **cmd)
{
	(*cmd)->fd_in = open(filename, O_RDONLY);
	// if ((*cmd)->fd_in < 0)
	// 	ft_printf("minishell: %s: %s\n", filename, strerror(errno));
	(*cmd) = (*cmd)->next;
}
void	open_out(char *filename, t_cmd **cmd)
{
	(*cmd)->fd_out = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
	// if ((*cmd)->fd_out < 0)
	// 	ft_printf("minishell: %s: %s\n", filename, strerror(errno));
	(*cmd) = (*cmd)->next;
}

void	open_append(char *filename, t_cmd **cmd)
{
	(*cmd)->fd_out = open(filename, O_CREAT | O_RDWR | O_APPEND, 0644);
	// if ((*cmd)->fd_out < 0)
	// 	ft_printf("minishell: %s: %s\n", filename, strerror(errno));
	(*cmd) = (*cmd)->next;
}

void	set_pipe(t_cmd **cmd)
{
	(*cmd)->fd_out = -1;
	if (!(*cmd)->next)
		(*cmd)->next->fd_in = -1;
	(*cmd) = (*cmd)->next;
}
