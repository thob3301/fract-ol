/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:05:21 by miteixei          #+#    #+#             */
/*   Updated: 2024/10/08 17:32:28 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	button1(int x, int y, t_field *field)
{
	if (field->click)
	{
		field->from_origin.x -= field->mouse.x - x;
		field->from_origin.y -= field->mouse.y - y;
	}
	field->click = true;
}

static void	button4(int x, int y, t_field *field)
{
	t_complex	comp;
	t_complex	comp_scaled;

	color_wheel_spin(field);
	comp = grid_to_complex(field->from_origin.x + x,
			field->from_origin.y + y, field);
	field->scale /= SCALE;
	comp_scaled = grid_to_complex(field->from_origin.x + x,
			field->from_origin.y + y, field);
	field->origin_comp.real += comp.real - comp_scaled.real;
	field->origin_comp.imag += comp.imag - comp_scaled.imag;
	if (field->fractal_set == &mandelbrot)
		field->iterations += 0.5;
}

static void	button5(int x, int y, t_field *field)
{
	t_complex	comp;
	t_complex	comp_scaled;

	color_wheel_spin(field);
	comp = grid_to_complex(field->from_origin.x + x,
			field->from_origin.y + y, field);
	field->scale *= SCALE;
	comp_scaled = grid_to_complex(field->from_origin.x + x,
			field->from_origin.y + y, field);
	field->origin_comp.real += comp.real - comp_scaled.real;
	field->origin_comp.imag += comp.imag - comp_scaled.imag;
	if (field->fractal_set == &mandelbrot)
		field->iterations -= 0.5;
}

int	handle_mouse(int button, int x, int y, t_field *field)
{
	x -= (WIDTH / 2);
	y -= (HEIGHT / 2);
	if (1 == button)
		button1(x, y, field);
	else if (4 == button)
		button4(x, y, field);
	else if (5 == button)
		button5(x, y, field);
	else
		return (0);
	if (button == 4 || button == 5)
		free_tiles(field);
	field->render = true;
	init_tiles(field);
	move_tiles_origin(field);
	if (button == 4 || button == 5)
		render_fractal(field, true);
	else
		render_fractal(field, false);
	put_to_screen(field);
	return (1);
}
