#include "../includes/mini.h"

static void injector(char *value, char **str, char *ptr)
{
	char new[ARG_MAX];

	ft_bzero(new, ARG_MAX);
	ft_memcpy(new, *str, ptr - *str);
	ft_strcat(new, value);
	if ((ptr = ft_strchr(ptr, ' ')))
		ft_strcat(new, ptr);
	ft_strdel(str);
	*str = ft_strdup(new);
	ft_strdel(&value);
}

void	expand(char **args)
{
	int		j;
	char 	*ptr;
	char	*word;
	char	*value;
	char	*temp;

	if (args[1])
		args++;
	else
		return ;
	while (*args)
	{
		j = 0;
		while ((*args)[j]) //While (*args)++ was the issue
		{
			if ((ptr = ft_strchr(*args, '$')))
			{
				if (!(word = ft_strchr(ptr, ' ')))
					word = ft_strchr(ptr, '\0');
				temp = ft_strsub(ptr, 1, word - (ptr + 1));
				value = param_search(g_environ_vars, temp, NULL, SEARCH_VAL);
				if (value)
					injector(value, &*args, ptr);
				else
					ft_putendl("Can't find string!!!!");
				free(temp);
			}
			else
				j++;
		}
		args++;
	}
}