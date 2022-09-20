# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 16:38:04 by kadjane           #+#    #+#              #
#    Updated: 2022/09/20 14:42:04 by kadjane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = ft_atoi.c ft_putstr.c ft_itoa.c ft_strlen.c ft_strcmp.c fun_stack_a.c fun_stack_b.c fun_stack_shared.c fun_sort_1.c fun_sort_2.c stack.c push_swap.c  
NAME := push_swap

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS := -Wall -Wextra -Werror -fsanitize=address -g

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) -o push_swap

clean : 
	@rm -f *.o
fclean : clean
	@rm -f $(NAME)
re : fclean all

# run : fclean