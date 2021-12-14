/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_obstacle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:45:23 by npiya-is          #+#    #+#             */
/*   Updated: 2021/12/14 16:10:06 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include"point.h"
#include"eof.h"

int	read_files(char *file, char *buff, int buff_size);

int	count_obs(char *buff, t_eof de)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*(buff + i))
	{
		if (*(buff + i) == de.obs)
			count++;
		i++;
	}
	return (count - 1);
}

t_point	*find_obs(char *buff, t_eof de, int c_obs)
{
	int			x;
	int			y;
	int			index;
	t_point		*obs;

	obs = malloc((c_obs + 1) * sizeof(t_point));
	x = 0;
	index = 0;
	while (*(buff++))
	{
		if (*buff == '\n')
		{
			y = 0;
			x++;
		}
		if (*(buff) == de.obs && x != 0)
		{
			obs[index].ob = de.obs;
			obs[index].x = x;
			obs[index].y = y;
			index++;
		}
		y++;
	}
	return (obs);
}

int	main(int argc, char **argv)
{
	char	*buff;
	int	count;
	t_eof	obs;
	t_point	*adobs;

	buff = malloc(4096 * sizeof(char));
	if (argc == 2)
	{
		if (read_files(argv[1], buff, 4096) != 0)
		{
			printf("%s\n", buff);
			obs = detect_eof(buff);
			count = count_obs(buff, obs);
			printf("empty : %c, obs : %c, full : %c\n",obs.empty, obs.obs, obs.full);
			printf("obstacle number : %d\n", count);
			adobs = find_obs(buff, obs, count);
			for (int i = 0; i < count; i++)
			{
				printf("obs %d : %c, x: %d, y: %d\n",i + 1,adobs[i].ob, adobs[i].x, adobs[i].y);
			}
		}
	}
	return (0);
}
