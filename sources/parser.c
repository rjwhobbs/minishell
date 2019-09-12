#include "../includes/mini.h"

static void	ft_rmchr_on_steroids(char *str)
{
	char *p;
	char f;
	int i;

	f = 0;
	p = str;
	while (p && *p)
	{
		i = 0;
		while(*p && *p != '"' && *p != '\'')
			p++;
		if (*p == '"' || *p == '\'')
		{
			if (f == 0)
				f = *p;
			else if (f == *p)
				f = 0;
		}
		if (f == *p || f == 0)
			while (p && p[i++])
				p[i - 1] = p[i];
		else
			p++;		
	}
}

static void		qoute_checker(char **input, char *f)
{
	while (**input && !(**input == ' ' && *f == 0))
	{		
		if (**input == '\'' || **input == '"')
		{
			if (*f == **input)
				*f = 0;
			else if (*f == 0)
				*f = **input;
		}
		(*input)++;
	}
}

static void 	checker(char **args, char *input, char *f)
{
	char 	*ip;
	char 	*op;
	int		i;

	i = 0;
	while (*input)
	{
		ip = input;
		qoute_checker(&input, f);
		op = input;
		if (!(args[i] = ft_strsub(ip, 0, op - ip)))
			mini_error(ME_MEMERR, NONFATAL_ME);
		ft_rmchr_on_steroids(args[i]);
		i++;
		while (*input == ' ')
			input++;
	}
	args[i] = NULL;
}

char	**parser(char *input)
{
	char **args;
	char f;
	int i;

	f = 0;
	i = 0;
	if (!(args = (char**)malloc(sizeof(char*) * (ARG_MAX))))
		mini_error(ME_MEMERR, NONFATAL_ME);
	checker(args, input, &f);
	if (f)
	{
		ft_putendl("Error: quotes");
		ft_strstrdel(&args);
		return (NULL);
	}
	return (args);
}