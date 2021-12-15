/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 07:09:32 by tsomsa            #+#    #+#             */
/*   Updated: 2021/12/15 09:07:16 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "../headers/types.h"

t_square	find_biggest_square(t_square square, t_board board);

t_board	find_square(t_board board)
{
	t_square	square;
	int		i;
	int		j;

	i = 0;
	j = 0;
	board.sq.len = 0;
	printf("Finding Squarexxx\n");
	while (i < board.height)
	{
		// j = 0;
		square.x0 = 0;
		while (square.x0 < board.width)
		{
			square.len = board.width;
			// square.x0 = j;
			square.y0 = i;
			square = find_biggest_square(square, board);
			if (square.len > board.sq.len)
			{
				printf("SET: %d:%d = %d\n", square.y0, square.x0, square.len);
				board.sq.len = square.len;
				board.sq.x0 = square.x0;
				board.sq.y0 = square.y0;
			}
			square.x0++;
			j++;
		}
		i++;
	}
	return (board);
}

t_square	find_biggest_square(t_square square, t_board board)
{
	int		i;
	int		j;

	i = square.y0;
	j = square.x0;
	while (i < board.height && i - square.y0 < square.len)
	{
		j = square.x0;
		while (j < board.width && j - square.x0 < square.len)
		{
			if (board.data[i][j] == board.obs)
				break ;
			j++;
		}
		square.len = j - square.x0;
		i++;
	}
	if (i - square.y0 <= j - square.x0)
		square.len = i - square.y0;
	else
		square.len = 0;
	printf("%d:%d = %d\n", square.y0, square.x0, square.len);
	return square;
}
