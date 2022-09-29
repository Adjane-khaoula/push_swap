/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_sort_few_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:25:09 by kadjane           #+#    #+#             */
/*   Updated: 2022/09/20 14:26:08 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_element(t_data *data, t_list **stack)
{
	if ((*stack) && (*stack)->next && (*stack)->value > (*stack)->next->value)
		sa(stack,data);
}

void	sort_3_element(t_data *data, t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if ((*stack_a)->value > (*stack_a)->next->value && (*stack_a)->value > tmp->value)
	{
		ra (stack_a,data);
		sort_2_element(data, stack_a);
	}
	else if ((*stack_a)->value < (*stack_a)->next->value &&
				 (*stack_a)->next->value > (*stack_a)->next->next->value)
		{
			rra (stack_a, data);
			sort_2_element(data, stack_a);
		}
	else 
		sort_2_element(data, stack_a);
}

// void	sort_4_element(t_list **stack_a, t_list **stack_b)
// {
// 	push(stack_a,stack_b);
// 	sort_3_element(stack_a, stack_b);
// 	push(stack_b,stack_a);
// 	if ((*stack_a)->value > (*stack_a)->next->value)
// 	{
// 		swap(stack_a);
// 		push(stack_a,stack_b);
// 		sort_3_element(stack_a, stack_b);
// 		push(stack_b,stack_a);
// 	}
// }

// void	push_in_b(t_list **stack_a, t_list **stack_b)
// {
// 	t_list	*temp;
	
// 	temp = NULL;
	
// }