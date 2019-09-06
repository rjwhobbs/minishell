#include "../includes/mini.h"

int		main(int ac, char *av[], char *env[])
{
	char *env_var;

	(void)ac;
	//(void)av;
	env_var = param_search(env, "PATH", av[1], SEARCH_ON);
	ft_strjoin(env_var, av[1]);
	ft_putendl(env_var);
	return (0);
}