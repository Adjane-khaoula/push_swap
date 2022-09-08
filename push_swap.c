/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:40:53 by kadjane           #+#    #+#             */
/*   Updated: 2022/09/08 18:58:34 by kadjane          ###   ########.fr       */
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

void	add_node(t_list **list, t_list *node)
{
	node -> next = *list;
	*list = node;
}

void	remove_node(t_list *stack, t_list *node)
{
	t_list **temp;

	temp = &stack;
	while(*temp != node)
		temp = &(*temp)->next;
	temp = node->next;
}

void affiche_stack(t_list *stack)
{
	t_list	*temp;
	char	*str;
	
	temp = stack;
	while(temp->next != NULL)
	{
		str = ft_itoa(temp->value);
		ft_putstr(str);
		temp = temp->next;
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*head_a;
	t_list	*stack_b;
	t_list	*head_b;
	int	n;

	head_a = NULL;
	head_b = NULL;
	if (ac-- > 1 && head_a == NULL)
	{
		n = ft_atoi(av[ac]);
		head_a = node(n);
		stack_a = head_a;
		while(ac >= 1)
			add_node(&stack_a, node(ft_atoi(av[ac--])));
		affiche_stack(stack_a);
		affiche_stack(stack_b);
	}
}