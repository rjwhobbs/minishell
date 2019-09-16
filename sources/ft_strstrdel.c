/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:51:56 by wasahmed          #+#    #+#             */
/*   Updated: 2019/09/16 14:52:02 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini.h"

void	ft_strstrdel(char ***del_me)
{
	int i;

	i = 0;
	while ((*del_me)[i])
		free((*del_me)[i++]);
	free(*del_me);
}
