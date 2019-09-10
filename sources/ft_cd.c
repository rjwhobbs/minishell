#include "../includes/mini.h"

int		ft_cd(char *path)
{
	char	oldpwd[PATH_MAX];

	getcwd(oldpwd, PATH_MAX);
	ft_setenv("OLDPWD", oldpwd, ft_strlen("OLDPWD"), ft_strlen(oldpwd));
	chdir(path);
	ft_setenv("PWD", path, ft_strlen("PWD"), ft_strlen(path));
	return (1);
}