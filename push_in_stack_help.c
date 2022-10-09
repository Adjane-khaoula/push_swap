/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_stk_help.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 01:10:37 by kadjane           #+#    #+#             */
/*   Updated: 2022/10/09 01:48:19 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	last_stk(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp->value);
}

void	push_in_a_4(t_data *data, t_list **stk_b, t_list **stk_a)
{
	int	i;

	i = 0;
	while (((*stk_b)->value > (*stk_a)->value))
	{
		if (((*stk_b)->value > (*stk_a)->value)
			&& (*stk_b)->value == ((*stk_a)->value) + 1)
		{
			pa(stk_b, stk_a, data);
			sa(stk_a, data);
			i++;
			break ;
		}
		else
			ra(stk_a, data);
	}
	if (i != 1)
		pa(stk_b, stk_a, data);
}

void	push_in_a_3(int *tab, t_data *data, t_list **stk_b, t_list **stk_a)
{
	int		last_stack;
	int		last_value;

	last_value = *(tab + (data->nbr_node - 1));
	last_stack = last_stk(stk_a);
	if ((*stk_b)->value < last_stack && last_stack != last_value)
	{
		while ((*stk_b)->value < last_stack && last_stack != last_value)
		{
			rra(stk_a, data);
			last_stack = last_stk(stk_a);
		}
		pa(stk_b, stk_a, data);
	}
	else if (((*stk_b)->value > (*stk_a)->value))
		push_in_a_4(data, stk_b, stk_a);
	else
		pa(stk_b, stk_a, data);
}

void	push_in_a_2(int *tab, t_data *data, t_list **stk_b, t_list **stk_a)
{
	data->last_stack_b = last_stk(stk_b);
	if ((*stk_b)->value < data->last_stack_b)
	{
		while ((*stk_b)->value < data->last_stack_b)
		{
			rrb(stk_b, data);
			data->last_stack_b = last_stk(stk_b);
		}
		push_in_a_3(tab, data, stk_b, stk_a);
	}
	else if ((*stk_b)->value > (*stk_b)->next->value)
		push_in_a_3(tab, data, stk_b, stk_a);
	else if ((*stk_b)->value < (*stk_b)->next->value
		&& (*stk_b)->value > (*stk_b)->next->next->value)
	{
		sb(stk_b, data);
		push_in_a_3(tab, data, stk_b, stk_a);
	}
	else
	{
		rb(stk_b, data);
		data->last_stack_b = last_stk(stk_b);
	}
}

void	push_in_a(int *tab, t_data *data, t_list **stk_b, t_list **stk_a)
{
	data->last_value = *(tab + (data->nbr_node - 1));
	while ((*stk_b) && (*stk_b)->next && (*stk_b)->next->next)
		push_in_a_2(tab, data, stk_b, stk_a);
	data->last_stack_a = last_stk(stk_a);
	while (data->last_stack_a != data->last_value)
	{
		rra(stk_a, data);
		data->last_stack_a = last_stk(stk_a);
	}
	while ((*stk_b) && ((*stk_b)->next))
	{
		if ((*stk_b)->value < ((*stk_b)->next->value))
		{
			sb(stk_b, data);
			pa(stk_b, stk_a, data);
		}
		pa(stk_b, stk_a, data);
	}
	pa(stk_b, stk_a, data);
}
