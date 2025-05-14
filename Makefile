# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmonjard <kmonjard@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/12 11:40:15 by kmonjard          #+#    #+#              #
#    Updated: 2025/05/12 11:40:17 by kmonjard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC_DIR = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
INC_DIR = includes

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -c $(SRC_DIR) -I$(INC_DIR)
	ar rc $(NAME) *.o

clean:
	rm -f *.o
	rm -f $(INC_DIR)*.*.gch

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
