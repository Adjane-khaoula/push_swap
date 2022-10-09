/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_sort_few_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 00:20:08 by kadjane           #+#    #+#             */
/*   Updated: 2022/10/09 00:27:22 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_element(t_data *data, t_list **stack)
{
	if ((*stack) && (*stack)->next && (*stack)->value > (*stack)->next->value)
		sa(stack, data);
}

void	sort_3_element(t_data *data, t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if ((*stack_a) && (*stack_a)->next && (*stack_a)->value > tmp->value
		&& (*stack_a)->value > (*stack_a)->next->value)
	{
		ra (stack_a, data);
		sort_2_element(data, stack_a);
	}
	else if ((*stack_a)->value < (*stack_a)->next->value
		&& (*stack_a)->next->value > (*stack_a)->next->next->value)
	{
		rra (stack_a, data);
		sort_2_element(data, stack_a);
	}
	else
		sort_2_element(data, stack_a);
}

void	sort_5_element(int *table, t_data *data,
	t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*last_value;

	last_value = *stack_a;
	tmp = *stack_a;
	while (last_value->next)
		last_value = last_value->next;
	while (tmp->value != last_value->value)
	{
		if (tmp->value == *table || tmp->value == *(table + 1))
			pb(stack_a, stack_b, data);
		else
			ra(stack_a, data);
		tmp = *stack_a;
	}
	if ((tmp->value == *table || tmp->value == *(table + 1)))
		pb(stack_a, stack_b, data);
	sort_3_element(data, stack_a);
	if ((*stack_b)->value < (*stack_b)->next->value)
		sb(stack_b, data);
	pa(stack_b, stack_a, data);
	pa(stack_b, stack_a, data);
}
