#include "../includes/mini_errors.h"

static void	mini_terminate(void)
{
	ft_putendl(" A fatal error occured");
	exit(EXIT_FAILURE);
}

void		mini_error(char *err_name, int flag)
{
	ft_putendl(err_name);
	if (flag)
		mini_terminate();
}

