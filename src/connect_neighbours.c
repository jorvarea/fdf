/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_neighbours.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:14:11 by jorvarea          #+#    #+#             */
/*   Updated: 2024/04/06 16:26:58 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static bool	point_inside_img(mlx_image_t *img, float x, float y)
{
	unsigned int actual_x;
	unsigned int actual_y;

	actual_x = ft_round(x) + IMG_OFFSET;
	actual_y = ft_round(y) + IMG_OFFSET;
	
	return (actual_x >= 0 && actual_y >= 0 && actual_x < img->width 
			&& actual_y < img->height);
}

static void	draw_inverse_slope_line(mlx_image_t *img, t_point *a, t_point *b)
{
	float			slope;
	float			x;
	float			y;
	unsigned int	color;
	float			coefficient;

	slope = (b->xyz[0] - a->xyz[0]) / (b->xyz[1] - a->xyz[1]);
	y = a->xyz[1];
	while (y <= b->xyz[1])
	{
		x = a->xyz[0] + slope * (y - a->xyz[1]);
		if (a->color != b->color)
		{
			coefficient = (y - a->xyz[1]) / (b->xyz[1] - a->xyz[1]);
			color = color_gradient(a->color, b->color, coefficient);
		}
		else
			color = a->color;
		if (point_inside_img(img, x, y))
			mlx_put_pixel(img, IMG_OFFSET + ft_round(x), IMG_OFFSET + ft_round(y), color);
		y++;
	}
}

static void	draw_line_between_points(mlx_image_t *img, t_point *a, t_point *b)
{
	float			slope;
	float			x;
	float			y;
	unsigned int	color;
	float			coefficient;

	slope = (b->xyz[1] - a->xyz[1]) / (b->xyz[0] - a->xyz[0]);
	if (ft_abs_float(slope) <= 1)
	{
		x = a->xyz[0];
		while (x <= b->xyz[0])
		{
			y = a->xyz[1] + slope * (x - a->xyz[0]);
			coefficient = (x - a->xyz[0]) / (b->xyz[0] - a->xyz[0]);
			if (a->color != b->color)
				color = color_gradient(a->color, b->color, coefficient);
			else
				color = a->color;
			if (point_inside_img(img, x, y))
				mlx_put_pixel(img, IMG_OFFSET + ft_round(x), IMG_OFFSET + ft_round(y), color);
			x++;
		}
	}
	else
		draw_inverse_slope_line(img, a, b);
}

void	connect_neighbours(mlx_image_t *img, t_coord_matrix *coord_matrix,
		int row, int col)
{
	if (row > 0)
		draw_line_between_points(img, &coord_matrix->m[row - 1][col],
			&coord_matrix->m[row][col]);
	if (col > 0)
		draw_line_between_points(img, &coord_matrix->m[row][col - 1],
			&coord_matrix->m[row][col]);
}
