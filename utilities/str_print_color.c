/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_print_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 05:38:00 by tsomsa            #+#    #+#             */
/*   Updated: 2021/12/16 05:40:49 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/constants.h"
#include "../headers/utils.h"

void	str_print_color(char *str, char *color)
{
	str_print(color);
	str_print(str);
	str_print(C_RESET);
}
