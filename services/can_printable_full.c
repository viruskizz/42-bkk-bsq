/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_printable_full.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:34:57 by tsomsa            #+#    #+#             */
/*   Updated: 2021/12/15 09:08:20 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/types.h"

int	can_printable_full(t_board board, int i, int j)
{
	if ((board.sq.x0 <= j && j <= board.sq.x0 + board.sq.len - 1)
		&& (board.sq.y0 <= i && i <= board.sq.y0 + board.sq.len - 1)
		&& board.data[i][j] != board.obs)
		return (1);
	else
		return (0);
}
