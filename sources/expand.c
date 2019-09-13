#include "../includes/mini.h"

static void injector(char *value, char **str, char *ptr)
{
	char new[ARG_MAX];
	char	*wordend;

	ft_bzero(new, ARG_MAX);
	ft_memcpy(new, *str, ptr - *str);
	if (value)
		ft_strcat(new, value);
	else
	{
		if (!(wordend = ft_strchr(ptr, ' ')))
			wordend = ft_strchr(ptr, '\0');
		// if ((wordend - ptr) == 1)
		// 	ft_strcat(new,"$");		
	}
	if ((ptr = ft_strchr(ptr, ' ')))
		ft_strcat(new, ptr);
	ft_strdel(str);
	*str = ft_strdup(new);
	ft_strdel(&value);
}

static void expand_checker(char **str)
{
	int		j;
	char	*ptr;
	char	*temp;
	char	*value;
	char	*word;

	j = 0;
	while ((*str)[j]) //While (*args)++ was the issue
	{
		if ((ptr = ft_strchr(&(*str)[j], '$')))
		{
			if (!(word = ft_strchr(ptr, ' ')))
				word = ft_strchr(ptr, '\0');
			j = word - ptr;
			// ft_putnbr(j);
			// ft_nl();
			temp = ft_strsub(ptr, 1, word - (ptr + 1));
			// ft_putstr(temp);
			// ft_putendl("X");
			value = param_search(g_environ_vars, temp, NULL, SEARCH_VAL);
			//if (value)
				injector(value, str, ptr);
			//else
			//	ft_putendl("Can't find string!!!!");
			free(temp);
		}
		else
			j++;
	}
}

void	expand(char **args)
{
	if (args[1])
		args++;
	else
		return ;
	while (*args)
	{
		expand_checker(args);
		args++;
	}
}