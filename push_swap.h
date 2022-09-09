/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:20:26 by kadjane           #+#    #+#             */
/*   Updated: 2022/09/09 23:34:31 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include<stdlib.h>
#include<stdio.h>
#include <unistd.h>

typedef struct	s_list
{
	int value;
	struct s_list *next;
} t_list;

int	ft_atoi(const char	*str);
char	*ft_itoa(int n);
int	ft_strlen(const char *str);
void	ft_putstr(char *str);
void	swap(t_list	**stack);
void	push(t_list	**stack_1, t_list	**stack_2);
void	add_node(t_list **stack, t_list *new_node);
t_list	*node(int a);

#endif
