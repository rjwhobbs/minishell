#include "libft.h"

char	*ft_arrstr(char	**arr, char *str)
{
	if (arr)
	{
		while(*arr)
		{
			if (ft_strcmp(*arr, str) == 0)
				return (*arr);
			arr++;
		}
		if (!*arr)
			return (*arr);
	}
	return (NULL);
}
