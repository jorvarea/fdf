/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_key_translations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:23:37 by jorvarea          #+#    #+#             */
/*   Updated: 2024/04/13 21:55:38 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	manage_key_up(t_state *state)
{
	perform_translation(state->coord_matrix, 0, TRANS_UNIT);
	mlx_delete_image(state->mlx, state->img);
	state->img = redraw_image(state->mlx, state->coord_matrix);
}

void	manage_key_down(t_state *state)
{
	perform_translation(state->coord_matrix, 0, -TRANS_UNIT);
	mlx_delete_image(state->mlx, state->img);
	state->img = redraw_image(state->mlx, state->coord_matrix);
}

void	manage_key_left(t_state *state)
{
	perform_translation(state->coord_matrix, TRANS_UNIT, 0);
	mlx_delete_image(state->mlx, state->img);
	state->img = redraw_image(state->mlx, state->coord_matrix);
}

void	manage_key_right(t_state *state)
{
	perform_translation(state->coord_matrix, -TRANS_UNIT, 0);
	mlx_delete_image(state->mlx, state->img);
	state->img = redraw_image(state->mlx, state->coord_matrix);
}
