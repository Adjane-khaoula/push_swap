/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:30:23 by kadjane           #+#    #+#             */
/*   Updated: 2022/09/29 15:59:15 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"


void	push_in_b_hlp(int *tab,t_data *data, t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		iter;

	tmp = *stack_a;
	iter = data->nbr_node;
	while (iter-- && tmp)
	{
		if (tmp->value >= *(tab + (data->start)) && tmp->value < *(tab + data->middle))
		{
			tmp = tmp->next;
			pb(stack_a,stack_b,data);
			rb(stack_b,data);
		}
		else if (tmp->value < *(tab + (data->end)) && tmp->value >= *(tab + data->middle))
		{
			tmp = tmp->next;
			pb(stack_a,stack_b,data);
		}
		else
		{
			tmp = tmp->next;
			ra(stack_a,data);
		}
	}
}

void	push_in_b(int *table,t_data *data, t_list **stack_a, t_list **stack_b)
{
	data->middle = data->nbr_node / 2;
	data->step = 50; 
	data->start = data->middle - data->step;
	data->end = data->middle + data->step;
	while ((data->start > 0) && 
			(data->end < (data->nbr_node - 1)))
	{
		push_in_b_hlp(table, data, stack_a, stack_b);
		data->start -= data->step; 
		data->end += data->step; 
	}
	if (*stack_a)
	{
		data->start = 0;
		data->end = data->nbr_node - 1;
		push_in_b_hlp(table, data, stack_a, stack_b);
	}
}

void	push_in_a(t_data *data,t_list **stack_b, t_list **stack_a)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		last_value;

	last_value = (*stack_a)->value;
	while (*stack_b && (*stack_b)->next)
	{
		tmp1 = *stack_b;
		tmp2 = *stack_a;

		while (tmp1->next)
			tmp1 = tmp1->next;
		if ((*stack_b)->value < tmp1->value || ((*stack_b)->value > tmp1->value && (*stack_b)->value > ((*stack_b)->next)->value))
		{
			if ((*stack_b)->value < tmp1->value)
				rrb(stack_b,data);
			while (*stack_a && tmp2->next)
				tmp2 = tmp2->next;
				while (tmp2 && tmp2->value != last_value && (*stack_b)->value < tmp2->value )
				{
					rra(stack_a,data);
					tmp2 = *stack_a;
					while (*stack_a && tmp2->next)
						tmp2 = tmp2->next;
				}
				while (*stack_a && ((*stack_b)->value > (*stack_a)->value))
					ra(stack_a,data);
				pa(stack_b,stack_a,data);
		}
		else if ((*stack_b)->value < (((*stack_b)->next)->next)->value && (*stack_b)->value < ((*stack_b)->next)->value)
			rb(stack_b,data);
		else
			sb(stack_b,data);

	}
	if (!((*stack_b)->next))
		pa(stack_b,stack_a,data);
}