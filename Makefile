# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glecler <glecler@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/30 17:25:22 by glecler           #+#    #+#              #
#    Updated: 2020/07/27 13:46:37 by glecler          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

CC = clang
CFLAG = -Wall -Wextra -Werror

SRC_PATH	= ./srcs/
INC_PATH	= ./includes/
OBJ_PATH	= ./obj/
INC_MLX		= ./includes/minilibx_macos

LFT_PATH	= ./includes/libft/
LIBFT_FLAG	= -L$(LFT_PATH) -lft
MLX_FLAGS	= -L$(INC_MLX) -lmlx -framework OpenGL -framework Appkit
LIBFT		= $(LFT_PATH)libft.a
INCLIBFT  	= $(LFT_PATH)includes

OBJ_FILE = $(SRC_FILE:.c=.o)
SRC_FILE = 	main.c\
			parsing.c \
			parsing_check.c \
			display.c \
			event_hooks.c \
			play.c \
			raycasting.c \
			raycasting_tools.c \
			mlx_tools.c \
			img_tools.c \
			img_load.c \
			tools.c \
			error.c

OBJ      = $(addprefix $(OBJ_PATH),$(OBJ_FILE))

all: libft $(NAME)

$(NAME): $(OBJ) $(LIBFT)
		@$(CC) $(CFLAG) -lm $(LIBFT_FLAG) $(MLX_FLAGS) -o $@ $^

$(OBJ_PATH)%.o: $(SRC_PATH)%.c Makefile includes/wolf.h
		@mkdir -p $(OBJ_PATH)
		@$(CC) $(CFLAG) -I $(INC_PATH) -I $(INCLIBFT) -I $(INC_MLX) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):   $(LFT_PATH)
		@make -C $(LFT_PATH)

clean:
	@make -C $(LFT_PATH) clean
	@rm -rf $(OBJ_PATH)

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: test, all, $(NAME), clean, fclean, re
