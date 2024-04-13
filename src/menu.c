/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 00:37:30 by jorvarea          #+#    #+#             */
/*   Updated: 2024/04/13 22:57:01 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_menu(mlx_t *mlx)
{
	int	y;

	y = 0;
	mlx_put_string(mlx, "Press 'ESC' to close", 50, y += 35);
	mlx_put_string(mlx, "Zoom: press '-' or '+'", 50, y += 35);
	mlx_put_string(mlx, "Move: press arrow keys", 50, y += 20);
	mlx_put_string(mlx, "Rotate X: press 'A' or 'Z'", 50, y += 20);
	mlx_put_string(mlx, "Rotate Y: press 'S' or 'X'", 50, y += 20);
	mlx_put_string(mlx, "Rotate Z: press 'D' or 'Z'", 50, y += 20);
	mlx_put_string(mlx, "To change projection view:", 50, y += 35);
	mlx_put_string(mlx, "Isometric: press '1'", 50, y += 20);
	mlx_put_string(mlx, "Perspective: press '2'", 50, y += 20);
	mlx_put_string(mlx, "Colors: press 'SPACE'", 50, y += 35);
	mlx_put_string(mlx, "Reset view: press 'R'", 50, y += 35);
}
