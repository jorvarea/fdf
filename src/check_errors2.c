/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:38:30 by jorvarea          #+#    #+#             */
/*   Updated: 2024/03/26 15:38:04 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_valid_map_dimensions(t_map *map)
{
	if (map->nrows == 0 || map->ncols == 0)
	{
		ft_printf("Error: Map is empty\n");
		exit(EXIT_FAILURE);
	}
}

void	check_mlx_image_error(mlx_image_t *img)
{
	if (img == NULL)
	{
		ft_printf("Error: Image buffer allocation failed\n");
		exit(EXIT_FAILURE);
	}
}
