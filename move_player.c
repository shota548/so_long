/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: showatan <showatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:54:54 by showatan          #+#    #+#             */
/*   Updated: 2025/08/21 20:42:07 by showatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player->x;
	new_y = game->player->y;
	if (keycode == 13 || keycode == 119)
		new_y--;
	else if (keycode == 1 || keycode == 115)
		new_y++;
	else if (keycode == 0 || keycode == 97)
		new_x--;
	else if (keycode == 2 || keycode == 100)
		new_x++;
	if (game->map->grid[new_y][new_x] != '1')
	{
		if (game->map->grid[new_y][new_x] == 'C')
			game->collect_count--;
		if (game->map->grid[new_y][new_x] == 'E'
			&& game->collect_count == 0)
        {
            printf("You won in %d moves!\n", game->moves);
            mlx_destroy_window(game->mlx, game->win);
            free(game->player);
            exit(0);
        }
		mlx_put_image_to_window(game->mlx, game->win, game->img->empty,
			game->player->x * 64, game->player->y * 64);
		printf("Moves: %d\n", game->moves);
		game->map->grid[game->player->y][game->player->x] = '0';
		game->player->x = new_x;
		game->player->y = new_y;
		game->map->grid[game->player->y][game->player->x] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->img->player,
			game->player->x * 64, game->player->y * 64);
		game -> moves++;
	}
	return (0);
}
