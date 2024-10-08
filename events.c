/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:37:13 by miteixei          #+#    #+#             */
/*   Updated: 2024/10/08 17:36:35 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_hooks(t_field *field)
{
	mlx_key_hook(field->window, &handle_key1, field);
	mlx_mouse_hook(field->window, &handle_mouse, field);
	mlx_hook(field->window, DestroyNotify, NoEventMask, &_shutdown, field);
	mlx_hook(field->window, ButtonRelease,
		ButtonReleaseMask, &click_release, field);
	mlx_hook(field->window, MotionNotify,
		PointerMotionMask, &mouse_move, field);
}

void	put_to_screen(t_field *field)
{
	t_tile	*tile;

	if (!field->render)
		return ;
	tile = field->head;
	while (tile)
	{
		if (tile->visible)
			mlx_put_image_to_window(field->session, field->window, tile->img,
				(-field->from_origin.x + WIDTH / 2
					+ tile->position.x * TILE_SIZE),
				(-field->from_origin.y + HEIGHT / 2
					+ tile->position.y * TILE_SIZE));
		tile = tile->next;
	}
	field->render = false;
}

int	_shutdown(t_field *field)
{
	free_tiles(field);
	mlx_destroy_window(field->session, field->window);
	mlx_destroy_display(field->session);
	free(field->session);
	exit(0);
}

void	free_tiles(t_field *field)
{
	t_tile	*prev;
	t_tile	*tile;

	tile = field->head;
	while (tile)
	{
		mlx_destroy_image(field->session, tile->img);
		prev = tile;
		tile = tile->next;
		free(prev);
	}
	field->head = NULL;
	field->tail = NULL;
	field->tile_n = 0;
}
