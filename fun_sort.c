/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 11:05:17 by kadjane           #+#    #+#             */
/*   Updated: 2022/09/11 11:16:16 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"


void	sort_2_element(t_list **stack)
{
	int	data;
	
	if ((*stack)->value > (*stack)->next->value)
	{
		data = (*stack)->value;
		(*stack)->value = (*stack)->next->value;
		(*stack)->next->value = data;
	}
}

void	sort_3_element(t_list **stack)
{
	int		data;
	t_list	*temp;

	temp = *stack;
	while (temp->next)
		temp = temp->next;
	if ((*stack)->value > temp->value)
	{
		data = (*stack)->value;
		(*stack)->value = temp->value;
		temp->value = data;
		sort_2_element(stack);
	}
}