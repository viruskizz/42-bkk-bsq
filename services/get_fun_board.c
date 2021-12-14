/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:47:48 by tsomsa            #+#    #+#             */
/*   Updated: 2021/12/14 19:33:07 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "../headers/utils.h"
#include "../headers/types.h"

int		get_board_width(char *str);
t_board	set_board_desc(t_board board, char *data);
t_board set_board_matrix_data(t_board board, char *data);

t_board	get_fun_board(char *filename, t_board board)
{
	t_file	file;

	file.desc = 0;
	file = read_file(filename, file);
	if (file.desc == -1)
	{
		str_print(file.msg);
		exit(1);
	}
	board = set_board_desc(board, file.data);
	board = set_board_matrix_data(board, file.data);
	return (board);
}

t_board	set_board_desc(t_board board, char *data)
{
	char	*nb;
	int		i;

	i = 0;
	nb = malloc(100 * sizeof(char));
	while (data[i] >= '0' && data[i] <= '9')
	{
		nb[i] = data[i];
		i++;
	}
	nb[i] = '\0';
	board.width = get_board_width(data);
	board.height = str_number_to_int(nb);
	board.empty = data[i++];
	board.obs = data[i++];
	board.full = data[i++];
	free(nb);
	return (board);
}

t_board	set_board_matrix_data(t_board board, char *data)
{
	char	*buf;
	int		i;
	int		j;

	buf = malloc((board.width + 1) * sizeof(char));
	board.data = malloc((board.height + 1) * (board.width + 1) * sizeof(char));
	while (*data != '\n')
		data++;
	data++;
	i = 0;
	while (*data != '\0')
	{
		j = 0;
		while (*data != '\n')
		{
			buf[j] = *data;
			j++;
			data++;
		}
		buf[j] = '\0';
		board.data[i] = malloc((board.width + 1) * sizeof(char));
		board.data[i] = str_copy(board.data[i], buf);
		i++;
		data++;
	}
	return (board);
}

int	get_board_width(char *str)
{
	int	i;

	i = 0;
	while (*str != '\n')
		str++;
	str++;
	while (*str != '\n')
	{
		str++;
		i++;
	}
	return (i);
}
