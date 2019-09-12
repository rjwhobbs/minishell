#include "../includes/mini.h"

static void injector(char *value, char **str, char *ptr)
{
	char new[ARG_MAX];

	(void)value;
	ft_bzero(new, ARG_MAX);
	ft_memcpy(new, *str, ptr - *str);
	ft_strcat(new, value);
	if ((ptr = ft_strchr(ptr, ' ')))
		ft_strcat(new, ptr);
	ft_strdel(str);
	*str = ft_strdup(new);
	//ft_putstr(new);
	//ft_putendl("$");
}

void	expand(char **args)
{
	int 	i;
	char 	*ptr;
	char	*word;
	char	*value;
	char	*temp;
	//size_t	size;

	i = 0;
	args++;
	while (*args)
	{
		//ft_putendl(*args);
		while (**args)
		{
			if ((ptr = ft_strchr(*args, '$')))
			{
				if (!(word = ft_strchr(ptr, ' ')))
					word = ft_strchr(ptr, '\0');
				//ft_putendl(*args);
				temp = ft_strsub(ptr, 1, word - (ptr + 1));
				value = param_search(g_environ_vars, temp, NULL, SEARCH_VAL);
				if (value)
				{
					value = ft_strdup(value);
					injector(value, &*args, ptr);
				}
				else
					ft_putendl("Can't find string!!!!");
				free(temp);
				//*args = ptr;
				//*args = word;
			}
			else
				(*args)++;
			
		}
		args++;
	}
	//ft_putendl(value);
}