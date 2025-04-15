#include "parser.h"

int	main(int ac, char **av, char **envp)
{
	t_env	*env;

	env = my_setenv(envp);
	char *str = readline("$> ");
	t_cmd	*cmds = construct_cmds(str, env);
	ft_clearcmds(&cmds);
	env_clear(env);
	free(str);
}
