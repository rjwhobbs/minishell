#include "../includes/mini.h"

int		main(int ac, char *av[], char *env[])
{
	char *env_var;

	(void)ac;
	(void)av;
	env_var = param_search(env, "PATH", NULL, SEARCH_VAL);
	ft_putendl(env_var);
	return (0);
}