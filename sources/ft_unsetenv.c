#include "../includes/mini.h"

void	ft_unsetenv(char *varname)
{
	int		i;
	size_t	vlen;

	i = 0;
	vlen = ft_strlen(varname);
	while (g_environ_vars[i])
	{
		if (ft_strncmp(g_environ_vars[i], varname, vlen) == 0)
			break ;
		i++;
	}	
	if (g_environ_vars[i])
	{
		free(g_environ_vars[i]);
		g_environ_vars[i] = NULL;
		i++;
		while (g_environ_vars[i])
		{
			g_environ_vars[i - 1] = g_environ_vars[i];
			i++;
		}
		g_environ_vars[i - 1] = NULL;
	}
}

//we need to double check mem leaks