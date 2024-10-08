/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:20:56 by miteixei          #+#    #+#             */
/*   Updated: 2024/10/08 18:07:21 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_args(int argc, char **argv, t_field *field)
{
	if (argc != 2)
	{
		write(2, "Incorrect format\n\n"
			"fractol [FRACTAL]\n"
			"ex. mandelbrot, julia, multibrot\n", 70);
		_shutdown(field);
	}
	if (!ft_strncmp(argv[1], "mandelbrot", 10))
		field->fractal_set = &mandelbrot;
	else if (!ft_strncmp(argv[1], "julia", 5))
		field->fractal_set = &julia;
	else if (!ft_strncmp(argv[1], "multibrot", 9))
		field->fractal_set = &multibrot;
}

int	main(int argc, char **argv)
{
	t_field	field;

	session_init(&field);
	field_init(&field);
	handle_args(argc, argv, &field);
	init_tiles(&field);
	render_fractal(&field, true);
	put_to_screen(&field);
	set_hooks(&field);
	mlx_loop(field.session);
	return (0);
}
