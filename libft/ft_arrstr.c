/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:31:36 by wasahmed          #+#    #+#             */
/*   Updated: 2019/09/16 15:32:57 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_arrstr(char **arr, char *str)
{
	if (arr)
	{
		while (*arr)
		{
			if (ft_strcmp(*arr, str) == 0)
				return (*arr);
			arr++;
		}
		if (!*arr)
			return (*arr);
	}
	return (NULL);
}
