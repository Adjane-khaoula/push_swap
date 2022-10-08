/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:20:26 by kadjane           #+#    #+#             */
/*   Updated: 2022/10/08 18:31:37 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_list
{
	int				value;
	char			*out;
	struct s_list	*next;
} t_list;

typedef struct	s_data
{
	int		nbr_node;
	int		middle;
	int		step;
	int		start;
	int		end;
	t_list	*output;

} t_data;

int		ft_atoi(char *str);
void	ft_error();
char	*ft_itoa(int n);
int		ft_strlen(const char *str);
void	ft_putstr(char *str);
int		ft_strcmp(const char *s1, const char *s2);

void	add_node(t_list **stack, t_list *new_node);
t_list	*node(int a);
void	print_stack(t_list *stack);
t_list	*node_store(char *output);

void	sa(t_list	**stack,t_data *data);
void	sa_help(t_data *data);
void	pa(t_list	**stack_1, t_list	**stack_2,t_data *data);
void	ra(t_list **stack,t_data *data);
void	ra_help(t_data *data);
void	rra(t_list **stack, t_data *data);

void	sb(t_list	**stack,t_data *data);
void	sb_help(t_data *data);
void	pb(t_list	**stack_a, t_list	**stack_b,t_data *data);
void	rb(t_list **stack,t_data *data);
void	rb_help(t_data *data);
void	rrb(t_list **stack,t_data *data);

void	ss (t_list **stack_a, t_list **stack_b,t_data *data);
void	rr(t_list **stack_a, t_list **stack_b,t_data *data);
void	rrr(t_data *data, t_list **stack_a, t_list **stack_b);

int		*sort_stack_in_table(t_list	*stack_a, int nbr_node);
int		table_is_sorted(int **table, int nbr_node);
void	swap_element(int **tab, int nbr_node);
int		stack_is_sorted(t_list **stack,int nbr_node);
void	push_in_b(int *table,t_data *data, t_list **stack_a, t_list **stack_b);
void	push_in_b_hlp(int *tab,t_data *data, t_list **stack_a, t_list **stack_b);
void	push_in_a(int *table, t_data *data,t_list **stack_b, t_list **stack_a);


void	sort_2_element(t_data *data, t_list **stack);
void	sort_3_element(t_data *data, t_list **stack_a);
void	sort_5_element(int *table, t_data *data, t_list **stack_a, t_list **stack_b);

#endif
