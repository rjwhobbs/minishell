#include "../includes/mini.h"

size_t		ft_strarrlen(char **arr)
{
	size_t i;

	i = 0;
	if (arr)
		while (arr[i])
			i++;
	return (i);
}