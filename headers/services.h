/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   services.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:00:33 by tsomsa            #+#    #+#             */
/*   Updated: 2021/12/14 19:21:44 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVICES_H
# define SERVICES_H

# include "types.h"

t_board	get_fun_board(char *filename, t_board board);
void	print_fun_board(t_board board);

#endif
