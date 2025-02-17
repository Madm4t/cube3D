/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:31:32 by wdegraf           #+#    #+#             */
/*   Updated: 2025/02/17 14:15:24 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
//# include "MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

# define WIDTH 2048
# define HEIGHT 2048
# define TILE_SIZE 32
# define PLAYER_SIZE 16
# define PI 3.141592

typedef struct s_texture
{
	mlx_image_t		*img;
	int				width; 
	int				height;
}					t_texture;

typedef struct s_vector
{
	float			player_x;
	float			player_y;
}					t_vector;

typedef struct s_char
{
	mlx_image_t		*player_img;
	t_vector		pos;
	float			angle;
	t_vector		plane;
}					t_char;

typedef struct s_cub3d
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	char			**map;
	int				map_width;
	int				map_height;
	t_texture		texture[4];
	int				roof;
	int				floor;
	t_char			player;
}					t_c;

void	er_ex(t_c cub, char *str);
bool	scan_map(char *file, t_c *cub);
bool	parse_line(char *trim_line, t_c *cub, mlx_texture_t *texture,
			char *path);
bool	valid_map(t_c *cub, int p_count, int x, int y);
void	create_player(t_c *cub, int x, int y);
bool	map_err(char *line, int fd);

//draw_map.c
void	draw_map2D(t_c *cub);

//create_player.c
bool	collision(t_c *cub, float x, float y);
bool	is_wall(t_c *cub, float px, float py);

#endif