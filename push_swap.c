/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:40:53 by kadjane           #+#    #+#             */
/*   Updated: 2022/09/11 11:19:53 by kadjane          ###   ########.fr       */
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
	if (ac >=3)
		sort_2_element(&stack_a);
	if (ac >=4)
		sort_3_element(&stack_a);
	print_stack(stack_a);
}