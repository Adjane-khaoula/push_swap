/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:40:53 by kadjane           #+#    #+#             */
/*   Updated: 2022/09/15 22:40:10 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		nbr_node;
	int		*table;
	int	n;
	
	nbr_node = 0;
	stack_a = NULL;
	stack_b = NULL;
	n = ac;
	if (ac-- > 1)
	{
		while(ac > 0)
		{
			add_node(&stack_a, node(ft_atoi(av[ac--])));
			nbr_node++;
		}
	}
	table = sort_stack_a(&stack_a, nbr_node);
	while (nbr_node--)
		printf("+++++%d\n",*table++);
}