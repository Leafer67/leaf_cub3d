/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:12:02 by lloison           #+#    #+#             */
/*   Updated: 2023/02/21 18:10:00 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
#define DATA_H

#include "player.h"
#include "map.h"
#include "MLX42/MLX42.h"

typedef struct s_texture
{
	mlx_texture_t	*wall_n;
	mlx_texture_t	*wall_s;
	mlx_texture_t	*wall_e;
	mlx_texture_t	*wall_o;
}	t_texture;

typedef struct	s_image
{
	mlx_image_t		*player;
	mlx_image_t 	*_3d;
	mlx_image_t 	*background;
	mlx_image_t		*line;
	mlx_image_t		*map_img;
}	t_image;


typedef struct s_data
{
	mlx_t			*mlx;
	t_player		*player;
	t_map			*map;
	t_image			image;
	t_texture		texture;
	unsigned int	ceiling_color;
	unsigned int	floor_color;
}	t_data;

t_data	*init_data(char *filename);
void	free_data(t_data *data);
void	drawline3d(t_data *data, int *x, int *side, float *perpWallDist);
void	ft_line2(mlx_image_t *img, int begin_x, int begin_y, int end_x, int end_y, uint32_t color);
int		parse_texture(t_data *data, char *line);
void	parse_texture_and_color(t_data *data, int fd);
int		parse_fc_color(t_data *data, char *line);
void	check_extension(char *line);

#endif
