/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:40:53 by kadjane           #+#    #+#             */
/*   Updated: 2022/10/04 18:24:52 by kadjane          ###   ########.fr       */
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
	
	// printf("stack_a\n");
	// print_stack(stack_a);
	// printf("\n\n\n");
	// print_stack(stack_b);
	if (n == 2)
		sort_2_element(&data, &stack_a);
	else if (n == 3)
		sort_3_element(&data, &stack_a);
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
		push_in_a(&data,&stack_b,&stack_a);
	}
	if (data.output)
		ft_putstr(data.output->out);
	printf("\n\n\n");
	printf("stack_b\n");
	print_stack(stack_b);
	printf("\n\n\n");
	print_stack(stack_a);

	
	
	
	
	
	
	
	
	// ra(&stack_a,&data);
	// // print_stack(stack_a);
	
	// ra(&stack_a,&data);
	
	// pb(&stack_a,&stack_b,&data);
	// pb(&stack_a,&stack_b,&data);
	// rb(&stack_b,&data);
	// ra(&stack_a,&data);
	// // printf("\n\n\n");
	
	// sb(&stack_b,&data);
	// // print_stack(stack_a);
	// // printf("\n\n\n");
	
	// sa(&stack_a,&data);
	// sb(&stack_b,&data);
	// sa(&stack_a,&data);
	// // print_stack(stack_a);
	// // printf("\n\n\n");
	
	// sa(&stack_a,&data);
	// ra(&stack_a,&data);
	// pb(&stack_a,&stack_b,&data);
	// pb(&stack_a,&stack_b,&data);
	// pa(&stack_b,&stack_a,&data);
	// pa(&stack_b,&stack_a,&data);
	// pb(&stack_a,&stack_b,&data);
	// rb(&stack_b,&data);
	// print_stack(stack_a);
	// printf("\n\n\n");
	// print_stack(stack_b);
	


}

