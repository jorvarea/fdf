/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:53:57 by jorvarea          #+#    #+#             */
/*   Updated: 2024/03/26 21:09:42 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_line_between_points(mlx_image_t *img, t_point a, t_point b)
{
	int slope;
	int x;
	int y;
	
	if (b.x != a.x)
	{
		x = a.x;
		slope = (b.y - a.y) / (b.x - a.x);
		while (x <= b.x)
		{
			y = a.y + slope * (x - a.x);
			mlx_put_pixel(img, x, y, 0xFFFFFFFF);
			x++;
		}
	}
	else
	{
		x = a.x;
		y = a.y;
		while (y <= b.y)
		{
			mlx_put_pixel(img, x, y, 0xFFFFFFFF);
			y++;
		}
	}
}

void connect_neighbours(mlx_image_t *img, int fil, int col, int spacing)
{
	t_point current_point;
	t_point neighbour;
	
	current_point.x = col * spacing;
	current_point.y = fil * spacing;
	if (fil != 0)
	{
		neighbour.x = current_point.x;
		neighbour.y = current_point.y - spacing;
		draw_line_between_points(img, neighbour, current_point);
	}
	if (col != 0)
	{
		neighbour.x = current_point.x - spacing;
		neighbour.y = current_point.y;
		draw_line_between_points(img, neighbour, current_point);
	}
}

void	top_view(mlx_t *mlx, t_map *map)
{
	int	i;
	int j;
	int	spacing;
	mlx_image_t	*img;

	img = mlx_new_image(mlx, 0.9 * mlx->width, 0.9 * mlx->height);
	check_mlx_image_error(img);
	spacing = ft_min_float(img->width / map->ncols, img->height / map->nrows);
	i = 0;
	while (i < map->nrows)
	{
		j = 0;
		while (j < map->ncols)
		{
			connect_neighbours(img, i, j, spacing);
			j++;
		}
		i++;
	}
	mlx_image_to_window(mlx, img, (mlx->width / 2) - (img->width / 2), (mlx->height / 2) - (img->height / 2));
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
	check_valid_map_dimensions(&map);
	mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Fil de fer", true);
	check_mlx_error(mlx);
	top_view(mlx, &map);
	mlx_loop_hook(mlx, manage_key_pressed, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free_map_memory(&map);
	return (0);
}
