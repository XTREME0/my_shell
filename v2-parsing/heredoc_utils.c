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

int	read_heredoc(t_redirs *redirs)
{
	char	*line;

	redirs->fd = open(redirs->filename, O_CREAT | O_RDWR, 0644);
	if (redirs->fd == -1)
	{
		printf(FD_ERR, redirs->filename, strerror(errno));
		return (0);
	}
	while (1)
	{
		line = readline("heredoc> ");
		if (!line)
		{
			printf(HD_EOF, redirs->delim);
			break ;
		}
		if (ft_strcmp(line, redirs->delim) == 0)
			break ;
		write(redirs->fd, line, ft_strlen(line));
		free(line);
	}
	return (close(redirs->fd), free(line), 1);
}
