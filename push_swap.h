/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:20:26 by kadjane           #+#    #+#             */
/*   Updated: 2022/09/08 16:46:28 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include<stdlib.h>
#include<stdio.h>
#include <unistd.h>

typedef struct s_list
{
	int value;
	struct s_list *next;
} t_list;

int	ft_atoi(const char	*str);
char	*ft_itoa(int n);
int	ft_strlen(const char *str);
void	ft_putstr(char *str);
#endif
