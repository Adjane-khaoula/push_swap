/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_stack_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:51:51 by kadjane           #+#    #+#             */
/*   Updated: 2022/09/17 11:40:35 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list	**stack)
{
	int	data;

	if((*stack) && (*stack)->next  )
	{
		data = (*stack)->value;
		(*stack)->value = (*stack)->next->value;
		(*stack)->next->value = data;
		write(1,"sa\n",3); 
	}
}

void	pa(t_list	**stack_1, t_list	**stack_2)
{
	t_list	*temp;
	
	if(*stack_1)
	{
		temp = *stack_1;
		add_node(stack_2,node((*stack_1)->value));
		*stack_1 = (*stack_1)->next;
		free(temp);
		write(1,"pa\n",3);
	}
}


void	ra(t_list **stack)
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
		write(1,"ra\n",3);
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
		write(1,"rra\n",4);
	}
}