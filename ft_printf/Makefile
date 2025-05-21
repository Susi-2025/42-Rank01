# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vinguyen <vinguyen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/21 15:42:59 by vinguyen          #+#    #+#              #
#    Updated: 2025/05/21 16:51:00 by vinguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c

OBJS = $(SRCS: .c=.o)

NAME = libftprintf.a
LIBC = ar
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = ft_printf.c

OBJS = $(SRCS: .c=.o)

NAME = libftprintf.a
LIBC = ar
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

.PHONY: all clean
