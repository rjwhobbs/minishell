/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:38:21 by wasahmed          #+#    #+#             */
/*   Updated: 2019/09/16 15:38:25 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H
# include "../libft/libft.h"
# include "mini_errors.h"
# include <dirent.h>
# include <limits.h>
# include <sys/wait.h>

# define SEARCH_OFF	0
# define SEARCH_ON	01
# define SEARCH_VAL	02

# ifndef ARG_MAX
#  define ARG_MAX (256 * 1024)
# endif

char		**g_env;

char		*param_search(char **env, char *env_var, char *arg, int flag);
char		**ft_strarrdup(char **arr);
size_t		ft_strarrlen(char **arr);
void		ft_strstrdel(char ***del_me);
char		**ft_strarrrealloc(char **arr, char *str);
void		ft_setenv(char *var, char *value, size_t varlen, size_t vallen);
void		ft_unsetenv(char *varname);
int			ft_cd(char *path);
char		**parser(char *input);
void		expand(char **args);
int			unsetenv_checker(char **args);
int			setenv_checker(char **args);
int			ft_echo(char **args);
int			print_env(char **ep);
int			access_control(char *str);
int			access_control_f(char *str);

#endif
