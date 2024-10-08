/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IO.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:53:26 by miteixei          #+#    #+#             */
/*   Updated: 2024/10/08 17:37:51 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_tiles_origin(t_field *field)
{
	t_tile	*tile;

	tile = field->head;
	while (tile)
	{
		tile->rendered = false;
		tile->origin.real = field->origin_comp.real
			+ tile->position.x * TILE_SIZE * field->scale;
		tile->origin.imag = field->origin_comp.imag
			+ tile->position.y * TILE_SIZE * field->scale;
		tile = tile->next;
	}
}

t_complex	grid_to_complex(int x, int y, t_field *field)
{
	t_complex	comp;

	comp.real = (long double)x * field->scale;
	comp.imag = (long double)y * field->scale;
	return (comp);
}

void	color_wheel_spin(t_field *field)
{
	if (field->color_wheel_flag)
		field->color_wheel++;
	if (field->color_wheel == 6)
		field->color_wheel = 0;
}

int	click_release(int button, int x, int y, t_field *field)
{
	(void)x;
	(void)y;
	if (1 == button)
		field->click = false;
	init_tiles(field);
	render_fractal(field, false);
	put_to_screen(field);
	return (1);
}

int	mouse_move(int x, int y, t_field *field)
{
	x -= WIDTH / 2;
	y -= HEIGHT / 2;
	if (field->click)
	{
		field->from_origin.x += field->mouse.x - x;
		field->from_origin.y += field->mouse.y - y;
	}
	if (!field->lock_mouse)
	{
		field->mouse.x = x;
		field->mouse.y = y;
	}
	field->render = true;
	init_tiles(field);
	if (field->fractal_set == &julia)
		render_fractal(field, true);
	else
		render_fractal(field, false);
	put_to_screen(field);
	return (1);
}
