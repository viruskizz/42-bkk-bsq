/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 01:38:41 by tsomsa            #+#    #+#             */
/*   Updated: 2021/12/16 01:22:27 by tsomsa           ###   ########.fr       */
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
	t_file	file;

	file.desc = 0;
	board.width = 0;
	file = read_file("assets/fun_board.txt", file);
	file = validate_map_header_file(file);
	printf("Validate Map Header: %s\n", file.msg);
	if (file.desc == -1)
		printf("%s\n", file.msg);
	board = set_board_desc(file, board);
	printf("Desctipion set: %d\n", board.height);
	board = validate_board_data(file, board);
	board = get_fun_board(file, board);
	free(file.data);
	printf("Board Description\n");
	printf("width: %d\n", board.width);
	printf("height: %d\n", board.height);
	printf("obs: %c\n", board.obs);
	printf("empty: %c\n", board.empty);
	printf("full: %c\n", board.full);
	board = find_max_square(board); 
	printf("SQ %d:%d = %d\n", board.sq.y0, board.sq.x0, board.sq.len);
	print_fun_board(board);
	free(board.data);
	return (0);
}
