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
		ft_strdel(&g_environ_vars[i]);
		i++;
		while (g_environ_vars[i])
		{
			g_environ_vars[i - 1] = g_environ_vars[i];
			i++;
		}
		ft_strdel(&g_environ_vars[i - 1]);
	}
}

//we need to double check mem leaks