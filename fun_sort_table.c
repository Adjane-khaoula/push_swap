/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_sort_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 00:28:37 by kadjane           #+#    #+#             */
/*   Updated: 2022/10/09 03:56:36 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swap_element(int **tab, int nbr_node)
{
	int	tmp;
	int	*tab_tmp;

	tab_tmp = *tab;
	while (--nbr_node)
	{
		if (*tab_tmp > *(tab_tmp + 1))
		{
			tmp = *tab_tmp;
			*tab_tmp = *(tab_tmp + 1);
			*(tab_tmp + 1) = tmp;
		}
		tab_tmp++;
	}
}

int	table_is_sorted(int **table, int nbr_node)
{
	int	i;
	int	*tab_tmp;

	i = 0;
	tab_tmp = *table;
	while (--nbr_node)
	{
		if (*tab_tmp > *(tab_tmp + 1))
			i++;
		tab_tmp++;
	}
	return (i);
}

int	*sort_stack_in_table(t_list	*stack_a, int nbr_node)
{
	int	*tab;
	int	*tmp;
	int	i;

	i = 1;
	tab = malloc(sizeof(int) * nbr_node);
	tmp = tab;
	while (stack_a)
	{
		*tmp = stack_a->value;
		stack_a = stack_a->next;
		tmp++;
	}
	while (i)
	{
		swap_element(&tab, nbr_node);
		i = table_is_sorted(&tab, nbr_node);
	}
	return (tab);
}
