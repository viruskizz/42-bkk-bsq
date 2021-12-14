/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:05:51 by tsomsa            #+#    #+#             */
/*   Updated: 2021/12/14 10:08:03 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_H
# define BOARD_H

typedef struct s_board
{
	int		width;
	int		height;
	char	obs;
	char	empty;
	char	**data;
}	t_board

#endif
