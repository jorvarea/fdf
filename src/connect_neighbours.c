/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_neighbours.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:14:11 by jorvarea          #+#    #+#             */
/*   Updated: 2024/03/26 23:10:56 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_vertical_line(mlx_image_t *img, t_point a, t_point b)
{
	int				x;
	int				y;
	unsigned int	color;

	x = a.x;
	y = a.y;
	while (y <= b.y)
	{
		color = a.color + 1.0 * (y - a.y) / (b.y - a.y) * (b.color - a.color);
		mlx_put_pixel(img, x, y, color);
		y++;
	}
}

static void	draw_line_between_points(mlx_image_t *img, t_point a, t_point b)
{
	int				slope;
	int				x;
	int				y;
	unsigned int	color;
	int				coefficient;

	x = a.x;
	if (b.x != a.x)
	{
		slope = (b.y - a.y) / (b.x - a.x);
		while (x <= b.x)
		{
			y = a.y + slope * (x - a.x);
			coefficient = 1.0 * (x - a.x) / (b.x - a.x);
			color = a.color + coefficient * (b.color - a.color);
			mlx_put_pixel(img, x, y, color);
			x++;
		}
	}
	else
		draw_vertical_line(img, a, b);
}

static unsigned int	assign_color(t_map *map, int row, int col)
{
	unsigned int	color;

	if (map->color[map->data[row][col]])
		color = (map->color[map->data[row][col]] << 8) + 0xFF;
	else
		color = 0xFFFFFFFF;
	return (color);
}

void	connect_neighbours(mlx_image_t *img, t_map *map, t_coordinates *coord,
		int spacing)
{
	t_point	current_point;
	t_point	neighbour;

	current_point.x = coord->col * spacing;
	current_point.y = coord->row * spacing;
	current_point.color = map->color[map->data[coord->row][coord->col]];
	if (coord->row != 0)
	{
		neighbour.x = current_point.x;
		neighbour.y = current_point.y - spacing;
		neighbour.color = assign_color(map, coord->row - 1, coord->col);
		draw_line_between_points(img, neighbour, current_point);
	}
	if (coord->col != 0)
	{
		neighbour.x = current_point.x - spacing;
		neighbour.y = current_point.y;
		neighbour.color = assign_color(map, coord->row, coord->col - 1);
		draw_line_between_points(img, neighbour, current_point);
	}
}
