/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:40:53 by kadjane           #+#    #+#             */
/*   Updated: 2022/09/11 16:44:14 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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
	}
	print_stack(stack_a);
	printf("\n\n");
	if (n == 3)
		sort_2_element(&stack_a);
	if (n == 4)
		sort_3_element(&stack_a);
	if (n == 5)
		sort_4_element(&stack_a,&stack_b);
	print_stack(stack_a);
}