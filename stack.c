/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:29:03 by kadjane           #+#    #+#             */
/*   Updated: 2022/09/10 17:29:16 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*node(int a)
{
	t_list *new;

	new = (t_list *) malloc(sizeof(t_list));
	new->value = a;
	new->next = NULL;
	return new;
}

void	add_node(t_list **stack, t_list *new_node)
{
	new_node -> next = *stack;
	*stack = new_node;
}

void	print_stack(t_list *stack)
{
	t_list	*temp;
	char	*str;
	
	temp = stack;
	while(temp)
	{
		str = ft_itoa(temp->value);
		ft_putstr(str);
		temp = temp->next;
	}
}