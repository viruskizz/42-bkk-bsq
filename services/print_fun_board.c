/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fun_board.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:05:08 by tsomsa            #+#    #+#             */
/*   Updated: 2021/12/14 19:12:39 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../headers/types.h"
void	print_fun_board(t_board board)
{
	int	i;
	int	j;

	i = 0;
	while (i < board.height)
	{
		j = 0;
		while (j < board.width && board.data[i][j] != '\0')
		{
			write(1, &board.data[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
