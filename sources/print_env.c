/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:25:14 by wasahmed          #+#    #+#             */
/*   Updated: 2019/09/16 15:25:19 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini.h"

int	print_env(char **ep)
{
	int	i;

	i = 0;
	while (ep[i])
		ft_putendl(ep[i++]);
	return (1);
}
