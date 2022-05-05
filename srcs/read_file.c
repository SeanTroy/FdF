/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:43:24 by plehtika          #+#    #+#             */
/*   Updated: 2022/02/17 16:13:40 by plehtika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mapdata_to_int(char ***mapdata, t_map *map)
{
	int	y;
	int	x;

	map->z = (int **)malloc(sizeof(int *) * map->height);
	if (!map->z)
		error_exit(3);
	y = 0;
	x = 0;
	while (mapdata[y] != 0)
	{
		map->z[y] = (int *)malloc(sizeof(int) * map->width);
		if (!map->z[y])
			error_exit(3);
		while (mapdata[y][x] != 0)
		{
			map->z[y][x] = ft_atoi(mapdata[y][x]);
			if (map->z[y][x] < map->mindepth)
				map->mindepth = map->z[y][x];
			if (map->z[y][x] > map->maxdepth)
				map->maxdepth = map->z[y][x];
			x++;
		}
		x = 0;
		y++;
	}
}

char	***save_mapdata(int fd, t_map *map)
{
	char	***mapdata;
	int		i;
	char	*line;
	int		gnl_return;

	mapdata = (char ***)malloc(sizeof(char **) * (map->height + 1));
	if (!mapdata)
		error_exit(3);
	i = 0;
	gnl_return = get_next_line(fd, &line);
	while (gnl_return == 1)
	{
		mapdata[i++] = ft_strsplit(line, ' ');
		free(line);
		gnl_return = get_next_line(fd, &line);
	}
	close(fd);
	if (gnl_return == -1)
		error_exit(0);
	mapdata[i] = 0;
	return (mapdata);
}

void	get_map_dimensions(char *argv, t_map *map)
{
	int		fd;
	char	*line;
	int		gnl_return;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		error_exit(0);
	gnl_return = get_next_line(fd, &line);
	if (gnl_return == 0 || gnl_return == -1)
		error_exit(gnl_return + 1);
	map->width = ft_word_counter(line, ' ');
	while (gnl_return == 1)
	{
		map->height++;
		if (ft_word_counter(line, ' ') != map->width)
			error_exit(2);
		free(line);
		gnl_return = get_next_line(fd, &line);
	}
	close(fd);
	if (gnl_return == -1)
		error_exit(0);
	return ;
}

void	read_file(char *argv, t_map *map)
{
	int		fd;
	char	***mapdata;

	map->height = 0;
	map->width = 0;
	map->mindepth = 0;
	map->maxdepth = 0;
	get_map_dimensions(argv, map);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		error_exit(0);
	mapdata = save_mapdata(fd, map);
	mapdata_to_int(mapdata, map);
	ft_del3darray((void ****)&mapdata, map->height, map->width);
	return ;
}
