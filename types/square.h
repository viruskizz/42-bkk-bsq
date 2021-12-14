/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:46:58 by npiya-is          #+#    #+#             */
/*   Updated: 2021/12/15 00:32:29 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_H
# define SQUARE_H

# include "point.h"

typedef struct s_square
{
	int			len;
	int			x0;
	int			y0;
	t_point		point;
}	t_square;

#endif
