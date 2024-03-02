/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:53:57 by jorvarea          #+#    #+#             */
/*   Updated: 2024/03/02 01:47:28 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void manage_key_pressed(void* mlx)
{
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

int	main(void)
{
	mlx_t	*mlx;

	// t_map	map;
	// check_argument_count_error(argc);
	// ft_memset(&map, 0, sizeof(t_map));
	// parse_map(argv[1], &map);
	mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Fil de fer", true);
	mlx_loop_hook(mlx, manage_key_pressed, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	// free_map_memory(&map);
	return (0);
}
