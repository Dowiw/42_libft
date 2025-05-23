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

#Alt + Z to wrap a line for readability in VSC
C_FILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	 ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
	 ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
	 ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
	 ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c \
	 ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	 ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

O_FILES = $(C_FILES:.c=.o)

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -c $(C_FILES)
	ar rcs $(NAME) $(O_FILES)

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
