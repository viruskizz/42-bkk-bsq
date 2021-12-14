/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 01:38:41 by tsomsa            #+#    #+#             */
/*   Updated: 2021/12/14 14:20:55 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/utils.h"
#include "headers/types.h"

int	main(void)
{
	t_file file;

	str_print("It's work\n");
	file.desc = 0;
	file = read_file("assets/fun_board.txt", file);
	if (file.desc == -1)
	{
		str_print(file.msg);
		return (0);
	}
	str_print(file.data);
	return (0);
}
