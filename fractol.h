/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:26:33 by miteixei          #+#    #+#             */
/*   Updated: 2024/10/08 18:17:49 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TILE_SIZE 100
#define WIDTH 400
#define HEIGHT 400
#define SCALE 1.1
#define DEPTH 50

#include <stdint.h>
#include <math.h>
#include <stdbool.h>
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include <X11/keysymdef.h>
//#define XK_Escape 0xff1b
//#define XK_Left 0xff51
//#define XK_Up 0xff52
//#define XK_Right 0xff53
//#define XK_Down 0xff54
//#define XK_Pointer_Button1 0xfee9
//#define XK_Pointer_Button2 0xfeea
//#define XK_Pointer_Button3 0xfeeb
//#define XK_Pointer_Button4 0xfeec
//#define XK_Pointer_Button5 0xfeed

typedef const unsigned int	t_rainbow[6];

typedef struct s_complex
{
	long double	real;
	long double	imag;
}			t_complex;

typedef struct s_pixel
{
	int	x;
	int	y;
}		t_pixel;

typedef struct s_field
{
	void			*session;
	void			*window;
	bool			render;
	long double		scale;
	t_complex		origin_comp;
	t_pixel			from_origin;
	float			iterations;
	long double		exponent;
	bool			black_white;
	t_pixel			mouse;
	bool			lock_mouse;
	bool			click;
	int				color_wheel;
	int				color_wheel_flag;
	unsigned int	(*fractal_set)(struct s_complex, struct s_field *);
	unsigned int	(*color_picker_func)(unsigned int iter,
			struct s_field *field);
	struct s_tile	*head;
	struct s_tile	*tail;
	int				tile_n;
	int				tile_res;
}					t_field;

typedef struct s_tile
{
	t_img			*img;
	char			*data;
	struct s_pixel	position;
	t_complex		origin;
	bool			visible;
	bool			rendered;
	struct s_tile	*next;
}					t_tile;

// init.c
void			session_init(t_field *field);
void			field_init(t_field *field);
void			add_tile(t_field *field, int x, int y);
void			border(t_pixel screen_position,
					t_pixel *top_left, t_pixel *bottom_right);
void			init_tiles(t_field *field);
void			free_tiles(t_field *field);
// events.c
void			set_hooks(t_field *field);
void			put_to_screen(t_field *field);
int				_shutdown(t_field *field);
void			free_tiles(t_field *field);
// render.c
void			render_fractal(t_field *field, bool render);
unsigned int	mandelbrot(register t_complex c, t_field *field);
unsigned int	julia(register t_complex c, t_field *field);
unsigned int	multibrot(t_complex c, t_field *field);
// IO.c
void			move_tiles_origin(t_field *field);
t_complex		grid_to_complex(int x, int y, t_field *field);
void			color_wheel_spin(t_field *field);
int				click_release(int button, int x, int y, t_field *field);
int				mouse_move(int x, int y, t_field *field);
// fractals.c
bool			is_visible(t_field *field, t_tile *tile);
bool			_is_visible(t_pixel *screen_position, t_pixel *tile_position);
// color.c
unsigned int	color_picker1(unsigned int iter, t_field *field);
unsigned int	color_picker2(unsigned int iter, t_field *field);
// keyboard.c
int				handle_key1(int keycode, t_field *field);
// mouse.c
int				handle_mouse(int button, int x, int y, t_field *field);
