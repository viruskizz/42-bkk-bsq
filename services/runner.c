/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 05:36:19 by tsomsa            #+#    #+#             */
/*   Updated: 2021/12/16 06:02:07 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../headers/utils.h"
#include "../headers/types.h"
#include "../headers/services.h"
#include "../headers/constants.h"
#include <unistd.h>

void	runner(int argc, char *argv[]);
void	executor(t_file file);
t_file	runner_validate_file(t_file file);

void	runner(int argc, char *argv[])
{
	t_file	file;
	int		i;

	i = 1;
	while (i < argc)
	{
		file.desc = 0;
		file = read_file(argv[i], file);
		str_print("FILE: ");
		str_print(file.name);
		str_print("\n");
		file = runner_validate_file(file);
		if (file.desc == -1)
		{
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
		str_print_color(board.msg, C_RED);
		return ;
	}
	board = get_fun_board(file, board);
	board = find_max_square(board);
	print_fun_board(board);
	free(board.data);
}

t_file	runner_validate_file(t_file file)
{
	if (file.desc == -1)
	{
		str_print_color(file.msg, C_RED);
		str_print("\n");
		return (file);
	}
	file = validate_map_header_file(file);
	if (file.desc == -1)
	{
		str_print_color(file.msg, C_RED);
		str_print("\n");
		return (file);
	}
	return (file);
}
