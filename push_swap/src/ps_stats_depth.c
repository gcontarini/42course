/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stats_depth.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:29:44 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/22 17:31:05 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_min_depth(t_istack *stk, int depth)
{
	t_isunit	*curr1;
	t_isunit	*curr2;
	size_t		i;
	int			min;

	curr1 = stk->top;
	min = curr1->i;
	while (curr1 && depth--)
	{
		i = depth;
		curr2 = curr1->last;
		while (curr2 && i--)
		{
			if (curr2->i < min)
				min = curr2->i;
			curr2 = curr2->last;
		}
		curr1 = curr1->last;
	}
	return (min);
}

int	ps_max_depth(t_istack *stk, int depth)
{
	t_isunit	*curr1;
	t_isunit	*curr2;
	size_t		i;
	int			max;

	curr1 = stk->top;
	max = curr1->i;
	while (curr1 && depth--)
	{
		i = depth;
		curr2 = curr1->last;
		while (curr2 && i--)
		{
			if (curr2->i > max)
				max = curr2->i;
			curr2 = curr2->last;
		}
		curr1 = curr1->last;
	}
	return (max);
}

int	ps_median_depth(t_istack *stk, int depth)
{
	t_istack	*stkcpy;
	t_isunit	*median;
	size_t		m_index;
	int			i;

	stkcpy = ps_cpy_depth_istack(stk, depth);
	if (!stkcpy || !ft_sort_istack(stkcpy))
	{
		ft_clean_istack(stkcpy);
		return (0);
	}
	m_index = ft_len_istack(stkcpy) / 2;
	median = ft_peek_istack(stkcpy, m_index);
	i = 0;
	if (median)
		i = median->i;
	ft_clean_istack(stkcpy);
	return (i);
}
