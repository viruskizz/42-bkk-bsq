/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_print_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:41:37 by tsomsa            #+#    #+#             */
/*   Updated: 2021/12/16 19:06:43 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "../headers/constants.h"

void	str_print_err(char *str)
{
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
}

void	str_print_err_color(char *str)
{
	str_print_err(C_RED);
	str_print_err(str);
	str_print_err(C_RESET);
	str_print_err("\n");
}
