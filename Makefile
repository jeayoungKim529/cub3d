# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jimchoi <jimchoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 13:21:11 by jeakim            #+#    #+#              #
#    Updated: 2024/07/10 13:43:30 by jimchoi          ###   ########.fr        #
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
	COMFILE_FLAGS += -g3 -fsanitize=address
endif

SRCS = test.c
# cub.c\
# 		parsing.c\
# 		parsing_init_type.c\
# 		parsing_init_map.c\
# 		parsing_check.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I./libft_src

$(NAME): $(OBJS)
	@make bonus -C $(LIBFT_DIR)
	make -s -C $(MLXDIR)
	cp ./$(MLXDIR)/libmlx.dylib ./libmlx.dylib
	$(CC) $(CFLAG) $(OBJS) $(LIBFT) $(MLXFLAG) -o $(NAME)
# $(CC) -o $@ $(OBJS) $(LIBFT)
clean:
	@rm -rf $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f last_bonus
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft

# CC = cc
# CFLAG = -Wall -Wextra -Werror
# NAME = fdf
# LIBFT_DIR = ./libft/
# LIBFT_NAME = libft.a
# SRCS = fdf_main.c fdf_parsing.c fdf_bresenham.c fdf_draw_map.c 
# OBJS = $(SRCS:.c=.o)
# MLXDIR = ./minilibx_mms_20210621
# MLXFLAG = -L $(MLXDIR) -lmlx -L $(LIBFT_DIR) -lft -framework OpenGL -framework AppKit
# LIBMLXDIR = ./minilibx_mms_20210621

# .PHONY: all

# all: $(NAME)

# $(NAME): $(OBJS) fdf.h
# 	make -s -C $(LIBFT_DIR)
# 	make -s -C $(MLXDIR)
# 	cp ./$(MLXDIR)/libmlx.dylib ./libmlx.dylib
# 	$(CC) $(CFLAG) $(OBJS) $(MLXFLAG) -o $(NAME)

# $(OBJS)	: $(SRCS) 
# 	$(CC) $(CFLAG) -c $^

# clean:
# 	make -C $(LIBFT_DIR) clean
# 	make -C $(MLXDIR) clean
# 	rm -f $(OBJS)

# fclean: clean
# 	make -C $(LIBFT_DIR) fclean
# 	rm -f $(NAME)
# 	rm -f libmlx.dylib

# re: fclean all

# .PHONY: all clean fclean re
