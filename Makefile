# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hp <hp@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 16:38:04 by kadjane           #+#    #+#              #
#    Updated: 2022/10/04 22:08:26 by hp               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = ft_itoa.c fun_help.c fun_stack_a.c fun_stack_b.c fun_stack_shared.c fun_sort_table.c\
		stack.c push_in_stack.c fun_sort_few_nbr.c push_swap.c 
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