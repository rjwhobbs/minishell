/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:34:04 by wasahmed          #+#    #+#             */
/*   Updated: 2019/09/18 14:54:32 by rhobbs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini.h"

static void	injector(char *value, char **str, char *ptr)
{
	char new[ARG_MAX];
	char *check;

	ft_bzero(new, ARG_MAX);
	ft_memcpy(new, *str, ptr - *str);
	if (value)
		ft_strcat(new, value);
	else
	{
		if (!ptr[1])
			ft_strcat(new, "$");
	}
	if ((check = ft_strchr(ptr, ' ')))
		ft_strcat(new, check);
	ft_strdel(str);
	*str = ft_strdup(new);
	ft_strdel(&value);
}

static void	expand_checker(char **str)
{
	int		j;
	char	*ptr;
	char	*temp;
	char	*value;
	char	*word;

	j = 0;
	ptr = NULL;
	while ((*str)[j])
	{
		if ((ptr = ft_strchr(&(*str)[j], '$')) && (*str)[0])
		{
			if (!(word = ft_strchr(ptr, ' ')))
				word = ft_strchr(ptr, '\0');
			j = (ptr - *str) + 1;
			temp = ft_strsub(ptr, 1, word - (ptr + 1));
			value = param_search(g_env, temp, NULL, SEARCH_VAL);
			injector(value, str, ptr);
			ft_strdel(&temp);
		}
		else
			j++;
	}
}

void		expand(char **args)
{
	if (!args || !*args || !**args)
		return ;
	if (args[1])
		args++;
	else
		return ;
	while (*args)
	{
		expand_checker(args);
		args++;
	}
}
