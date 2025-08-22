/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: showatan <showatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:40:42 by showatan          #+#    #+#             */
/*   Updated: 2025/08/22 16:52:22 by showatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_sprites(t_game *game)
{
	int	w;
	int	h;

	game->img->wall = mlx_xpm_file_to_image(game->mlx, "wall.xpm", &w, &h);
	game->img->empty = mlx_xpm_file_to_image(game->mlx, "empty.xpm", &w, &h);
	game->img->player = mlx_xpm_file_to_image(game->mlx, "player.xpm", &w, &h);
	game->img->collectible = mlx_xpm_file_to_image(game->mlx, "collectible.xpm", &w, &h);
	game->img->exit = mlx_xpm_file_to_image(game->mlx, "exit.xpm", &w, &h);
	if (!game->img->wall || !game->img->empty ||
		!game->img->player || !game->img-> exit)
	{
		printf("%s", "loadsprites_error\n");
		return (0);
	}
	return (1);
}

void	*check_grid(char grid, t_game *game)
{
	if (grid == '1')
		return (game->img->wall);
	else if (grid == '0')
		return (game->img->empty);
	else if (grid == 'P')
		return (game->img->player);
	else if (grid == 'C')
		return (game->img->collectible);
	else if (grid == 'E')
		return (game->img->exit);
	else
		return (NULL);
}

int	render_map(t_game *game)
{
	int		i;
	int		j;
	void	*sprite;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			sprite = check_grid(game->map->grid[i][j], game);
			if (sprite)
				mlx_put_image_to_window(game->mlx, game->win, sprite,
					j * 64, i * 64);
			j++;
		}
		i++;
	}
	return (0);
}
