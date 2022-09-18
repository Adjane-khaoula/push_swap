/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:43:55 by kadjane           #+#    #+#             */
/*   Updated: 2022/09/18 19:00:34 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list **stack_a, t_list **stack_b,t_data *data)
{
	sa(stack_a,data);
	sb(stack_b,data);
	ft_putstr("ss"); 
}

void	rr(t_list **stack_a, t_list **stack_b,t_data *data)
{
	ra(stack_a, data);
	rb(stack_b, data);
	ft_putstr("rr");
}

void	rrr(t_list **stack_a, t_list **stack_b,t_data *data)
{
	rra(stack_a,data);
	rrb(stack_b,data);
	ft_putstr("rrr");
}


void	rrb(t_list **stack)
{
	t_list	**temp;
	t_list	*end_node;
	
	temp = stack;
	
	if(stack && (*stack)->next)
	{
		while((*temp)->next)
			temp = &(*temp)->next;
		end_node = node((*temp)->value);
		end_node->next = *stack;
		*stack = end_node;
		free(*temp);
		*temp = NULL;
		ft_putstr("rrb");
	}
}

void	rra(t_list **stack)
{
	t_list	**temp;
	t_list	*end_node;
	
	temp = stack;
	
	if(stack && (*stack)->next)
	{
		while((*temp)->next)
			temp = &(*temp)->next;
		end_node = node((*temp)->value);
		end_node->next = *stack;
		*stack = end_node;
		free(*temp);
		*temp = NULL;
		ft_putstr("rra");
	}
}