/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_printable_full.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:34:57 by tsomsa            #+#    #+#             */
/*   Updated: 2021/12/15 00:14:05 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/types.h"

int	can_printable_full(t_board board, int i, int j)
{
	if ((board.sq.x0 <= i && i <= board.sq.x0 + board.sq.len)
		&& (board.sq.y0 <= j && j <= board.sq.y0 + board.sq.len)
		&& board.data[i][j] != board.obs)
		return (1);
	else
		return (0);
}
