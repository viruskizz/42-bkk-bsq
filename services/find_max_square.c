/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:35:50 by npiya-is          #+#    #+#             */
/*   Updated: 2021/12/15 14:53:06 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../headers/types.h"

int	min_size(t_square sq, t_board b);
int	expand(t_square sq, t_board b);
int			is_fillable_square(t_square square, t_board board);
int	able_to_fill(t_square square, t_board board);
t_board	set_max_square(t_square square, t_board board);

t_board	find_max_square(t_board board)
{
	int	i;
	int	j;
	t_square		temp_sq;

	i = 0;
	board.sq.len = 0;
	temp_sq.len = 0;
	while (i < board.height)
	{
		j = 0;
		while (j < board.width)
		{
			temp_sq.x0 = i;
			temp_sq.y0 = j;
			if (able_to_fill(temp_sq, board))
			{
				temp_sq.len = able_to_fill(temp_sq, board);
				if (temp_sq.len > board.sq.len)
					board = set_max_square(temp_sq, board);
				temp_sq.len = 0;
			}
			j++;
		}
		i++;
	}
	printf("return x0 : %d , y0 : %d, len ; %d\n",board.sq.x0, board.sq.y0, board.sq.len);
	return (board);
}	

t_board	set_max_square(t_square square, t_board board)
{
	board.sq.len = square.len;
	board.sq.x0 = square.x0;
	board.sq.y0 = square.y0;
	return (board);
}

int	able_to_fill(t_square sq, t_board b)
{
	if (sq.x0 < b.height - 1 && sq.y0 < b.width - 1)
	{
		if (min_size(sq, b))
		{
			sq.len = 2;
			sq.len = expand(sq, b);
			return (sq.len - 1);
		}
	}
	return (0);	
}

int	min_size(t_square sq, t_board b)
{
	if (b.data[sq.x0][sq.y0] != b.obs && b.data[sq.x0 + 1][sq.y0] != b.obs
			&& b.data[sq.x0][sq.y0 + 1] != b.obs 
				&& b.data[sq.x0 + 1][sq.y0 + 1] != b.obs)
					return (1);
	return (0);
}

int	expand(t_square sq, t_board b)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = sq.y0 + i;
	k = sq.x0 + i;
	if (sq.x0 + sq.len == b.height  || sq.y0 + sq.len == b.width)
		return (sq.len);
	while (i <= sq.len && (i + sq.len) < b.height)
	{
		if (b.data[sq.x0 + sq.len][sq.y0 + i] == b.obs)
			return (sq.len);
		if (b.data[sq.x0 + i][sq.y0 + sq.len] == b.obs)
			return (sq.len);
		i++;
	}
	sq.len++;
	return (expand(sq, b));
}
