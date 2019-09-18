/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:28:27 by wasahmed          #+#    #+#             */
/*   Updated: 2019/09/18 14:50:08 by rhobbs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini.h"

int				ft_echo(char **args)
{
	char	flag;
	int		i;

	flag = 0;
	i = 0;
	args++;
	if (*args && (*args)[i++] == '-')
	{
		while ((*args)[i] == 'n')
			i++;
		if (!(*args)[i])
		{
			flag = 'n';
			args++;
		}
	}
	while (*args)
	{
		ft_putstr(*args++);
		if (*args)
			ft_putchar(' ');
	}
	if (!flag)
		ft_nl();
	return (1);
}
