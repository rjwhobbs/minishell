#include "../includes/mini.h"

void	print_env(char **ep)
{
	int	i;

	i = 0;
	while(ep[i])
		ft_putendl(ep[i++]);
}

void	ft_setenv(char **env)
{
	ft_strcpy(*env, "WHAAATTTTTTTTTTTTTTTTTTTTTTTPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPT");
}

int	main(int ac, char *av[], char *env[])
{
	print_env(env);
	ft_setenv(env);
	print_env(env);
	return(0);
}