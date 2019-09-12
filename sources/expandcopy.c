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

static int index_of(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == 0)
		return (-1);
	return (i);
}

void	expand(char **args)
{
	int 	i;
	int		j;
	int 	index;
	int		word;
	char	*value;
	char	*temp;
	//size_t	size;

	i = 1;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if ((index = index_of(args[i], '$')) >= 0)
			{
				if ((word = index_of(args[i] + index, ' ')) < 0);
					word = ft_strlen(args[i]);
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
		i++;
	}
	//ft_putendl(value);
}