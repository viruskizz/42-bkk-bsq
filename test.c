/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 01:38:41 by tsomsa            #+#    #+#             */
/*   Updated: 2021/12/16 05:56:03 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
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
	if (file.desc == -1)
		printf("%s\n", file.msg);
	board = set_board_desc(file, board);
	board = validate_board_data(file, board);
	board = get_fun_board(file, board);
	free(file.data);
	board = find_max_square(board);
	print_fun_board(board);
	free(board.data);
	return (0);
}
