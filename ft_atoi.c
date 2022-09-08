/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:00:14 by kadjane           #+#    #+#             */
/*   Updated: 2022/09/06 18:47:16 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char	*str)
{
	unsigned int	cmp;
	int				n;

	cmp = 0;
	n = 1;
	while (*(str))
	{
		while ((*str >= 9 && *str <= 13) || *str == ' ')
			str++;
		if (*str == '+' || *str == '-')
		{
			if (*str++ == '-')
				n = -1;
		}
		while (*str >= '0' && *str <= '9')
		{
			cmp = (cmp * 10) + (*str++ - '0');
			if (n > 0 && cmp > 2147483647)
				return (-1);
			if (n < 0 && cmp > 2147483648)
				return (0);
		}
		return (n * cmp);
	}
	return (0);
}
