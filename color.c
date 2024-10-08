/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:50:44 by miteixei          #+#    #+#             */
/*   Updated: 2024/10/08 17:34:05 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	color_picker1(unsigned int iter, t_field *field)
{
	const t_rainbow	colors = {
		0x4b369d,
		0x487de7,
		0x79c314,
		0xe81416,
		0xfaeb36,
		0xffa500};

	if (iter == DEPTH)
		return (0xcccccc);
	else
		return (colors[(iter + field->color_wheel) % 6]);
}

unsigned int	color_picker2(unsigned int iter, t_field *field)
{
	float	escape;

	if (field->black_white)
		escape = (float)1 - (float)iter / (float)field->iterations;
	else
		escape = (float)iter / (float)field->iterations;
	return ((unsigned int)(0xFF * (escape)) << 16
			| (unsigned int)(0xFF * (escape)) << 8
			| (unsigned int)(0xFF * (escape)));
}
