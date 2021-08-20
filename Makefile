# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abambi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/09 15:52:51 by abambi            #+#    #+#              #
#    Updated: 2021/01/25 11:04:54 by abambi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =  printf.c read_flags.c printf_lib.c printf_utils.c \
print_csp.c print_dixxu.c nllhh.c

OBJS = $(SRCS:.c=.o)

HEADER = ft_printf.h

INC_DIR = .

CC = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	ar rc $@ $^
	ranlib $@

bonus: $(OBJS) $(HEADER)
	ar -rcs $(NAME) $(OBJS)	

.c.o:  
	$(CC) $(FLAGS) -o ${<:.c=.o} -c $< -I$(INC_DIR)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
