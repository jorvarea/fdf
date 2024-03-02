/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:53:57 by jorvarea          #+#    #+#             */
/*   Updated: 2024/03/02 20:35:09 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	top_view(mlx_t *mlx, t_map *map)
{
	int			i;
	uint32_t	x;
	uint32_t	y;
	int			xspacing;
	int			yspacing;
	mlx_image_t	*img;

	img = mlx_new_image(mlx, mlx->width * (1 - 2 * WINDOW_MARGIN), mlx->height * (1 - 2 * WINDOW_MARGIN));
	xspacing = (mlx->width * (1 -  2 * WINDOW_MARGIN)) / map->ncols;
	yspacing = (mlx->height * (1 - 2 * WINDOW_MARGIN)) / map->nrows;
	i = 0;
	y = 0;
	while (i < map->nrows)
	{
		x = 0;
		while (x < img->width)
		{
			mlx_put_pixel(img, x, y, 0xFFFFFFFF);
			x++;
		}
		i++;
		y += yspacing;
	}
	i = 0;
	x = 0;
	while (i < map->ncols)
	{
		y = 0;
		while (y < img->height)
		{
			mlx_put_pixel(img, x, y, 0xFFFFFFFF);
			y++;
		}
		i++;
		x += xspacing;
	}
	mlx_image_to_window(mlx, img, mlx->width * WINDOW_MARGIN, mlx->height * WINDOW_MARGIN);
}

void	manage_key_pressed(void *mlx)
{
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

int	main(int argc, char **argv)
{
	mlx_t	*mlx;
	t_map	map;

	check_argument_count_error(argc);
	ft_memset(&map, 0, sizeof(t_map));
	parse_map(argv[1], &map);
	mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Fil de fer", true);
	check_mlx_error(mlx);
	top_view(mlx, &map);
	mlx_loop_hook(mlx, manage_key_pressed, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free_map_memory(&map);
	return (0);
}
