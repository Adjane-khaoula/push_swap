# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 16:38:04 by kadjane           #+#    #+#              #
#    Updated: 2022/09/11 11:38:27 by kadjane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = ft_atoi.c ft_putstr.c ft_itoa.c ft_strlen.c  instructions_1.c instructions_2.c fun_sort.c stack.c frctpush_swap.c  
NAME := push_swap

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS := -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) -o push_swap

clean : 
	@rm -f *.o
fclean : clean
	@rm -f $(NAME)
re : fclean all

run : all
	./push_swap 1 2 3 4 5 123
