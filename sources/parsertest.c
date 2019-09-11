#include "../libft/libft.h"

int main(void)
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
		while (*input)
		{
			if (*input == ' ' && f == 0)
				break;
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