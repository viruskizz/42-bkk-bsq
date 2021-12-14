/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 01:38:41 by tsomsa            #+#    #+#             */
/*   Updated: 2021/12/14 23:04:30 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include "headers/utils.h"
#include "headers/types.h"
#include "headers/services.h"

int	main(void)
{
	t_board	board;

	str_print("It's work\n");
	board.width = 0;
	board = get_fun_board("assets/fun_board.txt", board);
	printf("width: %d\n", board.width);
	printf("height: %d\n", board.height);
	printf("obs: %c\n", board.obs);
	printf("empty: %c\n", board.empty);
	printf("full: %c\n", board.full);
	board = find_max_square(board); 
	// board.sq.x0 = 0;
	// board.sq.y0 = 0;
	// board.sq.len = 4;
	print_fun_board(board);
	return (0);
}
