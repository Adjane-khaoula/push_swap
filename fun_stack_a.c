/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_stack_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:51:51 by kadjane           #+#    #+#             */
/*   Updated: 2022/09/29 15:39:13 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_help(t_data *data)
{
	if (ft_strcmp(data->output->out, "") != 0)
	{
		if(ft_strcmp(data->output->out, "sb") == 0)
		{
			write(1,"ss\n",4);
			data->output->out = "";
		}
		else
		{
			ft_putstr(data->output->out);
			data->output->out = "sa";
		}
	}
	else
		data->output = node_store("sa");
}

// void	sa_help(t_data *data)
// {
	
// 	if (data->output)
// 	{
// 		if(ft_strcmp(data->output->out, "sb") == 0)
// 			write(1,"ss\n",3);
// 		else
// 		{
// 			ft_putstr(data->output->out);
// 			ft_putstr("sa");
// 		}
// 		free(data->output);
// 		data->output = NULL;
// 	}
// 	else
// 		data->output = node_store("sa");
// }

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

void	pa(t_list	**stack_b, t_list	**stack_a,t_data *data)
{
	t_list	*temp;
	
	if(*stack_b)
	{
		temp = *stack_b;
		add_node(stack_a,node((*stack_b)->value));
		*stack_b = (*stack_b)->next;
		free(temp);
		temp = NULL;
		if (ft_strcmp(data->output->out, "") != 0)
		{
			ft_putstr(data->output->out);
			data->output->out = "pa";
		}
		else
			data->output = node_store("pa");
		
		// if (data->output)
		// {
		// 	ft_putstr(data->output->out);
		// 	ft_putstr("pa");
		// 	free(data->output);
		// 	data->output = NULL;
		// }
		// else
		// 	data->output = node_store("pa");
	}
}

void	ra_help(t_data *data)
{
	if (ft_strcmp(data->output->out, "") != 0)
	{
		if(ft_strcmp(data->output->out, "rb") == 0)
		{
			write(1,"rr\n",3);
			data->output->out = "";
		}
		else
		{
			ft_putstr(data->output->out);
			data->output->out = "ra";
		}
	}
	else
		data->output = node_store("ra");
}

// void	ra_help(t_data *data)
// {
// 	if (data->output)
// 	{
// 		if(ft_strcmp(data->output->out, "rb") == 0)
// 			write(1,"rr\n",3);
// 		else
// 		{
// 			ft_putstr(data->output->out);
// 			ft_putstr("ra");
// 		}
// 		free(data->output);
// 		data->output = NULL;
// 	}
// 	else
// 		data->output = node_store("ra");
// }

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

