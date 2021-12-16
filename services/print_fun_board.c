/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fun_board.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:05:08 by tsomsa            #+#    #+#             */
/*   Updated: 2021/12/16 17:15:12 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../headers/types.h"
#include "../headers/utils.h"
#include "../headers/services.h"

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define RESET "\033[m"

void	print_point(t_board board, int i, int j);
void	print_board_description(t_board board);
void	print_square_description(t_board board);

void	print_fun_board(t_board board)
{
	int	i;
	int	j;

	i = 0;
	print_board_description(board);
	print_square_description(board);
	while (i < board.height)
	{
		j = 0;
		while (j < board.width && board.data[i][j] != '\0')
		{
			print_point(board, i, j);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	print_board_description(t_board board)
{
	str_print("=== Board Description update ===\n");
	str_print("-Board: ");
	nbr_print(board.height);
	str_print(" x ");
	nbr_print(board.width);
	str_print("\n");
	str_print("-Empty: ");
	write(1, &board.empty, 1);
	str_print("\n");
	str_print("-OBS  : ");
	str_print(RED);
	write(1, &board.obs, 1);
	str_print(RESET);
	str_print("\n");
	str_print("-Full : ");
	str_print(GREEN);
	write(1, &board.full, 1);
	str_print(RESET);
	str_print("\n");
}

void	print_square_description(t_board board)
{
	str_print("-SQ   : ");
	nbr_print(board.sq.x0);
	write(1, ",", 1);
	nbr_print(board.sq.y0);
	str_print("\n");
	str_print("-Size : ");
	nbr_print(board.sq.len);
	str_print("\n");
}

void	print_point(t_board board, int i, int j)
{
	if ((board.sq.x0 <= j && j <= board.sq.x0 + board.sq.len - 1)
		&& (board.sq.y0 <= i && i <= board.sq.y0 + board.sq.len - 1)
		&& board.data[i][j] != board.obs)
	{
		str_print(GREEN);
		write(1, &board.full, 1);
	}
	else if (board.data[i][j] == board.obs)
	{
		str_print(RED);
		write(1, &board.data[i][j], 1);
	}
	else
		write(1, &board.data[i][j], 1);
	write(1, " ", 1);
	str_print(RESET);
}
