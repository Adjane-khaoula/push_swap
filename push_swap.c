/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:38:07 by kadjane           #+#    #+#             */
/*   Updated: 2022/10/07 18:41:21 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_data	data;
	int		*table;
	int		n;
	
	
	data.nbr_node = 0;
	data.output = node_store("");
	stack_a = NULL;
	stack_b = NULL;
	n = ac - 1;
	if (ac-- > 1)
	{
		while(ac > 0)
		{
			add_node(&stack_a, node(ft_atoi(av[ac--])));
			data.nbr_node++;
		}
	}
	if (n == 2)
		sort_2_element(&data, &stack_a);
	else if (n == 3)
		sort_3_element(&data, &stack_a);
	else if (n == 5)
		sort_5_element(&data, &stack_a, &stack_b);
	else
	{
		table = sort_stack_in_table(stack_a, data.nbr_node);
		push_in_b(table, &data, &stack_a, &stack_b);
		// sort_2_element(&data,&stack_a);
		// printf("\n\n\n");
		// printf("stack_b\n");
		// print_stack(stack_b);
		// printf("\n\n\n");
		// printf("stack_a\n");
		// print_stack(stack_a);
		// printf("\n\n\n");
		// write (1, "-------\n\n\n", 11);
		
		push_in_a(table, &data,&stack_b,&stack_a);
	}
	if (data.output)
		ft_putstr(data.output->out);
	// system("leaks push_swap");
	// printf("\n\n\n");
	// printf("stack_b\n");
	// print_stack(stack_b);
	// printf("\n\n\n");
	// print_stack(stack_a);
	// while (1)
	// 	;

}

