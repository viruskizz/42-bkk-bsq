/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eof.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 22:28:05 by npiya-is          #+#    #+#             */
/*   Updated: 2021/12/14 01:57:39 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EOF_H
# define EOF_H

typedef struct s_eof
{
	char	empty;
	char	obs;
	char	full;
}	t_eof;

t_eof   detect_eof(char *buff);

#endif
