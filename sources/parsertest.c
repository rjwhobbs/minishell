#include "../libft/libft.h"

static void	ft_rmchr(char *str, char c)
{
	char *p;
	int i;

	if ((c == '"' || c == '\'') && str)
	{
		p = str;
		while (p && *p)
		{
			i = 0;
			p = ft_strchr(p, c);
			while (p && p[i])
			{
				p[i] = p[i + 1];
				i++;
			}
		}
	}
}

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
			while (p && p[i])
			{
				p[i] = p[i + 1];
				i++;
			}
		else
			p++;		
	}
}

int		main(void)
{
	char *input;
	char *tmp;
	char *array[1024];
	char *ip;
	char *op;
	char f;
	int i;
	int j;

	f = 0;
	get_next_line(1, &input);
	tmp = ft_strtrim(input);
	ft_strdel(&input);
	input = tmp;
	i = 0;
	while (*input)
	{
		ip = input;
		while (*input && !(*input == ' ' && f == 0))
		{		
			if (*input == '\'' || *input == '"')
			{
				if (f == *input)
					f = 0;
				else if (f == 0)
					f = *input;
			}
			input++;
		}
		op = input;
		array[i] = ft_strsub(ip, 0, op - ip);
		ft_rmchr_on_steroids(array[i]);
		i++;
		while (*input == ' ')
			input++;
	}		
	free(tmp);
	if (f)
		ft_putendl("Error: quotes");
	else
	{

		ft_putnbr(i);
		j = 0;
		while (j < i)
		{
			ft_putstr(array[j]);
			ft_putendl("$");
			j++;
		}
	}
	return (0);
}