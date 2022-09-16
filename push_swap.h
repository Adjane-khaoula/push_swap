/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:20:26 by kadjane           #+#    #+#             */
/*   Updated: 2022/09/16 18:03:21 by kadjane          ###   ########.fr       */
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

typedef struct	s_data
{
	int	nbr_node;
	int	middle;
	int	step;
} t_data;

int		ft_atoi(const char	*str);
char	*ft_itoa(int n);
int		ft_strlen(const char *str);
void	ft_putstr(char *str);

void	add_node(t_list **stack, t_list *new_node);
t_list	*node(int a);
void	print_stack(t_list *stack);

void	sa(t_list	**stack);
void	pa(t_list	**stack_1, t_list	**stack_2);
void	ra(t_list **stack);
void	rra(t_list **stack);

void	sb(t_list	**stack);
void	pb(t_list	**stack_1, t_list	**stack_2);
void	rb(t_list **stack);
void	rrb(t_list **stack);

void	ss(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

int		*sort_stack_in_table(t_list	*stack_a, int nbr_node);
int		table_is_sorted(int **table, int nbr_node);
void	swap_element(int **tab, int nbr_node);
int		stack_is_sorted(t_list **stack,int nbr_node);
void	push_in_b(int *table,t_data *data, t_list **stack_a, t_list **stack_b);


void	sort_2_element(t_list **stack);
void	sort_3_element(t_list **stack_a, t_list **stack_b);
void	sort_4_element(t_list **stack_a, t_list **stack_b);
void	sort_5_element(t_list **stack_a, t_list **stack_b);

#endif
