# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jimchoi <jimchoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 13:21:11 by jeakim            #+#    #+#              #
#    Updated: 2024/07/12 18:49:05 by jimchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS =
#  -Wall -Werror -Wextra

NAME = cub3D
LIBFT_DIR = ./libft_src/
LIBFT = -L$(LIBFT_DIR) -lft -I./libft_src
MLXDIR = ./minilibx_mms_20210621
MLXFLAG = -L $(MLXDIR) -lmlx -L $(LIBFT_DIR) -lft -framework OpenGL -framework AppKit
LIBMLXDIR = ./minilibx_mms_20210621

ifdef DEBUG
	CFLAGS += -g3 -fsanitize=address
endif

SRCS = cub.c\
		parsing.c\
		ft_cub.c\
		parsing_check_util.c\
		parsing_init_type.c\
		parsing_init_map.c\
		parsing_check_map.c\
		parsing_init_user.c\
		\
		\
		exec.c \
		# exec_move.c \
		# exec_key_handling.c \
		# exec_image.c \
		# exec_utils.c \


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