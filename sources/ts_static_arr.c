#include "../libft/libft.h"

int	main(void)
{
	int i;
	char *err_name[3];

	err_name[0] = "peanuts";
	err_name[1] = "rasins";
	err_name[2] = NULL;
	i = 0;
	while(err_name[i])
		ft_putendl(err_name[i++]);
	return (0);
}