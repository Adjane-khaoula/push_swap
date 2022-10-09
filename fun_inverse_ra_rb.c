/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_inverse_ra_rb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 00:47:31 by kadjane           #+#    #+#             */
/*   Updated: 2022/10/09 00:56:18 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb_help(t_data *data)
{
	if (ft_strcmp(data->output->out, "") != 0)
	{
		if (ft_strcmp(data->output->out, "rra") == 0)
		{
			write(1, "rrr\n", 4);
			data->output->out = "";
		}
		else
		{
			ft_putstr(data->output->out);
			data->output->out = "rrb";
		}
	}
	else
	{
		free(data->output);
		data->output = node_store("rrb");
	}
}

void	rrb(t_list **stack, t_data *data)
{
	t_list	**temp;
	t_list	*end_node;

	temp = stack;
	if (stack && (*stack)->next)
	{
		while ((*temp)->next)
			temp = &(*temp)->next;
		end_node = node((*temp)->value);
		end_node->next = *stack;
		*stack = end_node;
		free(*temp);
		*temp = NULL;
		rrb_help(data);
	}
}

void	rra_help(t_data *data)
{
	if (ft_strcmp(data->output->out, "") != 0)
	{
		if (ft_strcmp(data->output->out, "rrb") == 0)
		{
			write(1, "rrr\n", 4);
			data->output->out = "";
		}
		else
		{
			ft_putstr(data->output->out);
			data->output->out = "rra";
		}
	}
	else
	{
		free(data->output);
		data->output = node_store("rra");
	}
}

void	rra(t_list **stack, t_data *data)
{
	t_list	**temp;
	t_list	*end_node;

	temp = stack;
	if (stack && (*stack)->next)
	{
		while ((*temp)->next)
			temp = &(*temp)->next;
		end_node = node((*temp)->value);
		end_node->next = *stack;
		*stack = end_node;
		free(*temp);
		*temp = NULL;
		rra_help(data);
	}
}
