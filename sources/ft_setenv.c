/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:47:32 by wasahmed          #+#    #+#             */
/*   Updated: 2019/09/16 15:29:31 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini.h"

static void	editor(char *value, size_t vallen, char *newstr, int index)
{
	char	*original_val;
	char	*temp;

	original_val = ft_strchr(g_env[index], '=') + 1;
	if (!original_val)
		return ;
	else if (ft_strlen(original_val) >= vallen)
		ft_strcpy(original_val, value);
	else
	{
		temp = ft_strdup(newstr);
		free(g_env[index]);
		g_env[index] = temp;
	}
}

void		ft_setenv(char *var, char *value, size_t varlen, size_t vallen)
{
	char	newstr[varlen + vallen + 2];
	int		i;

	if (!var || !value || !*var || !*value)
		mini_error("Incorrect setenv format", NONFATAL_ME);
	i = 0;
	while (g_env[i])
	{
		if (!ft_strncmp(g_env[i], var, varlen) && (g_env[i][varlen] == '='))
			break ;
		i++;
	}
	ft_bzero(newstr, sizeof(newstr));
	ft_strcat(newstr, var);
	ft_strcat(newstr, "=");
	ft_strcat(newstr, value);
	if (g_env[i])
		editor(value, vallen, newstr, i);
	else
		g_env = ft_strarrrealloc(g_env, newstr);
}

int			setenv_checker(char **args)
{
	if (ft_strarrlen(args) != 3)
		mini_error("Incorrect amount of arguments", 0);
	else
		ft_setenv(args[1], args[2], ft_strlen(args[1]), ft_strlen(args[2]));
	return (1);
}
