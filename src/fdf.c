/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:53:57 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/25 17:32:01 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void check_argument_count(int argc)
{
    if (argc != 2)
    {
        ft_printf("Error: Wrong argument count\n");
        exit(1);
    }
}

int main(int argc, char **argv)
{
    t_map map;
    
    check_argument_count(argc);
    ft_memset(&map, 0, sizeof(t_map));
    parse_map(argv[1], &map);
    print_map_array(&map);
    print_colors(&map);
    free_map_memory(&map);
    return (0);
}
