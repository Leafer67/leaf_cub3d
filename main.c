// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "cub3d.h"

void hook(void* param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	ft_movement(data);
}

int32_t	main(int argc, char **argv)
{
	mlx_t		*mlx;
	t_data		*data;
	mlx_image_t	*player;
	mlx_image_t	*vector_dir;
	mlx_image_t	*map_img;

	if (argc != 2)
	{
		ft_printf_error("ERROR: Wrong argument count\n");
		exit(11);
	}
	mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D", FALSE);
	if (!mlx)
		system_error("MLX ERROR");
	data = init_data(mlx, argv[1]);
	map_img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	vector_dir = mlx_new_image(mlx, VEC_DIR, VEC_DIR);
	player = mlx_new_image(mlx, WALL_SIZE + 1, WALL_SIZE + 1);
	data->img = player;
	data->vec_dir = vector_dir;
	if (data->player->tile_pos.y == 0)
		data->player->tile_pos.y = 1;
	if (data->player->tile_pos.x == 0)
		data->player->tile_pos.x = 1;
	data->player->dir.x = 0;
	data->player->dir.y = -(VEC_DIR / 2);
	circleBres((WALL_SIZE / 2), (WALL_SIZE / 2), PL_HITBOX, 0xFF0000FF, player);
	ft_draw_map(data->map, 0xFF00FF00, map_img);
	ft_line(data->vec_dir, VEC_DIR / 2, VEC_DIR / 2, VEC_DIR / 2 + data->player->dir.x, VEC_DIR / 2 + data->player->dir.y, 0xFF0000FF);
	mlx_image_to_window(mlx, map_img, 0, 0);
	mlx_image_to_window(mlx, player, WALL_SIZE * data->player->tile_pos.x, WALL_SIZE * data->player->tile_pos.y);
	mlx_image_to_window(mlx, vector_dir, WALL_SIZE * data->player->tile_pos.x, WALL_SIZE * data->player->tile_pos.y);
	mlx_loop_hook(mlx, &hook, data);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}