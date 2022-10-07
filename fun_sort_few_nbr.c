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

void	sort_5_element(t_data *data, t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		last_value;

	pb(stack_a, stack_b, data);
	pb(stack_a, stack_b, data);
	sort_3_element(data, stack_a);
	tmp = *stack_a;
	while (tmp->next)
		tmp = tmp->next;
	last_value = tmp->value;
	while((*stack_b))
	{
		tmp = *stack_a;
		while (tmp->next)
			tmp = tmp->next;
		if ((*stack_b)->value > tmp->value)
		{
			pb(stack_b, stack_a, data);
			ra(stack_a, data);
			last_value = tmp->next->value;
		}
		else if ((*stack_b)->value > (*stack_a)->value)
		{
			while((*stack_b)->value > (*stack_a)->value)
			{
				ra(stack_a, data);
				tmp = tmp->next;
			}
			pb(stack_b, stack_a, data);
		}
		else
		{
			while((*stack_b)->value < tmp->value && tmp->value != last_value)
			{
				rra(stack_a, data);
				tmp = *stack_a;
				while (tmp->next)
					tmp = tmp->next;
			}
			pb(stack_b, stack_a, data);
		}
	}
	while (tmp->value !=last_value)
	{
		rra(stack_a, data);
		tmp = *stack_a;
		while (tmp->next)
			tmp = tmp->next;
	}
}
