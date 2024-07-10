# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeakim <jeakim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 13:21:11 by jeakim            #+#    #+#              #
#    Updated: 2024/07/10 14:45:30 by jeakim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = cub3D
LIBFT_DIR = ./libft_src/
LIBFT = -L$(LIBFT_DIR) -lft -I./libft_src

ifdef DEBUG
	COMFILE_FLAGS += -g3 -fsanitize=address
endif

SRCS = cub.c\
		parsing.c\
		ft_cub.c\
		parsing_check_util.c\
		parsing_init_type.c\
		parsing_init_map.c\
		parsing_check_map.c\
		parsing_init_user.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I./libft_src

$(NAME): $(OBJS)
	@make bonus -C $(LIBFT_DIR)
	$(CC) -o $@ $(OBJS) $(LIBFT)

clean:
	@rm -rf $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f last_bonus
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft