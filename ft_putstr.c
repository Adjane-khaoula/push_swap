/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 18:44:41 by kadjane           #+#    #+#             */
/*   Updated: 2022/09/08 16:45:27 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	char	*nul;

	nul = "(null)";
	if (!str)
	{
		while (*nul)
			write (1, nul++, 1);
	}
	else
	{
		while (*str)
			write(1, str++, 1);
		write (1, "\n", 1);
	}
}
