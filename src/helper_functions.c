/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 02:43:03 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/25 17:33:54 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void print_map_array(t_map *map)
{
    int i;
    int j;

    i = 0;
    while (i < map->nrows)
    {
        j = 0;
        while (j < map->ncols)
        {
            ft_printf("%d ", map->data[i][j]);
            j++;
        }
        ft_printf("\n");
        i++;
    }
}

void print_colors(t_map *map)
{
    int i;

    i = 0;
    while(i < map->allocated_colors)
    {
        ft_printf("%d: 0x%X\n", i, map->color[i]);
        i++;
    }
}
