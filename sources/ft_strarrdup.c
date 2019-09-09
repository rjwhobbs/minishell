#include "../includes/mini.h"

char	**ft_strarrdup(char **arr)
{
	char	**dup;
	char	**dup_z;
	size_t	len;

	if (!(len = ft_strarrlen(arr)))
		return (NULL);
	if (!(dup = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	dup_z = dup;
	dup[len] = NULL;
	while(len--)
		*dup++ = ft_strdup(*arr++);
	return (dup_z);
}