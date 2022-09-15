/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 11:05:17 by kadjane           #+#    #+#             */
/*   Updated: 2022/09/15 23:21:05 by kadjane          ###   ########.fr       */
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

int	*sort_stack_a(t_list	**stack_a, int nbr_node)
{
	int	*tab;
	int	*tmp;
	int	i;

	i = 1;
	tab = malloc(sizeof(int) * nbr_node);
	tmp = tab;
	while (*stack_a)
	{
		*tmp = (*stack_a)->value;
		*stack_a = (*stack_a)->next;
		tmp++;
	}
	while (i)
	{
		swap_element(&tab,nbr_node);
		i = table_is_sorted(&tab, nbr_node);
	}
	return (tab);
}













// void	sort_2_element(t_list **stack)
// {
// 	if ((*stack)->value > (*stack)->next->value)
// 		swap (stack);
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