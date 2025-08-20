/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_array_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: showatan <showatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:23:23 by showatan          #+#    #+#             */
/*   Updated: 2025/08/20 19:48:28 by showatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines(char *file_path)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening map file");
		return (-1);
	}
	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line = get_next_line(fd);
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

t_map	*count_line_with_malloc(char *file_path)
{
	int		fd;
	int		idx;
	char	line;
	t_map	*map;

	fd = open(file_path, O_RDONLY);
	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
	{
		perror ("Memory allocation failed for map");
		return (NULL);
	}
	map->height = count_lines(file_path);
	if (map->height <= 0)
	{
		free(map);
		return (NULL);
	}
	return (map);
}

t_map	*read_map_with_malloc(char *file_path)
{
	int		fd;
	char	line;
	t_map	*map;
	int		idx;

	map->grid = (char **)malloc(sizeof(char *) * map ->height);
	if (!map->grid)
	{
		free(map);
		perror("Memory allocation failed for grid");
		return (NULL);
	}
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		free(map->grid);
		free(map);
		perror("Error opening map file on second read");
		return (NULL);
	}
	idx = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line = get_next_line(fd);
		map->grid[idx] = line;
		idx++;
	}
	close(fd);
	if (map->height > 0)
		map->width = strlen(map->grid[0]);
	return (map);
}
