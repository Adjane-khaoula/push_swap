/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:30:23 by kadjane           #+#    #+#             */
/*   Updated: 2022/09/25 18:45:35 by kadjane          ###   ########.fr       */
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
		else if (tmp->value <= *(tab + (data->end)) && tmp->value >= *(tab + data->middle))
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
	data->step = 20; 
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
	t_list	*tmp3;
	int		i;

	tmp1 = *stack_b;
	tmp2 = (*stack_b)->next;
	tmp3 = *stack_a;
	i = 0;
	while (*stack_b)
	{
		if ((*stack_b)->value < tmp2->value)
		{
			rb(stack_b,data);
			tmp2 = (*stack_b)->next;
		}
		else 
		{
			while (tmp1->next)
				tmp1 = tmp1->next;
			if ((*stack_b)->value < tmp1->value)
				rrb(stack_b,data);
			while (*stack_a && tmp3->next)
				tmp3 = tmp3->next;
			if (*stack_a && (*stack_b)->value > tmp3->value && i == 0)
			{
				pa(stack_b,stack_a,data);
				ra(stack_a,data);
			}
			else
			{
				while (*stack_a && (*stack_b)->value > (*stack_a)->value)
				{
					ra(stack_a,data);
					i++;
				}
				while (*stack_a && (*stack_b)->value < (*stack_a)->value && i)
				{
					rra(stack_a,data);
					i--;
				}
				pa(stack_b,stack_a,data);
			}
		}
		tmp1 = *stack_b;
		tmp3 = *stack_a;
	}
}