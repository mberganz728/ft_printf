# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberganz <mberganz@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 16:03:07 by mberganz          #+#    #+#              #
#    Updated: 2023/05/04 14:29:12 by mberganz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c print_char.c print_str.c print_nbr.c print_uns.c print_hexu.c print_hexl.c print_ptr.c

NAME = libftprintf.a
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re
