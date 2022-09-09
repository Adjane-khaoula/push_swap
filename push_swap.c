/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:40:53 by kadjane           #+#    #+#             */
/*   Updated: 2022/09/09 19:03:04 by kadjane          ###   ########.fr       */
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

t_list	*remove_node(t_list **stack, t_list *node)
{
	t_list **temp;

	temp = stack;
	while(*temp != node)
		temp = &(*temp)->next;
	*temp = node->next;
	return *stack;
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
	t_list **temp;
	int	n;

	stack_a = NULL;
	stack_b = NULL;
	if (ac-- > 1 && head_a == NULL)
	{
		n = ft_atoi(av[ac]);
		stack_a = node(n);
		head_a = stack_a;
		while(ac >= 1)
			add_node(&head_a, node(ft_atoi(av[ac--])));
		affiche_stack(head_a);
		temp = &head_a;
		while(*temp != NULL)
		{
			if((*temp)->value == 1)
				remove_node(&head_a,*temp);
			temp =&(*temp)->next;
		}
		affiche_stack(head_a);
	}
}