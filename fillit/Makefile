# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anlungu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 15:41:00 by anlungu           #+#    #+#              #
#    Updated: 2017/12/18 13:24:17 by anlungu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Werror -Wextra

SRC = main.c\
	  solve.c\
	  tetrimino.c\
	  map.c\
	  read.c

LIB_DEST = ./Libft/

LIBFT = ./Libft/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C ./Libft/
	@gcc $(FLAGS) -c $(SRC)
	@gcc $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)
	@printf '\033[034mDone make rule.\n\033[0m'

clean:
	@rm -f $(OBJ)
	@make fclean -C $(LIB_DEST)
	@printf '\033[035mDone clean rule.\n\033[0m'

fclean: clean
	@rm -f $(NAME)
	@printf '\033[036mDone fclean rule.\n\033[0m'

re: fclean all
