#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/05 17:59:57 by flagoutt          #+#    #+#              #
#    Updated: 2015/03/27 13:55:23 by flagoutt         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# **************************************************************************** #
# 		PROGRAM																   #
# **************************************************************************** #
NAME		=	fractol

# **************************************************************************** #
#		SOURCES
# **************************************************************************** #

DIRSRC		=	srcs

SRCS =	$(DIRSRC)/ft_init.c \
		$(DIRSRC)/mlx_fractal_debug.c \
		$(DIRSRC)/mlx_putline.c \
		$(DIRSRC)/mlx_putpxl_img.c \
		$(DIRSRC)/mlx_create_img.c \
		$(DIRSRC)/mlx_fractal_mandelbrot.c \
		$(DIRSRC)/mlx_fractal_mandelcomplex.c \
		$(DIRSRC)/mlx_fractal_mandelbrotcube.c \
		$(DIRSRC)/mlx_fractal_mandelbar.c \
		$(DIRSRC)/mlx_fractal_burningship.c \
		$(DIRSRC)/mlx_fractal_julia.c \
		$(DIRSRC)/mlx_fractal_tree.c \
		$(DIRSRC)/mlx_fractal_hooks.c \
		$(DIRSRC)/mlx_key_hooks.c \
		$(DIRSRC)/mlx_mouse_hooks.c \
		$(DIRSRC)/mlx_paletmaker.c \
		$(DIRSRC)/which_fractal.c \
		$(DIRSRC)/mlx_getpxl_img.c \
		main.c \

# **************************************************************************** #
#		DIRECTORIES
# **************************************************************************** #

DIRBIN		=	bin
BIN			=	$(addprefix $(DIRBIN)/, $(SRCS:.c=.o))
DIRLIST		=	srcs
DIRINC		=	./includes/
DIRINC_MLX	=	./minilibx/
DIRINC_FT	=	./libft/

# **************************************************************************** #
#		COMPILE
# **************************************************************************** #

CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror
INCS		=	-I $(DIRINC) -I $(DIRINC_FT) -I $(DIRINC_MLX)
LIBS		=	-Lminilibx -lmlx -framework OpenGL -framework AppKit -Llibft/ -lft -lm

# **************************************************************************** #
#		RULES																   #
# **************************************************************************** #

all: libft $(NAME)

libft:
	@$(MAKE) -C libft

$(NAME): $(DIRBIN) $(BIN)
	@printf " ------------------------------------------------------------ \n"
	@make -C minilibx
	@$(CC) $(CFLAG) $(BIN) $(LIBS) -o $(NAME)
	@printf "\n\t\tMAKING PROJECT\t\t\t"
	@printf "\t\e[32m[DONE]\e[0m\n\n"
	@printf " ------------------------------------------------------------ \n"

$(addprefix $(DIRBIN)/, %.o) : %.c $(DIRINC) $(DIRINC_FT)
	@mkdir -p $(@D)
	@printf "compiling \e[33m%-41s\e[0m" "$@..."
	@$(CC) $(CFLAG) $(INCS) -o $@ -c $<
	@printf "\t\e[32m[DONE]\e[0m\n"

$(DIRBIN) :
	@/bin/mkdir $(DIRBIN); \
		for DIR in $(DIRLIST); \
		do \
		/bin/mkdir $(DIRBIN)/$$DIR; \
		done

clean:
	@$(MAKE) -C libft $@
	@printf " ------------------------------------------------------------ \n"
	@printf "cleaning binaries...\t\t\t\t\t"
	@/bin/rm -rf $(DIRBIN);
	@printf "\e[32m[DONE]\e[0m\n"

fclean: clean
	@$(MAKE) -C libft $@
	@printf " ------------------------------------------------------------ \n"
	@printf "cleaning project...\t\t\t\t\t"
	@/bin/rm -rf $(NAME);
	@printf "\e[32m[DONE]\e[0m\n"
	@printf " ------------------------------------------------------------ \n"

re: fclean all

.PHONY: clean fclean re libft
