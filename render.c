/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:34:49 by miteixei          #+#    #+#             */
/*   Updated: 2024/10/08 17:41:56 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_fractal(t_field *field, bool render)
{
	int			i;
	t_tile		*tile;
	t_complex	c;

	tile = field->head;
	while (tile)
	{
		if (tile->visible && (render || !tile->rendered))
		{
			i = 0;
			while (i < field->tile_res)
			{
				c.real = tile->origin.real + (i % TILE_SIZE) * field->scale;
				c.imag = tile->origin.imag + (i / TILE_SIZE) * field->scale;
				((unsigned int *)tile->data)[i++]
					= field->color_picker_func(
						(field->fractal_set)(c, field), field);
			}
			tile->rendered = true;
		}
		tile = tile->next;
	}
}

unsigned int	mandelbrot(register t_complex c, t_field *field)
{
	int					i;
	register t_complex	z;
	register t_complex	z_temp;

	i = 0;
	z = (t_complex){(long double)0, (long double)0};
	while (++i < (int)field->iterations
		&& z.real * z.real + z.imag * z.imag <= 4.0)
	{
		z_temp = z;
		z.real = z_temp.real * z_temp.real - z_temp.imag * z_temp.imag;
		z.imag = 2.0 * z_temp.real * z_temp.imag;
		z.real += c.real;
		z.imag += c.imag;
	}
	return (i);
}

unsigned int	julia(register t_complex z, t_field *field)
{
	int					i;
	register t_complex	c;
	register t_complex	z_temp;

	i = 0;
	c = grid_to_complex(field->mouse.x, field->mouse.y, field);
	while (i < field->iterations && z.real * z.real + z.imag * z.imag <= 4.0)
	{
		z_temp = z;
		z.real = z_temp.real * z_temp.real - z_temp.imag * z_temp.imag;
		z.imag = 2.0 * z_temp.real * z_temp.imag;
		z.real += c.real;
		z.imag += c.imag;
		i++;
	}
	return (i);
}

unsigned int	multibrot(register t_complex c, t_field *field)
{
	int					i;
	register t_complex	z;
	register t_complex	z_temp;

	i = 0;
	z = (t_complex){0, 0};
	while (i < field->iterations && z.real * z.real + z.imag * z.imag < 4.0)
	{
		z_temp.real = z.real * z.real + z.imag * z.imag;
		z_temp.real = pow(z_temp.real, field->exponent / 2.0);
		z_temp.imag = z_temp.real;
		z_temp.real = z_temp.real
			* cos(field->exponent * atan2(z.imag, z.real)) + c.real;
		z.imag = z_temp.imag
			* sin(field->exponent * atan2(z.imag, z.real)) + c.imag;
		z.real = z_temp.real;
		i++;
	}
	return (i);
}
