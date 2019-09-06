/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhobbs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 08:38:39 by rhobbs            #+#    #+#             */
/*   Updated: 2019/09/06 09:36:11 by rhobbs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			temp_check(char **temp, char **line, int end)
{
	char	*del_temp;
	char	*nlp;

	*line = ft_strnew(0);
	del_temp = *temp;
	nlp = ft_strchr(*temp, '\n');
	if (!nlp && ft_strlen(*temp) > 0)
	{
		*line = ft_strrealloc(*line, *temp);
		if (end == 0)
			ft_strdel(temp);
		return (1);
	}
	else if (nlp)
	{
		*nlp = '\0';
		*line = ft_strrealloc(*line, *temp);
		*temp = ft_strdup(nlp + 1);
		ft_strdel(&del_temp);
		if (**temp == '\0')
			ft_strdel(temp);
	}
	return (1);
}

static int			buff_rw(char **temp, int fd)
{
	char		buff[GNL_BUFF_SIZE + 1];
	int			end;

	end = 0;
	if (!*temp)
		if (!(*temp = ft_strnew(0)))
			return (-1);
	if (!ft_strchr(*temp, '\n'))
		while ((end = read(fd, buff, GNL_BUFF_SIZE)) > 0)
		{
			buff[end] = '\0';
			if (!(*temp = ft_strrealloc(*temp, buff)))
				return (-1);
			if (ft_strchr(buff, '\n'))
				break ;
		}
	return (end);
}

int					get_next_line(const int fd, char **line)
{
	static char		*temp;
	int				end;

	if (fd < 0 || !line)
		return (-1);
	if ((end = buff_rw(&temp, fd)) < 0)
		return (-1);
	if (end == 0 && (temp == NULL || *temp == '\0'))
		return (0);
	return (temp_check(&temp, line, end));
}
