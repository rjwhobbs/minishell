/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:24:28 by wasahmed          #+#    #+#             */
/*   Updated: 2019/09/18 15:09:41 by rhobbs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini.h"

static void	ft_rmchr_on_steroids(char *p)
{
	char	f;
	int		i;

	f = 0;
	while (p && *p)
	{
		i = 0;
		while (*p && *p != '"' && *p != '\'')
			p++;
		if (*p == '"' || *p == '\'')
		{
			if (f == 0)
				f = *p;
			else if (f == *p)
				f = 0;
		}
		if (f == *p || f == 0)
			while (p && p[i++])
				p[i - 1] = p[i];
		else
			p++;
	}
}

static void	qoute_checker(char **input, char *f)
{
	while (**input && !(ft_isspace(**input) && *f == 0))
	{
		if (**input == '\'' || **input == '"')
		{
			if (*f == **input)
				*f = 0;
			else if (*f == 0)
				*f = **input;
		}
		(*input)++;
	}
}

static void	tilde_expander(char **str)
{
	char *home;
	char *temp;

	home = param_search(g_env, "HOME", NULL, SEARCH_VAL);
	temp = ft_strrealloc(home, &(*str)[1]);
	ft_strdel(str);
	*str = temp;
}

static void	checker(char **args, char *input, char *f)
{
	char	*ip;
	char	*op;
	int		i;

	i = 0;
	while (*input)
	{
		ip = input;
		qoute_checker(&input, f);
		op = input;
		if (!(args[i] = ft_strsub(ip, 0, op - ip)))
		{
			mini_arr_error(ME_MEMERR, &args, NONFATAL_ME);
			return ;
		}
		if (args[i][0] == '~' && (!args[i][1] || args[i][1] == '/'))
			tilde_expander(&args[i]);
		ft_rmchr_on_steroids(args[i]);
		i++;
		while (ft_isspace(*input))
			input++;
	}
	args[i] = NULL;
}

char		**parser(char *input)
{
	char	**args;
	char	f;

	f = 0;
	if (!input || !*input)
		return (NULL);
	if (!(args = (char**)malloc(sizeof(char*) * (ARG_MAX))))
	{
		mini_error(ME_MEMERR, NONFATAL_ME);
		return (NULL);
	}
	checker(args, input, &f);
	if (f)
	{
		ft_putendl("Error: unmatched qoutes.");
		if (args && *args)
			ft_strstrdel(&args);
		return (NULL);
	}
	return (args);
}
