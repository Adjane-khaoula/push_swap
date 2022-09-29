/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:37:10 by kadjane           #+#    #+#             */
/*   Updated: 2022/09/29 14:12:00 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	char	*null;

	null = "(null)";
	if (!str)
	{
		while (*null)
			write (1, null++, 1);
	}
	else
	{
		while (*str)
			write(1, str++, 1);
		write (1, "\n", 1);
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

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
			cmp = (cmp * 10) + (*str++ - '0');
		if (*str < 0 || *str > 9 || (n > 0 && cmp > 2147483647)
				|| (n < 0 && cmp > 2147483648))
		{
			ft_putstr("Error");
			exit(0);
		}
		return (n * cmp);
	}
	return (0);
}