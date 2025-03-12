#include "../minishell.h"

int	ft_mkhtmp(t_cmd *cmd)
{
	char	*def;
	char	*random;
	char	*filename;

	def = "/tmp/heredoc_tmp_";
	random = ft_itoa(*random);
	if (!random)
		return (0);
	filename = ft_strjoin(def, random);
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
	(*cmd)->heredoc_fd = open((*cmd)->heredoc_file, O_RDWR | O_CREAT);
	if ((*cmd)->heredoc_fd < 0)
		ft_printf("minishell: %s: %s\n", (*cmd)->heredoc_file, strerror(errno));
	return (1);
}
