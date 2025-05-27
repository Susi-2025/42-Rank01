# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vinguyen <vinguyen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/21 15:42:59 by vinguyen          #+#    #+#              #
#    Updated: 2025/05/26 12:28:41 by vinguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_putchar.c ft_putnbr_base.c ft_putptr.c ft_putstr.c ft_putnbr_base_unsigned.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a
LIBC = ar rcs
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

.c .o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
