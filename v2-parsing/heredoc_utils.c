#include "parser.h"

int	ft_mkhtmp(t_cmd *cmd)
{
	char	*def;
	char	*random;
	char	*filename;

	def = "/tmp/heredoc_tmp_";
	random = ft_utoa((size_t)&random);
	if (!random)
		return (0);
	filename = custom_join(def, random);
	if (!filename)
		return (0);
	cmd->heredoc_file = filename;
	free(random);
	return (1);
}

int	open_heredoc(char *delim, t_cmd **cmd)
{
	(*cmd)->delim = ft_strdup(delim);
	if ((*cmd)->delim == NULL)
		return (0);
	if (!ft_mkhtmp((*cmd)))
		return (0);
	(*cmd)->fd_in = open((*cmd)->heredoc_file, O_RDWR | O_CREAT);
	// if ((*cmd)->fd_in < 0)
	// 	ft_printf("minishell: %s: %s\n", (*cmd)->heredoc_file, strerror(errno));
	return (1);
}
