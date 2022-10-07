/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:37:59 by kadjane           #+#    #+#             */
/*   Updated: 2022/10/07 16:07:42 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	push_in_b_hlp(int *tab,t_data *data, t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		iter;

	tmp = *stack_a;
	iter = data->nbr_node;
	while (iter-- && tmp && tmp->next)
	{
		if (tmp->value >= *(tab + (data->start)) && tmp->value < *(tab + data->middle))
		{
			tmp = tmp->next;
			pb(stack_a,stack_b,data);
			rb(stack_b,data);
		}
		else if (tmp->value < *(tab + ((data->end))) && tmp->value >= *(tab + data->middle))
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

void	push_in_a_help(int *table, t_data *data,t_list **stack_b, t_list **stack_a)
{
	t_list	*tmp;
	int		last_value;
	int		i;

	i = 0;
	tmp = *stack_a;
	last_value = *(table + (data->nbr_node - 1));
	while (*stack_a && tmp->next)
		tmp = tmp->next;

	if ((*stack_b)->value < tmp->value && tmp->value != last_value)
	{
		while ((*stack_b)->value < tmp->value && tmp->value != last_value)
		{
			rra(stack_a,data);
			tmp = *stack_a;
			while (tmp->next)
				tmp = tmp->next;
		}
		pa(stack_b,stack_a,data);
	}
	else if (((*stack_b)->value > (*stack_a)->value))
	{
		while (((*stack_b)->value > (*stack_a)->value))
		{
			if(((*stack_b)->value > (*stack_a)->value ) && (*stack_b)->value == ((*stack_a)->value) + 1)
			{
				pa(stack_b,stack_a,data);
				sa(stack_a,data);
				i++;
				break ;
			}
			else
				ra(stack_a,data);
		}
		if (i != 1)
			pa(stack_b,stack_a,data);
	}
	else 
		pa(stack_b,stack_a,data);

}

void	push_in_a(int *table, t_data *data,t_list **stack_b, t_list **stack_a)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		last_value;
	// int		i;
	
	// // last_value = data->nbr_node;
	// last_value = (*stack_a)->value;
	last_value = *(table + (data->nbr_node - 1));
	while ((*stack_b)&& (*stack_b)->next && (*stack_b)->next->next)
	{
		tmp1 = *stack_b;
		while (tmp1->next)
			tmp1 = tmp1->next;
		if ((*stack_b)->value < tmp1->value)
		{	
			while ((*stack_b)->value < tmp1->value)
			{
				rrb(stack_b,data);
				tmp1 = *stack_b;
				while (tmp1->next)
				tmp1 = tmp1->next;
			}
			push_in_a_help(table, data,stack_b,stack_a);
		}
		else if ((*stack_b)->value > (*stack_b)->next->value)
			push_in_a_help(table, data,stack_b,stack_a);
		else if ((*stack_b)->value < (*stack_b)->next->value && (*stack_b)->value > (*stack_b)->next->next->value)
		{
				sb(stack_b,data);
				push_in_a_help(table, data,stack_b,stack_a);
		}
		else
		{
				rb(stack_b,data);
				tmp1 = tmp1->next;
		}
	
	}
	tmp2 = *stack_a;
	while (tmp2->next)
		tmp2 = tmp2->next;

	while (tmp2->value != last_value)
	{
		rra(stack_a,data);
		tmp2 = *stack_a;
		while (tmp2->next)
			tmp2 = tmp2->next;
	}
	while ((*stack_b) && ((*stack_b)->next))
	{
		if ((*stack_b)->value < ((*stack_b)->next->value))
		{
			sb(stack_b,data);
			pa(stack_b,stack_a,data);
		}
		pa(stack_b,stack_a,data);
	}
	pa(stack_b,stack_a,data);
}















	// if ((*stack_b)->value < tmp1->value || ((*stack_b)->value > ((*stack_b)->next)->value)
		// 	|| ((*stack_b)->value < (*stack_b)->next->value && (*stack_b)->value > (*stack_b)->next->next->value
		// 	&& (*stack_b)->next->value > (*stack_b)->next->next->value))
		// {
		// 	if ( ((*stack_b)->value < (*stack_b)->next->value && (*stack_b)->value > (*stack_b)->next->next->value
		// 		&& (*stack_b)->next->value > (*stack_b)->next->next->value))
		// 		sb(stack_b,data);
		// 	if ((*stack_b)->value < tmp1->value)
		// 		rrb(stack_b,data);
		// 	if (tmp2->value != last_value && (*stack_b)->value < tmp2->value )
		// 	{	
		// 		while (tmp2->value != last_value && (*stack_b)->value < tmp2->value )
		// 		{
		// 			rra(stack_a,data);
		// 			tmp2 = *stack_a;
		// 			while (*stack_a && tmp2->next)
		// 			tmp2 = tmp2->next;
		// 		}
		// 			pa(stack_b,stack_a,data);	
		// 	}
		// 	else 
		// 	{	
		// 		i = 0;
		// 		while (((*stack_b)->value > (*stack_a)->value))
		// 		{
		// 			if(((*stack_b)->value > (*stack_a)->value ) && (*stack_b)->value == ((*stack_a)->value) + 1)
		// 			{
		// 				pa(stack_b,stack_a,data);
		// 				sa(stack_a,data);
		// 				i++;
		// 				break ;
		// 			}
		// 			else
		// 				ra(stack_a,data);
		// 		}
		// 		// printf("qqknk %s\n", data->output->out);
		// 		// if (ft_strcmp(data->output->out,"ra") == 0)
		// 			// pa(stack_b,stack_a,data);	
		// 		if (i != 1)
		// 			pa(stack_b,stack_a,data);	

		// 	}
		// }
		// else
		// 	rb(stack_b,data);