/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:40:53 by kadjane           #+#    #+#             */
/*   Updated: 2022/09/16 18:17:39 by kadjane          ###   ########.fr       */
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
	stack_a = NULL;
	stack_b = NULL;
	n = ac;
	if (ac-- > 1)
	{
		while(ac > 0)
		{
			add_node(&stack_a, node(ft_atoi(av[ac--])));
			data.nbr_node++;
		}
	}

	printf("++++++++++stack_a_debut\n");
	print_stack(stack_a);
	printf("\n\n");
	
	printf("++++++++++stack_b_debut\n");
	print_stack(stack_b);
	printf("\n\n");
	
	table = sort_stack_in_table(stack_a, data.nbr_node);
	push_in_b(table, &data, &stack_a, &stack_b);
	printf("++++++++++stack_a_fin\n");
	print_stack(stack_a);
	printf("\n\n");
	
	printf("++++++++++stack_b_fin\n");
	print_stack(stack_b);
}













	//printf("+++++++++++++%d\n",stack_is_sorted(&stack_a, nbr_node));
	// table = sort_stack_in_table(&stack_a, nbr_node);
	// while (nbr_node--)
	// 	printf("+++++%d\n",*table++);