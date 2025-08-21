/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: showatan <showatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:04:34 by showatan          #+#    #+#             */
/*   Updated: 2025/08/21 16:34:48 by showatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(t_map *map)
{
	int	idx;

	idx = 0;
	while (idx < map->height)
	{
		if (ft_strlen(map->grid[idx]) - 1 != map->width)
			return (0);
		idx++;
	}
	return (1);
}

int	is_surrounded_by_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->width)
	{
		if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (j < map->height)
	{
		if (map->grid[j][0] != '1' || map->grid[j][map->width-1] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	has_required_elements(t_map *map)
{
	int	player_count;
	int	exit_count;
	int	collect_count;
	int	i;
	int	j;

	player_count = 0;
	exit_count = 0;
	collect_count = 0;
	i = 0;
	while (i < map -> height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == 'P')
				player_count++;
			else if (map->grid[i][j] == 'E')
				exit_count++;
			else if (map->grid[i][j] == 'C')
				collect_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1 || exit_count != 1 || collect_count < 1)
		return (0);
	return (1);
}

int	validate_map(t_map *map)
{
	if (is_rectangular(map) == 0)
	{
		write(1, "Error\nMap is not rectangular.\n", 31);
		return (0);
	}
	if (is_surrounded_by_walls(map) == 0)
	{
		write(1, "Error\nMap is not surrounded by walls.\n", 38);
		return (0);
	}
	if (has_required_elements(map) == 0)
	{
		write(1, "Error\nMap does not have required elements.\n", 44);
		return (0);
	}
	return (1);
}
