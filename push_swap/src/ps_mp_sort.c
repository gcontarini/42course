/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_mp_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:48:10 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/23 10:16:40 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	mp_sort(t_istack *stk1, t_istack *stk2, int depth, int out);
static int	mp_sort2(t_istack *stk1, t_istack *stk2, int depth, int out);
static int	mp1(t_istack *stk1, t_istack *stk2, int depth, int out);
static int	mp2(t_istack *stk1, t_istack *stk2, int depth, int out);

int	ps_midpoint_sort(t_istack *stk1, t_istack *stk2, int out)
{
	int		i;

	i = mp_sort(stk1, stk2, (int) ft_len_istack(stk1), out);
	return (i);
}

static int	mp_sort(t_istack *stk1, t_istack *stk2, int depth, int out)
{
	int	i;
	int	j;

	if (depth <= 5)
		return (el5_sort1(stk1, stk2, depth, out));
	j = mp1(stk1, stk2, depth, out);
	i = depth - 1;
	i += mp_sort(stk1, stk2, depth - j, out);
	i += mp_sort2(stk1, stk2, j, out);
	return (i);
}

static int	mp_sort2(t_istack *stk1, t_istack *stk2, int depth, int out)
{
	int	i;
	int	j;

	if (depth <= 5)
	{
		i = el5_sort2(stk1, stk2, depth, out);
		while (depth--)
			i += ps_pa(stk1, stk2, out);
		return (i);
	}
	j = mp2(stk1, stk2, depth, out);
	i = depth - 1;
	i += ps_execute1(stk2, depth - j, out, ps_rrb);
	i += mp_sort(stk1, stk2, j, out);
	i += mp_sort2(stk1, stk2, depth - j, out);
	return (i);
}

static int	mp1(t_istack *stk1, t_istack *stk2, int depth, int out)
{
	int	i;
	int	mid;

	mid = ps_median(stk1);
	i = 0;
	while (depth--)
	{
		if (stk1->top && stk1->top->i < mid)
		{
			ps_pb(stk1, stk2, out);
			i++;
		}
		else
			ps_ra(stk1, out);
	}
	return (i);
}

static int	mp2(t_istack *stk1, t_istack *stk2, int depth, int out)
{
	int	i;
	int	mid;

	mid = ps_median_depth(stk2, depth);
	i = 0;
	while (depth--)
	{
		if (stk2->top && stk2->top->i > mid)
		{
			ps_pa(stk1, stk2, out);
			i++;
		}
		else
			ps_rb(stk2, out);
	}
	return (i);
}
