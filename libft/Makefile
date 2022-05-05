# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 13:22:32 by plehtika          #+#    #+#              #
#    Updated: 2022/02/14 19:10:09 by plehtika         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_PATH = ./srcs/

ADDONS_PATH = ./srcs/addons/

INCLUDES = -I./includes/

SRCS = memset bzero memcpy memccpy memmove memchr memcmp strlen strdup strcpy \
strncpy strcat strncat strlcat strchr strrchr strstr strnstr strcmp strncmp \
atoi isalpha isdigit isalnum isascii isprint toupper tolower \
memalloc memdel strnew strdel strclr striter striteri strmap strmapi strequ \
strnequ strsub strjoin strtrim strsplit itoa putchar putstr putendl putnbr \
putchar_fd putstr_fd putendl_fd putnbr_fd lstnew lstdelone lstdel lstadd \
lstiter lstmap

ADDONS = ft_lstappend ft_strstretch ft_delarray get_next_line ft_word_counter \
ft_del2darray ft_del3darray ft_abs_int ft_abs_double rgb_to_int ft_min ft_max

CFLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc -c $(patsubst %,$(SRC_PATH)ft_%.c,$(SRCS)) \
	$(patsubst %,$(ADDONS_PATH)%.c,$(ADDONS)) $(INCLUDES) $(CFLAG)
	@echo "Libft object files created"
	@ar -rcs $(NAME) $(patsubst %,ft_%.o,$(SRCS)) $(patsubst %,%.o,$(ADDONS))
	@echo "Library '$(NAME)' created"

clean:
	@rm -f $(patsubst %,./ft_%.o,$(SRCS)) $(patsubst %,./%.o,$(ADDONS))
	@echo "Libft object files deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "Library '$(NAME)' deleted"

re: fclean all

.PHONY: all clean fclean re
