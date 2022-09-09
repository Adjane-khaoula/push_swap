/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_stack_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:06:31 by kadjane           #+#    #+#             */
/*   Updated: 2022/09/09 23:46:15 by kadjane          ###   ########.fr       */
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

void	ss(t_list **stack_a, t_list **stack_b,int ac)
{
	swap(stack_a);
	swap(stack_b);
}

void	push(t_list	**stack_1, t_list	**stack_2)
{
	t_list	*temp;
	
	temp = *stack_1;
	add_node(stack_2,node((*stack_1)->value));
	*stack_1 = (*stack_1)->next;
	free(temp);
}