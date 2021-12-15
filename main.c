/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 01:38:41 by tsomsa            #+#    #+#             */
/*   Updated: 2021/12/16 03:46:08 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "headers/utils.h"
#include "headers/types.h"
#include "headers/services.h"
#include "headers/constants.h"

void	runner(int argc, char *argv[]);
void	executor(t_file file);
void	print_error_msg(char *msg);

int	main(int argc, char *argv[])
{
	if (argc >= 2)
	{
		runner(argc, argv);
	}
	str_print(C_RED);
	str_print("== FINISH!! ==\n");
	str_print(C_RESET);
	return (0);
}

void	runner(int argc, char *argv[])
{
	t_file file;
	int	i;

	i = 1;
	while (i < argc)
	{
		file.desc = 0;
		file = read_file(argv[i], file);
		str_print("FILE: ");
		str_print(file.name);
		str_print("\n");
		if (file.desc == -1)
		{
			print_error_msg(file.msg);
			i++;
			continue ;
		}
		file = validate_map_header_file(file);
		if (file.desc == -1)
		{
			print_error_msg(file.msg);
			i++;
			continue ;
		}
		executor(file);
		free(file.data);
		str_print("\n");
		i++;
	}
}

void	executor(t_file file)
{
	t_board	board;

	board.width = 0;
	board = set_board_desc(file, board);
	board = validate_board_data(file, board);
	if (!board.is_valid)
	{
		print_error_msg(board.msg);
		return ;
	}
	board = get_fun_board(file, board);
	board = find_max_square(board);
	print_fun_board(board);
	free(board.data);
}

void	print_error_msg(char *msg)
{
	str_print(C_RED);
	str_print(msg);
	str_print(C_RESET);
	str_print("\n\n");
}
