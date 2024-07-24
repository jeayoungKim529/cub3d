# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 13:21:11 by jeakim            #+#    #+#              #
#    Updated: 2024/07/24 21:05:24 by jimchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

NAME = cub3D
LIBFT_DIR = ./libft_src/
LIBFT = -L$(LIBFT_DIR) -lft -I./libft_src
MLXDIR = ./minilibx_mms_20210621
MLXFLAG = -L $(MLXDIR) -lmlx -L $(LIBFT_DIR) -lft -framework OpenGL -framework AppKit
LIBMLXDIR = ./minilibx_mms_20210621

ifdef DEBUG
	CFLAGS += -g3 -fsanitize=address
endif

SRCS =	src/cub.c\
		src/parsing.c\
		src/ft_cub.c\
		src/parsing_check_util.c\
		src/parsing_init_type.c\
		src/parsing_init_map.c\
		src/parsing_check_map.c\
		src/parsing_init_user.c\
		\
		\
		src/exec.c \
		src/exec_init.c \
		src/exec_direction.c\
		src/exec_key_handling.c \
		src/exec_image.c \
		src/exec_move.c \
		src/exec_raycast.c \
		src/exec_dda.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I./libft_src

$(NAME): $(OBJS)
	@make bonus -C $(LIBFT_DIR)
	make -s -C $(MLXDIR)
	cp ./$(MLXDIR)/libmlx.dylib ./libmlx.dylib
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAG) -o $(NAME)
# $(CC) -o $@ $(OBJS) $(LIBFT)


clean:
	@rm -rf $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLXDIR) clean

fclean: clean
	@rm -f libmlx.dylib
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft