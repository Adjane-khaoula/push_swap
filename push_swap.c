/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:38:07 by kadjane           #+#    #+#             */
/*   Updated: 2022/10/08 18:34:13 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

int	check_duplicate(t_list **stack_a, int value)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->value == value)
		{
			ft_putstr("Error");
			exit(0) ;
		}
		tmp = tmp->next;
	}
	return (1);
}

void	ft_error()
{
	ft_putstr("Error");
	exit(EXIT_FAILURE);
	
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_data	data;
	int		*table;
	int		n;
	int		i;
	
	
	i = 0;
	data.nbr_node = 0;
	data.output = node_store("");
	stack_a = NULL;
	stack_b = NULL;
	n = ac - 1;
	if (ac == 1)
		exit(EXIT_SUCCESS);
	if (ac-- > 1)
	{
		while(ac > 0)
		{
			if (check_duplicate(&stack_a, ft_atoi(av[ac])) == 1)
			{
				add_node(&stack_a, node(ft_atoi(av[ac--])));
				data.nbr_node++;
			}
		}
	}
	if(stack_is_sorted(&stack_a, data.nbr_node) == 0)
		exit(EXIT_SUCCESS);
	if (n == 2)
		sort_2_element(&data, &stack_a);
	else if (n == 3)
		sort_3_element(&data, &stack_a);
	else if (n == 5)
	{
		table = sort_stack_in_table(stack_a, data.nbr_node);
		sort_5_element(table, &data, &stack_a, &stack_b);
	}
	else
	{
		table = sort_stack_in_table(stack_a, data.nbr_node);
		push_in_b(table, &data, &stack_a, &stack_b);
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

