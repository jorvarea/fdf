/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:53:57 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/27 14:58:38 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	map;
	mlx_t	*window;

	check_argument_count_error(argc);
	ft_memset(&map, 0, sizeof(t_map));
	parse_map(argv[1], &map);
	window = mlx_init(1000, 1000, "Test Window", true);
	mlx_loop(window);
	mlx_terminate(window);
	free_map_memory(&map);
	return (0);
}
