#include "../includes/mini.h"

int		ft_cd(char *path)
{
	char	oldpwd[PATH_MAX];
	char	pwd[PATH_MAX];

	getcwd(oldpwd, PATH_MAX);
	ft_setenv("OLDPWD", oldpwd, ft_strlen("OLDPWD"), ft_strlen(oldpwd));
	chdir(path);
	getcwd(pwd, PATH_MAX);
	ft_setenv("PWD", pwd, ft_strlen("PWD"), ft_strlen(pwd));
	return (1);
}