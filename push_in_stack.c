/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:37:59 by kadjane           #+#    #+#             */
/*   Updated: 2022/10/09 02:17:39 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	push_in_b_2(int *tab, t_data *data, t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_a;
	data->iter = data->nbr_node;
	while (data->iter-- && tmp && tmp->next)
	{
		if (tmp->value >= *(tab + (data->start))
			&& tmp->value < *(tab + data->middle))
		{
			tmp = tmp->next;
			pb(stack_a, stack_b, data);
			rb(stack_b, data);
		}
		else if (tmp->value < *(tab + ((data->end)))
			&& tmp->value >= *(tab + data->middle))
		{
			tmp = tmp->next;
			pb(stack_a, stack_b, data);
		}
		else
		{
			tmp = tmp->next;
			ra(stack_a, data);
		}
	}
}

void	push_in_b(int *table, t_data *data, t_list **stack_a, t_list **stack_b)
{
	if (data->nbr_node == 500)
		data->step = 50;
	else
		data->step = 20;
	data->middle = data->nbr_node / 2;
	data->start = data->middle - data->step;
	data->end = data->middle + data->step;
	while ((data->start > 0) && (data->end < (data->nbr_node - 1)))
	{
		push_in_b_2(table, data, stack_a, stack_b);
		data->start -= data->step;
		data->end += data->step;
	}
	if (*stack_a)
	{
		data->start = 0;
		data->end = data->nbr_node - 1;
		push_in_b_2(table, data, stack_a, stack_b);
	}
}
