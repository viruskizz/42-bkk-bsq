/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_board.h                                            :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 02:37:11 by tsomsa            #+#    #+#             */
/*   Updated: 2021/12/14 10:08:23 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_BOARD_H
# define F_BOARD_H

typedef struct f_board
{
	int		file_desc;
	char	*file_msg[50];
	int		height;
	int		width;
	char	obs;
	char	empty;
	char	*data;
}	t_board

#endif
