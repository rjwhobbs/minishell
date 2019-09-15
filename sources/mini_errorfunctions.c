#include "../includes/mini_errors.h"

static void	mini_terminate(void)
{
	ft_putendl(": a fatal error occured: shell terminated.");
	if (g_environ_vars && *g_environ_vars)
		ft_strstrdel(&g_environ_vars);
	exit(EXIT_FAILURE);
}

void 		mini_arr_error(char *err, char ***arrdel, int f)
{
	ft_putendl(err);
	if (arrdel && *arrdel)
	{
		ft_strstrdel(arrdel);
		**arrdel = NULL;
	}
	if (f)
		mini_terminate();
}

void           mini_error(char *err, int f)
{
	ft_putendl(err);
	if (f)
		mini_terminate();
}

