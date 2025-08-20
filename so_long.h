/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: showatan <showatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:18:48 by showatan          #+#    #+#             */
/*   Updated: 2025/08/20 17:27:49 by showatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
}	t_data;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;




#endif
