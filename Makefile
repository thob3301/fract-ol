# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 20:31:56 by miteixei          #+#    #+#              #
#    Updated: 2024/10/08 18:15:50 by miteixei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -Ofast -g

cfiles = main.c 	 \
		events.c     \
		fractals.c   \
		init.c       \
		IO.c         \
		render.c	 \
		color.c		 \
		keyboard.c	 \
		mouse.c

ofiles = $(patsubst %.c, %.o, $(cfiles))

NAME = fractol
LIBFT = libft/libft.a
MLX = minilibx-linux/libmlx_Linux.a

$(NAME) : $(MLX) $(LIBFT) $(ofiles)
	$(CC) $(CFLAGS) $(ofiles) $(MLX) $(LIBFT) -lm -lXext -lX11 -o $(NAME)
# -lmlx -L/usr/lib	

$(LIBFT) :
	make -C ./libft

$(MLX) :
	make -C ./minilibx-linux

.PHONY : all clean fclean re bonus

all : $(NAME) clean

clean :
	rm -f $(ofiles)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

bonus : 
