/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 01:38:41 by tsomsa            #+#    #+#             */
/*   Updated: 2021/12/16 05:43:48 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "headers/utils.h"
#include "headers/types.h"
#include "headers/services.h"
#include "headers/constants.h"
#include <unistd.h>

void	get_input(void);

int	main(int argc, char *argv[])
{
	if (argc >= 2)
		runner(argc, argv);
	else
		get_input();
	str_print_color("== FINISH!! ==\n", C_RED);
	return (0);
}

void	get_input(void)
{
	char	input[100];
	char	buf;
	int		i;
	char	*arr[2];

	str_print("INPUT:\n");
	i = 0;
	while (read(0, &buf, 1) > 0 && i < 100)
	{
		if (buf == '\n')
			break ;
		input[i] = buf;
		i++;
	}
	input[i] = '\0';
	arr[1] = input;
	runner(2, arr);
}
