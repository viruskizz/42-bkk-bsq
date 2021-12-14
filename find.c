/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:35:50 by npiya-is          #+#    #+#             */
/*   Updated: 2021/12/14 22:04:04 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "headers/types.h"
int	g_len;
int	able_to_fill(t_square square, char table[5][5], t_board board);

t_board	find_max_square(char table[5][5], t_board board)
{
	int	h;
	int	w;
	t_square		square;

	h = 0;
	w = 0;
	square.len = 0;
	board.sq.len = 0;
	while (h < board.height)
	{
		square.point.x = h;
		w = 0;	
		while (w < board.width)
		{
			square.point.y = w;
			g_len = able_to_fill(square, table, board);
			if (g_len > board.sq.len)
			{
				board.sq.len = g_len;
				board.sq.point.x = square.point.x;
				board.sq.point.y = square.point.y;
				printf("board x : %d y : %d len : %d\n",board.sq.point.x,board.sq.point.y,board.sq.len);
			}
			w++;
		}
		h++;
	}
	return (board);
}

int	able_to_fill(t_square square, char table[5][5], t_board board)
{
	int	row;
	int	col;
	int	i;
	int	len;

	row = square.point.x;
	col = square.point.y;
	i = 0;
	len = 0;
	printf("start point row : %d col : %d len : %d\n",row, col, square.len);
	if (table[row][col] == board.obs)
		return (0);
	if (!square.len)
	{
		while (table[row][col] != board.obs && col < board.width)
		{
			len++;
			col++;
		}
		square.len = len;
	}
	else
	{
		while (i < square.len && col < board.width)
		{
			i++;
			col++;
		}
	}
	if (square.len == 0)
		return (0);
	col--;
	i = 1;
	printf("move1 row : %d, col : %d len : %d\n", row, col, square.len); 
	while ( i < square.len && row < board.height - 1)
	{
		if (table[row][col] == board.obs)
		{
			square.len--;
			return (able_to_fill(square, table, board));
		}
		row++;
		i++;
	}
	printf("move2 row row : %d, col : %d len : %d\n", row, col, square.len); 
	i = 1;
	while (i < square.len)
	{	
		if (table[row][col] == board.obs)
		{
			square.len--;
			return (able_to_fill(square, table, board));
		}
		col--;
		i++;
	}
	i = 1;
	printf("move3 col row : %d, col : %d len : %d\n", row, col, square.len); 
	while (i < square.len)	
	{		
		if (table[row][col] == board.obs)
		{
			square.len--;
			return (able_to_fill(square, table, board));
		}
		row--;
		i++;
	}
//	if (check_in_square(table , square))
//		return (able_to_fill(square, table, board));
	printf(" last move col row : %d, col : %d len : %d\n", row, col, square.len);
	g_len = square.len;
	return (square.len);
}

//int	chaeck_in_square(
int	main(void)
{
	char	table[5][5];

	table[0][0] = 'o';
	table[0][1] = '.';
	table[0][2] = '.';
	table[0][3] = '.';
	table[0][4] = 'o';
	table[1][0] = '.';
	table[1][1] = '.';
	table[1][2] = '.';
	table[1][3] = 'o';
	table[1][4] = '.';
	table[2][0] = '.';
	table[2][1] = 'o';
	table[2][2] = '.';
	table[2][3] = '.';
	table[2][4] = '.';
	table[3][0] = '.';
	table[3][1] = '.';
	table[3][2] = '.';
	table[3][3] = '.';
	table[3][4] = '.';
	table[4][0] = '.';
	table[4][1] = '.';
	table[4][2] = 'o';
	table[4][3] = '.';
	table[4][4] = '.';

	t_board	board;
	board.width = 5;
	board.height = 5;
	board.obs = 'o';
	board.empty = '.';
	board = find_max_square(table, board);
	printf("square len : %d\n", board.sq.len);
	printf("square x : %d\n", board.sq.point.x);
	printf("square y : %d\n", board.sq.point.y);
	return (0);
}

