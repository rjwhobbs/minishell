/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:18:23 by wasahmed          #+#    #+#             */
/*   Updated: 2019/09/16 15:18:29 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini.h"

static char	*bin_search(char *path, char *arg, int n)
{
	struct dirent	*bins;
	DIR				*path_to_bin;
	char			location[n + 2];

	ft_strncpy(location, path, n);
	location[n] = '/';
	location[n + 1] = 0;
	path_to_bin = opendir(location);
	if (path_to_bin == NULL)
		return (NULL);
	while ((bins = readdir(path_to_bin)) != NULL)
	{
		if (ft_strcmp(bins->d_name, arg) == 0)
		{
			closedir(path_to_bin);
			return (ft_strdup(location));
		}
		bins++;
	}
	if (closedir(path_to_bin) == -1)
		mini_error(ME_CLSERR, FATAL_ME);
	return (NULL);
}

static char	*path_search(char *arg, char *start, char *end)
{
	char	*path;

	if ((path = bin_search(start, arg, end - start)))
		return (path);
	while (!path)
	{
		start = end;
		if (*start == 0)
			return (NULL);
		start += 1;
		if (!(end = ft_strchr(start, ':')))
			end = ft_strchr(start, 0);
		path = bin_search(start, arg, end - start);
		if (path)
			return (path);
	}
	return (NULL);
}

static char	*path_start(char *var, char *arg, int flag)
{
	char	*start;
	char	*end;

	start = ft_strchr(var, '=');
	if (start)
	{
		if (flag & SEARCH_VAL)
			return (ft_strdup(start + 1));
		if (!(end = ft_strchr(start + 1, ':')))
			end = ft_strchr(start, 0);
		return (path_search(arg, start + 1, end));
	}
	return (NULL);
}

static char	*env_search(char **env, char *env_var, char *arg, int flag)
{
	int		i;
	int		len;

	i = 0;
	while (env[i])
	{
		len = ft_strlen(env_var);
		if (ft_strncmp(env[i], env_var, len) == 0 && (env[i][len] == '='))
		{
			if (!flag)
				return (ft_strdup(env[i]));
			else if (flag)
				return (path_start(env[i], arg, flag));
		}
		i++;
	}
	return (NULL);
}

char		*param_search(char **env, char *env_var, char *arg, int flag)
{
	if (!env || !*env || !env_var || !*env_var)
		return (NULL);
	return (env_search(env, env_var, arg, flag));
}
