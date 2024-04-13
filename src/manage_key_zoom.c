/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_key_zoom.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:51:47 by jorvarea          #+#    #+#             */
/*   Updated: 2024/04/13 22:45:54 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	manage_zoom_in(t_state *state)
{
	t_point		focus;
	mlx_image_t	*img;
	t_point		**m;
	int			nrows;
	int			ncols;

	img = state->img;
	nrows = state->coord_matrix->nrows;
	ncols = state->coord_matrix->ncols;
	m = state->coord_matrix->m;
	focus.xyz[0] = m[nrows / 2][ncols / 2].xyz[0] + (img->width / 2 - m[nrows
			/ 2][ncols / 2].xyz[0]);
	focus.xyz[1] = m[nrows / 2][ncols / 2].xyz[1] + (img->height / 2 - m[nrows
			/ 2][ncols / 2].xyz[1]);
	perform_zoom(state->coord_matrix, ZOOM_FACTOR, &focus);
	mlx_delete_image(state->mlx, state->img);
	state->img = redraw_image(state->mlx, state->coord_matrix);
}

void	manage_zoom_out(t_state *state)
{
	t_point		focus;
	mlx_image_t	*img;
	t_point		**m;
	int			nrows;
	int			ncols;

	img = state->img;
	nrows = state->coord_matrix->nrows;
	ncols = state->coord_matrix->ncols;
	m = state->coord_matrix->m;
	focus.xyz[0] = m[nrows / 2][ncols / 2].xyz[0] + (img->width / 2 - m[nrows
			/ 2][ncols / 2].xyz[0]);
	focus.xyz[1] = m[nrows / 2][ncols / 2].xyz[1] + (img->height / 2 - m[nrows
			/ 2][ncols / 2].xyz[1]);
	perform_zoom(state->coord_matrix, 1.0 / ZOOM_FACTOR, &focus);
	mlx_delete_image(state->mlx, state->img);
	state->img = redraw_image(state->mlx, state->coord_matrix);
}
