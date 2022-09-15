/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 11:05:17 by kadjane           #+#    #+#             */
/*   Updated: 2022/09/15 15:37:09 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swap_element(char **tab, int nbr_node)
{
	int	tmp;
	
	while (nbr_node--)
	{
		if (**tab > **(tab + 1))
		{
			tmp = **tab;
			**tab = **(tab + 1);
			**(tab + 1) = tmp;
		}
		tab++;
	}
}

int	table_is_sorted(char **table, int nbr_node)
{
	int	i;

	i = 0;
	while (--nbr_node)
	{
		if (**table > **(table + 1))
			i++;
		table++;
	}
	return i;
}

char	*sort_stack_a(t_list	**stack_a, int nbr_node)
{
	char	*tab;
	int		i;

	i = 1;
	tab = malloc(sizeof(int) * nbr_node);
	while (*stack_a)
	{
		*tab++ = (*stack_a)->value;
		*stack_a = (*stack_a)->next;
	}
	while (i)
	{
		swap_element(&tab,nbr_node - 1);
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