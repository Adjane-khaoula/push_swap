/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_stack_shared.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:43:55 by kadjane           #+#    #+#             */
/*   Updated: 2022/09/27 10:25:43 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss (t_list **stack_a, t_list **stack_b,t_data *data)
{
	sa(stack_a,data);
	sb(stack_b,data);
	ft_putstr("ss"); 
}

void	rr(t_list **stack_a, t_list **stack_b,t_data *data)
{
	ra(stack_a, data);
	rb(stack_b, data);
	ft_putstr("rr");
}

void	rrr(t_data *data, t_list **stack_a, t_list **stack_b)
{
	rra(stack_a,data);
	rrb(stack_b,data);
	ft_putstr("rrr");
}

void	rrb_help(t_data *data)
{
	if (data->output)
	{
		if(ft_strcmp(data->output->out, "rra") == 0)
			write(1,"rrr\n",4);
		else
		{
			ft_putstr(data->output->out);
			ft_putstr("rrb");
		}
		free(data->output);
		data->output = NULL;
	}
	else
		data->output = node_store("rrb");
}

void	rrb(t_list **stack,t_data *data)
{
	t_list	**temp;
	t_list	*end_node;
	
	temp = stack;
	
	if(stack && (*stack)->next)
	{
		while((*temp)->next)
			temp = &(*temp)->next;
		end_node = node((*temp)->value);
		end_node->next = *stack;
		*stack = end_node;
		free(*temp);
		*temp = NULL;
		rrb_help(data);
		// if (data->output)
		// {
		// 	ft_putstr(data->output->out);
		// 	ft_putstr("rrb");
		// 	free(data->output);
		// 	data->output = NULL;
		// }
		// else
		// 	data->output = node_store("rrb");
	}
}

void	rra_help(t_data *data)
{
	if (data->output)
	{
		if(ft_strcmp(data->output->out, "rrb") == 0)
			write(1,"rrr\n",4);
		else
		{
			ft_putstr(data->output->out);
			ft_putstr("rra");
		}
		free(data->output);
		data->output = NULL;
	}
	else
		data->output = node_store("rra");
}

void	rra(t_list **stack, t_data *data)
{
	t_list	**temp;
	t_list	*end_node;
	
	temp = stack;
	
	if(stack && (*stack)->next)
	{
		while((*temp)->next)
			temp = &(*temp)->next;
		end_node = node((*temp)->value);
		end_node->next = *stack;
		*stack = end_node;
		free(*temp);
		*temp = NULL;
		rra_help(data);
		// if (data->output)
		// {
		// 	ft_putstr(data->output->out);
		// 	ft_putstr("rra");
		// 	free(data->output);
		// 	data->output = NULL;
		// }
		// else
		// 	data->output = node_store("rra");
	}
}