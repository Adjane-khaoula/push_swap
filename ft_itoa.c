/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hp <hp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:19:59 by kadjane           #+#    #+#             */
/*   Updated: 2022/10/04 22:06:53 by hp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_cpy(char *str, char *s)
{
	int	i;

	i = 0;
	while (*s)
		*(str + i++) = *s++;
	*(str + i) = '\0';
	return (str);
}

int	lenbr(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		while (n * -1 >= 10)
		{
			n /= 10;
			i++;
		}
		i++;
	}
	else
	{
		while (n >= 10)
		{
			n /= 10;
			i++;
		}
	}
	return (i);
}

char	*ispositif(int n)
{
	int		m;
	int		k;
	char	*s;
	int		i;

	i = lenbr(n);
	m = n;
	k = n;
	s = (char *)malloc(i + 1);
	*(s + i) = '\0';
	if (!s)
		return (NULL);
	while (k >= 10)
	{
		m = k % 10;
		k /= 10;
		s[--i] = m + '0';
	}
	s[--i] = k + '0';
	return (s);
}

char	*isnegatif(int n)
{
	int		m;
	int		k;
	char	*s;
	int		i;

	k = n * -1;
	i = lenbr(n);
	s = (char *)malloc(i + 1);
	if (!s)
		return (NULL);
	*(s + i) = '\0';
	while (k >= 10)
	{
		m = k % 10;
		k /= 10;
		s[--i] = m + '0';
	}
	s[--i] = k + '0';
	s[--i] = '-';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;

	if (n == -2147483648)
	{
		s = (char *)malloc(12);
		if (!s)
			return (0);
		ft_cpy(s, "-2147483648");
	}
	if (n < 0 && n != -2147483648)
		s = isnegatif(n);
	if (n >= 0)
		s = ispositif(n);
	return (s);
}
