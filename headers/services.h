/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   services.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:00:33 by tsomsa            #+#    #+#             */
/*   Updated: 2021/12/15 16:10:31 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVICES_H
# define SERVICES_H

# include "types.h"

t_board	get_fun_board(char *filename, t_board board);
t_board	find_max_square(t_board board);
void	print_fun_board(t_board board);
int		can_printable_full(t_board board, int i, int j);

#endif
