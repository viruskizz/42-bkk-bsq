/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:15:08 by tsomsa            #+#    #+#             */
/*   Updated: 2021/12/15 19:54:27 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include "types.h"

void	str_print(char *str);
int		str_len(char *str);
int		str_number_to_int(char *str);
int		is_c_numeric(char c);
int		is_c_printable(char c);
void	char_write(char *c);
char	*str_copy(char *dest, char *src);
char	*str_concat(char *dest, char *src);


t_file	read_file(char *filename, t_file file);

#endif
