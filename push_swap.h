/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:20:26 by kadjane           #+#    #+#             */
/*   Updated: 2022/09/11 17:07:14 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

typedef struct	s_list
{
	int value;
	struct s_list *next;
} t_list;

int		ft_atoi(const char	*str);
char	*ft_itoa(int n);
int		ft_strlen(const char *str);
void	ft_putstr(char *str);

void	add_node(t_list **stack, t_list *new_node);
t_list	*node(int a);
void	print_stack(t_list *stack);

void	swap(t_list	**stack);
void	ss(t_list **stack_a, t_list **stack_b);
void	push(t_list	**stack_1, t_list	**stack_2);
void	rotate(t_list **stack);
void	rr(t_list **stack_a, t_list **stack_b);
void	reverse_rotate(t_list **stack);
void	sort_2_element(t_list **stack);
void	sort_3_element(t_list **stack_a, t_list **stack_b);
void	sort_4_element(t_list **stack_a, t_list **stack_b);
void	sort_5_element(t_list **stack_a, t_list **stack_b);

#endif
