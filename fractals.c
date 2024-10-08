/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:22:06 by miteixei          #+#    #+#             */
/*   Updated: 2024/10/07 16:16:59 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	is_visible(t_field *field, t_tile *tile)
{
	return (_is_visible(&field->from_origin, &tile->position));
}

bool	_is_visible(t_pixel *screen_position, t_pixel *tile_position)
{
	if ((tile_position->x * TILE_SIZE
			< screen_position->x + (-WIDTH / 2)
			&& tile_position->x * TILE_SIZE + TILE_SIZE - 1
			< screen_position->x + (-WIDTH / 2))
		|| (tile_position->x * TILE_SIZE + TILE_SIZE - 1
			> screen_position->x + (WIDTH / 2) - 1
			&& tile_position->x * TILE_SIZE
			> screen_position->x + (WIDTH / 2) - 1)
		|| (tile_position->y * TILE_SIZE
			< screen_position->y + (-HEIGHT / 2)
			&& tile_position->y * TILE_SIZE + TILE_SIZE - 1
			< screen_position->y + (-HEIGHT / 2))
		|| (tile_position->y * TILE_SIZE + TILE_SIZE - 1
			> screen_position->y + (HEIGHT / 2) - 1
			&& tile_position->y * TILE_SIZE
			> screen_position->y + (HEIGHT / 2) - 1))
		return (0);
	else
		return (1);
}
