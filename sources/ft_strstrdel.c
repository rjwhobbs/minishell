#include "../includes/mini.h"

void	ft_strstrdel(char ***del_me)
{
	int i;

	i = 0;
	while ((*del_me)[i])
		free((*del_me)[i++]);
	free(*del_me);
}