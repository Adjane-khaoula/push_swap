# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 16:38:04 by kadjane           #+#    #+#              #
#    Updated: 2022/10/10 13:23:50 by kadjane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = ft_itoa.c fun_help.c fun_stack_a.c fun_stack_b.c fun_stack_shared.c fun_sort_table.c\
		fun_inverse_ra_rb.c push_in_stack_help.c stack.c push_in_stack.c fun_sort_few_nbr.c \
		push_swap.c

NAME = push_swap

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) -o push_swap
clean : 
	@rm -f *.o
fclean : clean
	@rm -f $(NAME)
re : fclean all