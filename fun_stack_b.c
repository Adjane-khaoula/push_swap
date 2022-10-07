/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_stack_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:44:04 by kadjane           #+#    #+#             */
/*   Updated: 2022/10/07 16:45:04 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb_help(t_data *data)
{
	if (ft_strcmp(data->output->out, "") != 0)
	{
		if(ft_strcmp(data->output->out, "sa") == 0)
		{
			write(1,"ss\n",3);
			data->output->out = "";;
		}
		else
		{
			ft_putstr(data->output->out);
			data->output->out = "sb";
		}
	}
	else
	{
		free(data->output);
		data->output = node_store("sb");
	}
}

void	sb(t_list	**stack,t_data *data)
{
	int	first_data;

	if((*stack) && (*stack)->next)
	{
		first_data = (*stack)->value;
		(*stack)->value = (*stack)->next->value;
		(*stack)->next->value = first_data;
		sb_help(data);
	}
}

void	pb(t_list	**stack_a, t_list	**stack_b,t_data *data)
{
	t_list	*temp;
	
	if(*stack_a)
	{
		temp = *stack_a;
		add_node(stack_b,node((*stack_a)->value));
		*stack_a = (*stack_a)->next;
		free(temp);
		if (ft_strcmp(data->output->out, "") != 0)
		{
			ft_putstr(data->output->out);
			data->output->out = "pb";
		}
		else
		{
			free(data->output);
			data->output = node_store("pb");
		}
	}
}

void	rb_help(t_data *data)
{
	if (ft_strcmp(data->output->out, "") != 0)
	{
		if(ft_strcmp(data->output->out, "ra") == 0)
		{
			write(1,"rr\n",3);
			data->output->out = "";
		}
		else
		{
			ft_putstr(data->output->out);
			data->output->out = "rb";
		}
	}
	else
	{
		free(data->output);
		data->output = node_store("rb");
	}
}

void	rb(t_list **stack,t_data *data)
{
	t_list	*temp_1;
	t_list	*temp_2;
	t_list	*first_node;
	
	temp_1 = *stack;
	temp_2 = *stack;
	
	if(*stack && (*stack)->next)
	{
		first_node = node((*stack)->value);
		while(temp_1->next)
			temp_1 = temp_1->next;
		temp_1->next = first_node;
		*stack = (*stack)->next;
		free(temp_2);
		rb_help(data);
	}
}
