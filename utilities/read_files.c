/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 22:16:50 by npiya-is          #+#    #+#             */
/*   Updated: 2021/12/14 12:10:54 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../headers/types.h"

int	read_files(char *file, char *buff, int buff_size)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	read(fd, buff, buff_size);
	return (1);
}

t_eof	detect_eof(char *buff)
{
	t_eof	de;
	int	i;

	i = 0;
	while (*(buff) != '\n')
	{
		buff++;
	}
	de.empty = *(buff - 3);
	de.obs = *(buff - 2);
	de.full = *(buff - 1);
	return (de);
}
