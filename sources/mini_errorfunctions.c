/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_errorfunctions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:14:11 by wasahmed          #+#    #+#             */
/*   Updated: 2019/09/16 15:14:23 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_errors.h"

static void	mini_terminate(void)
{
	ft_putendl(": a fatal error occured: shell terminated.");
	if (g_env && *g_env)
		ft_strstrdel(&g_env);
	exit(EXIT_FAILURE);
}

void		mini_arr_error(char *err, char ***arrdel, int f)
{
	ft_putendl(err);
	if (arrdel && *arrdel)
	{
		ft_strstrdel(arrdel);
		**arrdel = NULL;
	}
	if (f)
		mini_terminate();
}

void		mini_error(char *err, int f)
{
	ft_putendl(err);
	if (f)
		mini_terminate();
}
