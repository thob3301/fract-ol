/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:26:28 by miteixei          #+#    #+#             */
/*   Updated: 2024/10/08 17:36:24 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	session_init(t_field *field)
{
	field->session = mlx_init();
	field->window = mlx_new_window(field->session, WIDTH, HEIGHT, "Fract'ol");
}

void	field_init(t_field *field)
{
	mlx_clear_window(field->session, field->window);
	field->render = false;
	field->scale = (2.0 / (long double)(WIDTH / 2));
	field->origin_comp = (t_complex){0, 0};
	field->from_origin = (t_pixel){0, 0};
	field->iterations = DEPTH;
	field->exponent = 3.0;
	field->black_white = false;
	field->mouse = (t_pixel){0, 0};
	field->lock_mouse = false;
	field->click = false;
	mlx_mouse_get_pos(field->session, field->window,
		&field->mouse.x, &field->mouse.y);
	field->color_wheel = 0;
	field->color_wheel_flag = false;
	field->fractal_set = &mandelbrot;
	field->color_picker_func = &color_picker2;
	field->head = NULL;
	field->tail = NULL;
	field->tile_n = 0;
	field->tile_res = TILE_SIZE * TILE_SIZE;
}

t_tile	*is_tile(t_field *field, int x, int y)
{
	t_tile	*tile;

	tile = field->head;
	while (tile)
	{
		if (tile->position.x == x && tile->position.y == y)
			return (tile);
		else
			tile = tile->next;
	}
	return (NULL);
}

void	add_tile(t_field *field, int x, int y)
{
	t_tile	*tile;

	tile = is_tile(field, x, y);
	if (tile)
	{
		tile->visible = is_visible(field, tile);
		render_fractal(field, false);
		return ;
	}
	tile = malloc(sizeof(t_tile));
	tile->img = mlx_new_image(field->session, TILE_SIZE, TILE_SIZE);
	tile->data = tile->img->data;
	tile->position.x = x;
	tile->position.y = y;
	tile->origin = grid_to_complex(x * TILE_SIZE, y * TILE_SIZE, field);
	tile->visible = is_visible(field, tile);
	tile->rendered = false;
	tile->next = NULL;
	if (!field->head)
		field->head = tile;
	else
		field->tail->next = tile;
	field->tail = tile;
	field->tile_n++;
}

// double check this
void	init_tiles(t_field *field)
{
	t_pixel	top_left;
	t_pixel	bottom_right;
	t_pixel	tile_position;

	top_left.x = (field->from_origin.x - (WIDTH / 2)) / TILE_SIZE - 1;
	top_left.y = (field->from_origin.y - (HEIGHT / 2)) / TILE_SIZE - 1;
	bottom_right.x = (field->from_origin.x + (WIDTH / 2 - 1)) / TILE_SIZE + 1;
	bottom_right.y = (field->from_origin.y + (HEIGHT / 2 - 1)) / TILE_SIZE + 1;
	tile_position = top_left;
	while (1)
	{
		while (1)
		{
			add_tile(field, tile_position.x, tile_position.y);
			tile_position.x++;
			if (tile_position.x == bottom_right.x)
				break ;
		}
		if (tile_position.x == bottom_right.x
			&& tile_position.y == bottom_right.y)
			break ;
		tile_position.x = top_left.x;
		tile_position.y++;
	}
}
