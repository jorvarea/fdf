/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:01:18 by jorvarea          #+#    #+#             */
/*   Updated: 2024/04/06 15:54:15 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_alpha_channel(t_map *map)
{
	unsigned int	color;
	int				row;
	int				col;

	row = 0;
	while (row < map->nrows)
	{
		col = 0;
		while (col < map->ncols)
		{
			if (map->color[map->data[row][col]])
				color = (map->color[map->data[row][col]] << 8) + 0xFF;
			else
				color = DEFAULT_COLOR;
			map->color[map->data[row][col]] = color;
			col++;
		}
		row++;
	}
}

static void	split_colors(unsigned int color, t_color *colors)
{
	colors->red = (color >> 24) & 0xFF;
	colors->green = (color >> 16) & 0xFF;
	colors->blue = (color >> 8) & 0xFF;
	colors->alpha = color & 0xFF;
}

static unsigned int	merge_colors(t_color *colors)
{
	unsigned int	color;

	color = (colors->red << 24) | (colors->green << 16) | (colors->blue << 8) 
		| colors->alpha;
	return (color);
}

unsigned int	color_gradient(unsigned int color_a, unsigned int color_b,
		float coefficient)
{
	t_color	colors_a;
	t_color	colors_b;
	t_color	result;

	split_colors(color_a, &colors_a);
	split_colors(color_b, &colors_b);
	result.red = (1.0 - coefficient) * colors_a.red + coefficient
		* colors_b.red;
	result.green = (1.0 - coefficient) * colors_a.green + coefficient
		* colors_b.green;
	result.blue = (1.0 - coefficient) * colors_a.blue + coefficient
		* colors_b.blue;
	return (merge_colors(&result));
}
