#ifndef MINI_H
# define MINI_H
# include "../libft/libft.h"
# include <dirent.h>

#define SEARCH_OFF	0
#define SEARCH_ON	01
#define SEARCH_VAL	02

char		**g_environ_vars;
//extern char **environ;

char		*param_search(char **env, char *env_var, char *arg, int flag);
char		**ft_strarrdup(char **arr);
size_t		ft_strarrlen(char **arr);
void		ft_strstrdel(char ***del_me);
char		**ft_strarrrealloc(char **arr, char *str);
void		ft_setenv(char *var_name, char *value, size_t varlen, size_t vallen);

#endif