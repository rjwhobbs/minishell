/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_errors.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:41:02 by wasahmed          #+#    #+#             */
/*   Updated: 2019/09/16 15:41:17 by wasahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_ERRORS_H
# define MINI_ERRORS_H
# include "mini.h"

# define NONFATAL_ME 0
# define FATAL_ME	1

# define ME_CLSERR	"error closing directory stream"
# define ME_MEMERR	"error allocating memory"

void	mini_arr_error(char *err, char ***arrdel, int f);
void	mini_error(char *err, int f);

#endif
