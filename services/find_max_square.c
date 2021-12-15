/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:35:50 by npiya-is          #+#    #+#             */
/*   Updated: 2021/12/15 09:04:11 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../headers/types.h"


int			is_fillable_square(t_square square, t_board board);
t_square	able_to_fill(t_square square, t_board board);
t_board	set_max_square(t_square square, t_board board);

t_board	find_max_square(t_board board)
{
	int	i;
	int	j;
	t_square		temp_sq;

	i = 0;
	j = 0;
	temp_sq.len = 0;
	board.sq.len = 0;
	while (i < board.height)
	{
		temp_sq.x0 = i;
		j = 0;	
		while (j < board.width)
		{
			temp_sq.y0 = j;
			temp_sq = able_to_fill(temp_sq, board);
			if (temp_sq.len > board.sq.len)
				board = set_max_square(temp_sq, board);
			j++;
		}
		i++;
	}
	return (board);
}

t_board	set_max_square(t_square square, t_board board)
{
	board.sq.len = square.len;
	board.sq.x0 = square.x0;
	board.sq.y0 = square.y0;
	return (board);
}

t_square	able_to_fill(t_square square, t_board board)
{
	int	i;
	int	j;
	int	k;
	int	len;

	i = square.x0;
	j = square.y0;
	k = 0;
	len = 0;
	// printf("start point row : %d col : %d len : %d\n",row, col, square.len);
	if (board.data[i][j] == board.obs)
	{	square.len = 0;
		return (square);
	}
	if (!square.len)
	{
		while (board.data[i][j] != board.obs && j < board.width)
		{
			len++;
			j++;
		}
		square.len = len;
	}
	else
	{
		while (k < square.len && j < board.width)
		{
			k++;
			j++;
		}
	}
	if (square.len == 0)
		return (square);
	j--;
	k = 1;
	//printf("move1 row : %d, col : %d len : %d\n", row, col, square.len); 
	while ( k < square.len && i < board.height - 1)
	{
		if (board.data[i][j] == board.obs)
		{
			square.len--;
			return (able_to_fill(square, board));
		}
		i++;
		k++;
	}
	// printf("move2 row row : %d, col : %d len : %d\n", row, col, square.len); 
	k = 1;
	while (k < square.len)
	{	
		if (board.data[i][j] == board.obs)
		{
			square.len--;
			return (able_to_fill(square, board));
		}
		j--;
		k++;
	}
	k = 1;
	// printf("move3 col row : %d, col : %d len : %d\n", i, j, square.len); 
	while (k < square.len)	
	{		
		if (board.data[i][j] == board.obs)
		{
			square.len--;
			return (able_to_fill(square, board));
		}
		i--;
		k++;
	}
	if (!is_fillable_square(square, board))
	{
		square.len--;
		return (able_to_fill(square, board));
		// printf(" last move col row : %d, col : %d len : %d\n", row, col, square.len);
	}
	return (square);
}

int	is_fillable_square(t_square square, t_board board)
{
	int	i;
	int	j;

	i = 0;
	while (i < square.len)
	{
		j = 0;
		while (j < square.len)
		{
			if (board.data[i][j] == board.obs)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
