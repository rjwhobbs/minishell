/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrrealloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:50:47 by wasahmed          #+#    #+#             */
/*   Updated: 2019/09/16 14:51:26 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini.h"

char	**ft_strarrrealloc(char **arr, char *str)
{
	char	**new;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strarrlen(arr);
	new = (char**)malloc(sizeof(char*) * (len + 2));
	new[len + 1] = NULL;
	while (len--)
	{
		new[i] = ft_strdup(arr[i]);
		i++;
	}
	new[i] = ft_strdup(str);
	ft_strstrdel(&arr);
	return (new);
}
