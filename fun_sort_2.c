/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_sort_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:25:09 by kadjane           #+#    #+#             */
/*   Updated: 2022/09/20 14:26:08 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_sorted(t_list **stack,int nbr_node)
{
	t_list	*tmp;
	
	tmp = *stack;

	while (--nbr_node)
	{
		if (tmp->value > tmp->next->value)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

// void	sort_2_element(t_list **stack)
// {
// 	if ((*stack)->value > (*stack)->next->value)
// 		sa(stack);
// }

// void	sort_3_element(t_list **stack_a, t_list **stack_b)
// {
// 	t_list	*temp;

// 	temp = *stack_a;
// 	while (temp->next)
// 		temp = temp->next;
// 	if ((*stack_a)->value > temp->value)
// 		rotate (stack_a);
// 	sort_2_element(stack_a);
// 	if ((*stack_a)->next->value > (*stack_a)->next->next->value )
// 	{
// 		push(stack_a,stack_b);
// 		sort_2_element(stack_a);
// 		push(stack_b,stack_a);
// 	}
// }

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