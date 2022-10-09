/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_stack_shared.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:43:55 by kadjane           #+#    #+#             */
/*   Updated: 2022/10/09 00:55:33 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list **stack_a, t_list **stack_b, t_data *data)
{
	sa(stack_a, data);
	sb(stack_b, data);
	ft_putstr("ss");
}

void	rr(t_list **stack_a, t_list **stack_b, t_data *data)
{
	ra(stack_a, data);
	rb(stack_b, data);
	ft_putstr("rr");
}

void	rrr(t_data *data, t_list **stack_a, t_list **stack_b)
{
	rra(stack_a, data);
	rrb(stack_b, data);
	ft_putstr("rrr");
}
