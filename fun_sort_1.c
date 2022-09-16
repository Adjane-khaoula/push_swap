/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_sort_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 11:05:17 by kadjane           #+#    #+#             */
/*   Updated: 2022/09/16 19:26:30 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swap_element(int **tab, int nbr_node)
{
	int	tmp;
	int	*tab_tmp;
	
	tab_tmp = *tab;
	while (--nbr_node)
	{
		if (*tab_tmp > *(tab_tmp + 1))
		{
			tmp = *tab_tmp;
			*tab_tmp = *(tab_tmp + 1);
			*(tab_tmp + 1) = tmp;
		}
		tab_tmp++;
	}
}

int	table_is_sorted(int **table, int nbr_node)
{
	int	i;
	int	*tab_tmp;

	i = 0;
	tab_tmp = *table;
	while (--nbr_node)
	{
		if (*tab_tmp > *(tab_tmp + 1))
			i++;
		tab_tmp++;
	}
	return i;
}

int	*sort_stack_in_table(t_list	*stack_a, int nbr_node)
{
	int	*tab;
	int	*tmp;
	int	i;

	i = 1;
	tab = malloc(sizeof(int) * nbr_node);
	tmp = tab;
	while (stack_a)
	{
		*tmp = stack_a->value;
		stack_a = stack_a->next;
		tmp++;
	}
	while (i)
	{
		swap_element(&tab,nbr_node);
		i = table_is_sorted(&tab, nbr_node);
	}
	return (tab);
}

void	push_in_b_hlp(int *tab,t_data *data, t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		iter;

	tmp = *stack_a;
	iter = data->nbr_node;
	while (--iter)
	{
		if (tmp->value >= *(tab + (data->middle - data->step)) && tmp->value < *(tab+ data->middle))
			pb(stack_a,stack_b);
		else if (tmp->value <= *(tab + (data->middle + data->step)) && tmp->value >= *(tab + data->middle))
		{
			pb(stack_a,stack_b);
			rb(stack_b);
		}
		else
			ra(stack_a);
		printf("++++++++++ %p\n",tmp);
		tmp = tmp->next;
	}
}

void	push_in_b(int *table,t_data *data, t_list **stack_a, t_list **stack_b)
{
	data->middle = (data->nbr_node - 1) / 2;
	data->step = 2; 
	
	while (((data->middle - data->step) >= 0) && 
			((data->middle +data->step) <= (data->nbr_node - 1)))
	{
		push_in_b_hlp(table, data, stack_a, stack_b);
		data->step += 2;
	}
	if (!(*stack_a))
	{
		data->step = data->middle;
		push_in_b_hlp(table, data, stack_a, stack_b);
	}
}
