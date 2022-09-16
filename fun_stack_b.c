/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_stack_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:44:04 by kadjane           #+#    #+#             */
/*   Updated: 2022/09/16 19:14:42 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list	**stack)
{
	int	data;

	if((*stack) && (*stack)->next  )
	{
		data = (*stack)->value;
		(*stack)->value = (*stack)->next->value;
		(*stack)->next->value = data;
		write(1,"sb\n",3);
	}
}

void	pb(t_list	**stack_a, t_list	**stack_b)
{
	t_list	*temp;
	
	if(*stack_a)
	{
		temp = *stack_a;
		add_node(stack_b,node((*stack_a)->value));
		*stack_a = (*stack_a)->next;
		free(temp);
		write(1,"pb\n",3);
	}
}

void	rb(t_list **stack)
{
	t_list	*temp_1;
	t_list	*temp_2;
	t_list	*first_node;
	
	temp_1 = *stack;
	temp_2 = *stack;
	
	if(stack && (*stack)->next)
	{
		first_node = node((*stack)->value);
		while(temp_1->next)
			temp_1 = temp_1->next;
		temp_1->next = first_node;
		*stack = (*stack)->next;
		free(temp_2);
		write(1,"rb\n",3);
	}
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
		write(1,"rrb\n",4);
	}
}