#include "parser.h"

int	main(int ac, char **av, char **envp)
{
	t_env	*env;

	env = my_setenv(envp);
	while (env)
	{
		printf("%s=%s\n", env->key, env->val);
		env = env->next;
	}
}
