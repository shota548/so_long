/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: showatan <showatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:18:48 by showatan          #+#    #+#             */
/*   Updated: 2025/08/21 20:18:00 by showatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_img
{
	void	*player;
	void	*wall;
	void	*empty;
	void	*collectible;
	void	*exit;
}	t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_player	*player;
	t_img		*img;
	int			moves;
	int			collect_count;
}	t_game;

char	*get_next_line(int fd);
int		ft_strchr_len(const char *s, int search_c );
void	*ft_memcpy(void *dst, const void *src, size_t len);
char	*ft_strdnup(const char *s1, int n);
char	*ft_strjoin(char const *s1, char const *s2);
int	count_lines(char *file_path);
int	load_sprites(t_game *game);
int	render_map(t_game*game);
t_map	*count_line_with_malloc(char *file_path);
t_map	*read_map_with_malloc(char *file_path);
int	close_window(int keycode, void *param);
int	destroy_window_hook(void *param);
int main(int argc, char **argv);
int	is_rectangular(t_map *map);
int	is_surrounded_by_walls(t_map *map);
int	has_required_elements(t_map *map);
int	validate_map(t_map *map);
int destroy_hook(void *param);
int	key_hook(int keycode, t_game *game);


#endif
