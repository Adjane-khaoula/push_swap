/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_stack_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:51:51 by kadjane           #+#    #+#             */
/*   Updated: 2022/09/20 17:14:21 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_help(t_data *data)
{
	
	if (data->output)
	{
		if(ft_strcmp(data->output->out, "sb") == 0)
		{
			write(1,"ss\n",3);
			free(data->output);
			data->output = NULL;
		}
		else
		{
			ft_putstr(data->output->out);
			ft_putstr("sa");
			data->output->out = "sa";
		}
	}
	else
		data->output = node_store("sa");
}

void	sa(t_list	**stack,t_data *data)
{
	int	first_data;

	if((*stack) && (*stack)->next  )
	{
		first_data = (*stack)->value;
		(*stack)->value = (*stack)->next->value;
		(*stack)->next->value = first_data;
		sa_help(data);
	}
}

void	pa(t_list	**stack_1, t_list	**stack_2,t_data *data)
{
	t_list	*temp;
	
	if(*stack_1)
	{
		temp = *stack_1;
		add_node(stack_2,node((*stack_1)->value));
		*stack_1 = (*stack_1)->next;
		free(temp);
		temp = NULL;
		if (data->output)
		{
			ft_putstr(data->output->out);
			ft_putstr("pa");
			data->output->out = "pa";
		}
		else
			data->output = node_store("pa");
	}
}

void	ra_help(t_data *data)
{
	printf("+++++++++++++++++++++");
	if (data->output)
	{
		if(ft_strcmp(data->output->out, "rb") == 0)
		{
			write(1,"rr\n",3);
			free(data->output);
			data->output = NULL;
		}
		else
		{
			ft_putstr(data->output->out);
			ft_putstr("ra");
			data->output->out = "ra";
		}
	}
	else
		data->output = node_store("ra");
}

void	ra(t_list **stack,t_data *data)
{
	t_list	*temp_1;
	t_list	*temp_2;
	t_list	*first_node;

	temp_1 = *stack;
	temp_2 = *stack;
	
	if(stack && (*stack)->next)
	{
		first_node = node((*stack)->value);
		while(temp_1->next)
			temp_1 = temp_1->next;
		temp_1->next = first_node;
		*stack = (*stack)->next;
		free(temp_2);
		ra_help(data);
	}
}

