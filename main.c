/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: showatan <showatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:12:20 by showatan          #+#    #+#             */
/*   Updated: 2025/08/20 13:21:32 by showatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
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
	t_data	*data;

	data = (t_data *)param;
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data);
	exit(0);
	return (0);
}

int	main(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (1);

	data->win = mlx_new_window(data->mlx, 800, 600, "So Long");
	if (data->win == NULL)
	{
		free(data);
		return (1);
	}

	mlx_key_hook(data->win, close_window, data);

	mlx_hook(data->win, 17, 0, destroy_window_hook, data);

	mlx_loop(data->mlx);

	free(data);
	return (0);
}
