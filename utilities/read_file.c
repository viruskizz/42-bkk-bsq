/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                       :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 22:16:50 by npiya-is          #+#    #+#             */
/*   Updated: 2021/12/14 14:38:28 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../headers/types.h"
#include "../headers/utils.h"

#define BUF_SIZE 1028

t_file	open_file(t_file file);
t_file	read_buffer(t_file file);
t_file	close_file(t_file file);

t_file	read_file(char *filename, t_file file)
{
	file.name = malloc(str_len(filename) * sizeof(char));
	file.msg = malloc(50 * sizeof(char));
	file.name = str_copy(file.name, filename);
	file = open_file(file);
	if (file.desc == -1)
		return (file);
	file = read_buffer(file);
	file = close_file(file);
	return (file);
}

t_file	open_file(t_file file)
{
	file.desc = open(file.name, O_RDONLY);
	if (file.desc == -1)
	{
		file.msg = str_copy(file.msg, "Error: Cannot open file.");
		file.data = "\0";
	}
	else
		file.msg = str_copy(file.msg, "Open succeed");
	return (file);
}

t_file	read_buffer(t_file file)
{
	char	*buf;
	int		ret;

	buf = malloc((BUF_SIZE + 1) * sizeof(char));
	ret = read(file.desc, buf, BUF_SIZE);
	while (ret)
	{
		buf[ret] = '\0';
		str_concat(file.data, buf);
		ret = read(file.desc, buf, BUF_SIZE);
	}
	free(buf);
	return (file);
}

t_file	close_file(t_file file)
{
	if (close(file.desc) == -1)
	{
		file.desc = -1;
		file.msg = str_copy(file.msg, "Error Cannot close file");
	}
	return (file);
}
