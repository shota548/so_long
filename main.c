/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: showatan <showatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:12:20 by showatan          #+#    #+#             */
/*   Updated: 2025/08/21 20:25:34 by showatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(int keycode, void *param)
{
	t_game	*data;

	data = (t_game *)param;
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data);
		exit(0);
	}
	return (0);
}

int	destroy_window_hook(void *param)
{
	t_game	*data;

	data = (t_game *)param;
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data);
	exit(0);
	return (0);
}

int find_player_position(t_map *map, t_player *player)
{
    int y;
    int x;

    y = 0;
    while (y < map->height)
    {
        x = 0;
        while (x < map->width)
        {
            if (map->grid[y][x] == 'P')
            {
                player->x = x;
                player->y = y;
                return (1);
            }
            x++;
        }
        y++;
    }
    return (0);
}

int count_collectibles(t_map *map)
{
    int count;
    int y;
    int x;

    count = 0;
    y = 0;
    while (y < map->height)
    {
        x = 0;
        while (x < map->width)
        {
            if (map->grid[y][x] == 'C')
                count++;
            x++;
        }
        y++;
    }
    return (count);
}

int destroy_hook(void *param)
{
    t_game *game;

    game = (t_game *)param;
    mlx_destroy_window(game->mlx, game->win);
    exit(0);
    return (0);
}

int main(int argc, char **argv)
{
    t_game  game;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <map_file.ber>\n", argv[0]);
        return (1);
    }

    game.map = read_map_with_malloc(argv[1]);
    if (!game.map || !validate_map(game.map))
        return (1);

    game.mlx = mlx_init();
    if (!game.mlx)
        return (1);

    game.win = mlx_new_window(game.mlx, game.map->width * 64, game.map->height * 64, "so_long");
    if (!game.win)
        return (1);

    game.img = malloc(sizeof(t_img));
    if (!game.img || !load_sprites(&game))
        return (1);

    game.player = malloc(sizeof(t_player));
    if (!game.player)
        return (1);
    find_player_position(game.map, game.player);

    game.collect_count = count_collectibles(game.map);
    game.moves = 0;

    render_map(&game);

    mlx_key_hook(game.win, key_hook, &game);
    mlx_hook(game.win, 17, 0, destroy_hook, &game);

    mlx_loop(game.mlx);

    // メモリの解放
    // TODO: ここにメモリ解放のロジックを追加
    return (0);
}

