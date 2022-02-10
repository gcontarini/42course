/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:56:39 by gcontari          #+#    #+#             */
/*   Updated: 2022/02/04 16:11:58 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ps_atol(const char *str)
{
	long	n;
	long	nbr;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	n = 1;
	if (*str == '-' || *str == '+')
		n = 44 - *str++;
	nbr = 0;
	while (*str >= '0' && *str <= '9')
		nbr = 10 * nbr + (n * (*str++ - '0'));
	return (nbr);
}

int	ps_onlydigits(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != '-' && *str != '+' && *str != ' ')
			return (0);
		str++;
	}
	return (1);
}

unsigned int	ps_min_index(int *arr, size_t len)
{
	int				min;
	unsigned int	index;
	size_t			i;

	min = arr[0];
	index = 0;
	i = 1;
	while (i < len)
	{
		if (min > arr[i] && arr[i] >= 0)
		{
			min = arr[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	stkget(t_istack *stk, size_t index)
{
	t_isunit	*curr;

	curr = stk->top;
	while (curr && index--)
		curr = curr->last;
	return (curr->i);
}
