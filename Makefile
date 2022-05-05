# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 17:29:14 by plehtika          #+#    #+#              #
#    Updated: 2022/02/16 21:51:47 by plehtika         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_PATH = ./srcs/

SRCS = main read_file count_grid draw_lines keyboard_functions mouse_functions \
view_controls color_squares get_colors args_to_colors error_exit

INCLUDES = -I./includes/ -I./libft/includes/ -I/usr/local/include

LIBS = -L /usr/local/lib -L libmlx -L libft -l mlx -l ft

FRAMEWORKS = -framework OpenGL -framework Appkit

CFLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C libft
	@gcc -o $(NAME) $(patsubst %,$(SRC_PATH)%.c,$(SRCS)) $(INCLUDES) $(LIBS) \
	$(FRAMEWORKS) $(CFLAG)
	@echo "Binary file '$(NAME)' created"

clean:
	@make -C libft clean

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "Binary file '$(NAME)' deleted"

re: fclean all

.PHONY: all clean fclean re
