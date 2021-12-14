/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:47:48 by tsomsa            #+#    #+#             */
/*   Updated: 2021/12/14 16:17:10 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "../headers/utils.h"
#include "../headers/types.h"

char	**create_matrix(char *str);
int		str_number_to_int(char *nb);
int		get_board_width(char *str);
t_board	set_board_desc(t_board board, char *data);

t_board	get_fun_board(t_board board)
{
	t_file	file;

	file.desc = 0;
	file = read_file("assets/fun_board.txt", file);
	if (file.desc == -1)
	{
		str_print(file.msg);
		exit(1);
	}
	board = set_board_desc(board, file.data);
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

int		str_number_to_int(char *nb)
{
	int	sum;

	sum = 0;
	while (*nb)
	{
		sum = (sum * 10) + (*nb - '0');
		nb++;
	}
	return (sum);
}

int		get_board_width(char *str)
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
