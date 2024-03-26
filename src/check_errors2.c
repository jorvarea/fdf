/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:38:30 by jorvarea          #+#    #+#             */
/*   Updated: 2024/03/26 14:43:55 by jorvarea         ###   ########.fr       */
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
