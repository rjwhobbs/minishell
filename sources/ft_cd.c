#include "../includes/mini.h"

int		ft_cd(char *path)
{
	char	oldpwd[PATH_MAX];
	char	pwd[PATH_MAX];
	int		freeme;

	freeme = 0;
	if (!path)
	{
		path = param_search(g_environ_vars, "HOME", NULL, SEARCH_VAL);
		freeme = 1;
	}
	else if (ft_strcmp(path, "-") == 0)
	{
		path = param_search(g_environ_vars, "OLDPWD", NULL, SEARCH_VAL);
		freeme = 1;
	}
	getcwd(oldpwd, PATH_MAX);
	ft_setenv("OLDPWD", oldpwd, ft_strlen("OLDPWD"), ft_strlen(oldpwd));
	chdir(path);
	getcwd(pwd, PATH_MAX);
	ft_setenv("PWD", pwd, ft_strlen("PWD"), ft_strlen(pwd));
	if (freeme)
		free(path);
	return (1);
}