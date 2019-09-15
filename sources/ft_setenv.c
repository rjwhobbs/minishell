#include "../includes/mini.h"

static void		editor(char *value, size_t vallen, char *newstr, int index)
{
	char	*original_val;
	char	*temp;

	original_val = ft_strchr(g_environ_vars[index], '=') + 1; //what if the envar has incorrect format
	if (!original_val)
		return ;
	else if (ft_strlen(original_val) >= vallen)
		ft_strcpy(original_val, value);
	else
	{
		temp = ft_strdup(newstr);
		free(g_environ_vars[index]);
		g_environ_vars[index] = temp;
	}
}

void			ft_setenv(char *var_name, char *value, size_t varlen, size_t vallen)
{
	char 	newstr[varlen + vallen + 2];
	int		i;

	if (!var_name || !value || !*var_name || !*value)
		mini_error("Incorrect setenv format", NONFATAL_ME);
	i = 0;
	while (g_environ_vars[i])
	{
		if (ft_strncmp(g_environ_vars[i], var_name, varlen) == 0)
			break ;
		i++;
	}
	ft_bzero(newstr, sizeof(newstr));
	ft_strcat(newstr, var_name);
	ft_strcat(newstr, "=");
	ft_strcat(newstr, value);
	if (g_environ_vars[i])
		editor(value, vallen, newstr, i);
	else
		g_environ_vars = ft_strarrrealloc(g_environ_vars, newstr);
}

// Need to handle no value and no varname
//void	ft_unsetenv()