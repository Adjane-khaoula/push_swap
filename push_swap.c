/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:38:07 by kadjane           #+#    #+#             */
/*   Updated: 2022/10/09 04:14:20 by kadjane          ###   ########.fr       */
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
			exit(0);
		}
		tmp = tmp->next;
	}
	return (1);
}

void	ft_error(void)
{
	ft_putstr("Error");
	exit(EXIT_FAILURE);
}

void	sort_stack(t_data *data, t_list **stack_a, t_list **stack_b)
{
	int	*table;

	if (stack_is_sorted(stack_a, data->nbr_node) == 0)
		exit(EXIT_SUCCESS);
	if (data->nbr_node == 2)
		sort_2_element(data, stack_a);
	else if (data->nbr_node == 3)
		sort_3_element(data, stack_a);
	else if (data->nbr_node == 5)
	{
		table = sort_stack_in_table(*stack_a, data->nbr_node);
		sort_5_element(table, data, stack_a, stack_b);
	}
	else
	{
		table = sort_stack_in_table(*stack_a, data->nbr_node);
		push_in_b(table, data, stack_a, stack_b);
		push_in_a(table, data, stack_b, stack_a);
	}
	if (data->output)
		ft_putstr(data->output->out);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_data	data;

	data.nbr_node = ac - 1;
	data.output = node_store("");
	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		exit(EXIT_SUCCESS);
	if (ac-- > 1)
	{
		while (ac > 0)
		{
			if (check_duplicate(&stack_a, ft_atoi(av[ac])) == 1)
				add_node(&stack_a, node(ft_atoi(av[ac--])));
		}
	}
	sort_stack(&data, &stack_a, &stack_b);
}
