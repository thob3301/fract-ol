# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miteixei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 14:25:49 by miteixei          #+#    #+#              #
#    Updated: 2023/11/27 19:34:50 by miteixei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

cfiles := ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
	ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
	ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
ofiles := $(patsubst %.c,%.o,$(cfiles))

#cfiles := $(wildcard *.c)
#bcfiles := ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
#	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
#	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
#cfiles := $(filter-out $(bcfiles),$(cfiles))
#ofiles := $(patsubst %.c,%.o,$(cfiles))
#bofiles := $(patsubst %.c,%.o,$(bcfiles))

NAME = libft.a

$(NAME) : $(ofiles)
	ar rcs $(NAME) $(ofiles)

#$(ofiles) : $(cfiles) libft.h
#	$(CC) $(cflags) -c $(cfiles)

.PHONY : all clean fclean re #bonus

all : $(NAME) clean

clean :
	rm -f $(ofiles)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

#bonus : 
