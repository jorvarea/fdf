/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:01:18 by jorvarea          #+#    #+#             */
/*   Updated: 2024/04/07 19:19:20 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_alpha_channel(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->ncolors)
	{
		map->color[i].color = (map->color[i].color << 8) + 0xFF;
		i++;
	}
}

unsigned int	find_color(t_map *map, int z)
{
	bool			found;
	unsigned int	color;
	int				i;

	found = false;
	i = 0;
	while (i < map->ncolors && !found)
	{
		if (map->color[i].z == z)
			found = true;
		i++;
	}
	if (found)
		color = map->color[i - 1].color;
	else
		color = DEFAULT_COLOR;
	return (color);
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
		float coeff)
{
	t_color			colors_a;
	t_color			colors_b;
	t_color			result;
	unsigned int	final_color;

	if (color_a != color_b)
	{
		split_colors(color_a, &colors_a);
		split_colors(color_b, &colors_b);
		result.red = (1.0 - coeff) * colors_a.red + coeff * colors_b.red;
		result.green = (1.0 - coeff) * colors_a.green + coeff * colors_b.green;
		result.blue = (1.0 - coeff) * colors_a.blue + coeff * colors_b.blue;
		final_color = merge_colors(&result);
	}
	else
		final_color = color_a;
	return (final_color);
}
