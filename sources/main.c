#include "../includes/mini.h"

void	print_env(char **ep)
{
	int	i;

	i = 0;
	while(ep[i])
		ft_putendl(ep[i++]);
}

char	**ft_strarrrealloc(char **arr, char *str)
{
	char	**new;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strarrlen(arr);
	new = (char**)malloc(sizeof(char*) * (len + 2));
	new[len + 1] = NULL;
	while(len--)
	{
		new[i] = ft_strdup(arr[i]);
		i++;
	}
	new[i] = str;
	ft_strstrdel(&arr);
	return (new);
}

void	ft_setenv()
{
	g_environ_vars = ft_strarrrealloc(g_environ_vars, "CHEESE=awesome");
}

int		main(int ac, char *av[], char *env[])
{
	(void)ac;
	(void)av;
	
	g_environ_vars = ft_strarrdup(env);
	print_env(g_environ_vars);
	ft_setenv();
	print_env(g_environ_vars);
	return (0);
}