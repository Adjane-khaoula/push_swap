/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:40:53 by kadjane           #+#    #+#             */
/*   Updated: 2022/09/10 00:05:53 by kadjane          ###   ########.fr       */
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

void print_stack(t_list *stack)
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

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	
	int	n;

	stack_a = NULL;
	stack_b = NULL;
	n = ac;
	if (ac-- > 1)
	{
		while(ac > 0)
			add_node(&stack_a, node(ft_atoi(av[ac--])));
		// print_stack(stack_a);
		// push(&stack_a,&stack_b);
		
		// printf("\n");
		// print_stack(stack_a);
		// printf("\n");
		// print_stack(stack_b);
		
		// while(1);
	}
}