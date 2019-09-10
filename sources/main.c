#include "../includes/mini.h"

void	print_env(char **ep)
{
	int	i;

	i = 0;
	while(ep[i])
		ft_putendl(ep[i++]);
}

int		main(int ac, char *av[], char *env[])
{
	(void)ac;
	(void)av;
	
	g_environ_vars = ft_strarrdup(env);
	print_env(g_environ_vars);
	//ft_setenv(av[1], av[2], ft_strlen(av[1]), ft_strlen(av[2]));
	ft_putendl("........................");
	ft_unsetenv(av[1]);
	print_env(g_environ_vars);
	ft_strstrdel(&g_environ_vars);
	return (0);
}