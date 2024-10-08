/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:54:09 by miteixei          #+#    #+#             */
/*   Updated: 2024/10/08 17:38:05 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	handle_key_exit(t_field *field)
{
	field->render = true;
	init_tiles(field);
	if (field->fractal_set == &multibrot)
		render_fractal(field, true);
	render_fractal(field, false);
	put_to_screen(field);
	return (1);
}

static int	handle_key3(int keycode, t_field *field)
{
	if (XK_minus == keycode)
	{
		field->exponent -= 0.25;
		if (field->exponent == 0)
			field->exponent = 0.25;
	}
	else if (XK_equal == keycode)
		field->exponent += 0.25;
	else if (XK_c == keycode)
		field->color_wheel_flag = !field->color_wheel_flag;
	else if (XK_b == keycode)
	{
		if (field->color_picker_func == color_picker1)
			field->color_picker_func = color_picker2;
		else
			field->color_picker_func = color_picker1;
	}
	else if (XK_slash == keycode)
		field->black_white = !field->black_white;
	else if (XK_Escape == keycode)
		_shutdown(field);
	return (handle_key_exit(field));
}

static int	handle_key2(int keycode, t_field *field)
{
	if (XK_j == keycode)
	{
		if (field->fractal_set == &julia)
			return (1);
		free_tiles(field);
		field_init(field);
		field->fractal_set = &julia;
	}
	else if (XK_k == keycode)
	{
		if (field->fractal_set == &multibrot)
			return (1);
		free_tiles(field);
		field_init(field);
		field->fractal_set = &multibrot;
	}
	else if (XK_l == keycode)
		field->lock_mouse = !field->lock_mouse;
	else
		return (handle_key3(keycode, field));
	return (handle_key_exit(field));
}

int	handle_key1(int keycode, t_field *field)
{
	if (XK_Left == keycode)
		field->from_origin.x -= (WIDTH / 10);
	else if (XK_Right == keycode)
		field->from_origin.x += (WIDTH / 10);
	else if (XK_Up == keycode)
		field->from_origin.y -= (WIDTH / 10);
	else if (XK_Down == keycode)
		field->from_origin.y += (WIDTH / 10);
	else if (XK_m == keycode)
	{
		if (field->fractal_set == &mandelbrot)
			return (1);
		free_tiles(field);
		field_init(field);
		field->fractal_set = &mandelbrot;
	}
	else
		return (handle_key2(keycode, field));
	return (handle_key_exit(field));
}
