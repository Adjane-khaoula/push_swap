/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    instructions_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:44:04 by kadjane           #+#    #+#             */
/*   Updated: 2022/09/10 17:44:45 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list	**stack)
{
	int	data;

	if((*stack) && (*stack)->next  )
	{
		data = (*stack)->value;
		(*stack)->value = (*stack)->next->value;
		(*stack)->next->value = data; 
	}
}

void	push(t_list	**stack_1, t_list	**stack_2)
{
	t_list	*temp;
	
	if(*stack_1)
	{
		temp = *stack_1;
		add_node(stack_2,node((*stack_1)->value));
		*stack_1 = (*stack_1)->next;
		free(temp);
	}
}

void	rotate(t_list **stack)
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
	}
}

void	reverse_rotate(t_list **stack)
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
	}
}