/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stats.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:20:00 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/22 19:36:33 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_min(t_istack *stk)
{
	t_isunit	*curr1;
	t_isunit	*curr2;
	int			min;

	curr1 = stk->top;
	min = curr1->i;
	while (curr1)
	{
		curr2 = curr1->last;
		while (curr2)
		{
			if (curr2->i < min)
				min = curr2->i;
			curr2 = curr2->last;
		}
		curr1 = curr1->last;
	}
	return (min);
}

int	ps_max(t_istack *stk)
{
	t_isunit	*curr1;
	t_isunit	*curr2;
	int			max;

	curr1 = stk->top;
	max = curr1->i;
	while (curr1)
	{
		curr2 = curr1->last;
		while (curr2)
		{
			if (curr2->i > max)
				max = curr2->i;
			curr2 = curr2->last;
		}
		curr1 = curr1->last;
	}
	return (max);
}

int	ps_median(t_istack *stk)
{
	t_istack	*stkcpy;
	t_isunit	*median;
	size_t		m_index;
	int			i;

	m_index = ft_len_istack(stk) / 2;
	stkcpy = ft_cpy_istack(stk);
	if (!stkcpy || !ft_sort_istack(stkcpy))
	{
		ft_clean_istack(stkcpy);
		return (0);
	}
	median = ft_peek_istack(stkcpy, m_index);
	i = 0;
	if (median)
		i = median->i;
	ft_clean_istack(stkcpy);
	return (i);
}
