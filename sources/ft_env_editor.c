#include "../includes/mini.h"



void	ft_setenv(char *var_name, char *value, size_t varlen, size_t vallen)
{
	char 	newstr[varlen + vallen + 2];
	int		i;
	char	*original_val;
	char	*temp;

	i = 0;
	while (g_environ_vars[i])
	{
		if (ft_strncmp(g_environ_vars[i], var_name, ft_strlen(var_name)) == 0)
			break ;
		i++;
	}
	ft_bzero(newstr, sizeof(newstr));
	ft_strcat(newstr, var_name);
	ft_strcat(newstr, "=");
	ft_strcat(newstr, value);
	if (g_environ_vars[i])
	{
		original_val = ft_strchr(g_environ_vars[i], '=') + 1;
		if (ft_strlen(original_val) >= vallen)
		{
			ft_strcpy(original_val, value);
		}
		else
		{
			temp = ft_strdup(newstr);
			free(g_environ_vars[i]);
			g_environ_vars[i] = temp;
		}
	}
	else
		g_environ_vars = ft_strarrrealloc(g_environ_vars, newstr);
}


//void	ft_unsetenv()