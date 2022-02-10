/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_midpoint_sort2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:21:33 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/23 10:12:56 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get2max(t_istack *stk, int depth, int *max1, int *max2);
static int	mv2max_pa(t_istack *stk1, t_istack *stk2, int depth, int out);
static int	find_pa(t_istack *stk1, t_istack *stk2, int value, int out);

int	el3_sort2(t_istack *stk1, t_istack *stk2, int depth, int out)
{
	int	i;

	i = 0;
	if (stk1->top && stk2->top->last && stk1->top->last
		&& stk1->top->i > stkget(stk1, 1) && stk2->top->i < stkget(stk2, 1))
		i += ps_ss(stk1, stk2, out);
	else if (stk1->top && stk1->top->last && stk1->top->i > stkget(stk1, 1))
		i += ps_sa(stk1, out);
	else if (stk2->top->i < stk2->top->last->i)
		i += ps_sb(stk2, out);
	if (depth < 3 || (stkget(stk2, 1) > stkget(stk2, 2)))
		return (i);
	if (stk2->top->i > stkget(stk2, 2))
	{
		i += ps_pa(stk1, stk2, out);
		i += ps_sb(stk2, out);
		i += ps_pb(stk1, stk2, out);
		return (i);
	}
	i += do_pa_2times(stk1, stk2, out);
	i += ps_rb(stk2, out);
	i += do_pb_2times(stk1, stk2, out);
	i += ps_rrb(stk2, out);
	return (i);
}

int	el5_sort2(t_istack *stk1, t_istack *stk2, int depth, int out)
{
	int	i;
	int	j;

	if (depth < 4)
		return (el3_sort2(stk1, stk2, depth, out));
	i = 0;
	i += mv2max_pa(stk1, stk2, depth, out);
	i += el3_sort2(stk1, stk2, depth - 2, out);
	j = 2;
	while (j--)
		i += ps_pb(stk1, stk2, out);
	return (i);
}

static int	get2max(t_istack *stk, int depth, int *max1, int *max2)
{
	t_istack	*stkcpy;

	stkcpy = ps_cpy_depth_istack(stk, depth);
	if (!stkcpy || !ft_sort_istack(stkcpy))
	{
		ft_clean_istack(stkcpy);
		return (0);
	}
	*max1 = ft_peek_istack(stkcpy, depth - 1)->i;
	*max2 = ft_peek_istack(stkcpy, depth - 2)->i;
	ft_clean_istack(stkcpy);
	return (1);
}

static int	mv2max_pa(t_istack *stk1, t_istack *stk2, int depth, int out)
{
	int			i;
	int			max1;
	int			max2;

	if (!get2max(stk2, depth, &max1, &max2))
		return (0);
	i = 0;
	if (steps_to_value(stk2, max1) < steps_to_value(stk2, max2))
	{
		i += find_pa(stk1, stk2, max1, out);
		i += find_pa(stk1, stk2, max2, out);
		return (i);
	}
	i += find_pa(stk1, stk2, max2, out);
	i += find_pa(stk1, stk2, max1, out);
	return (i);
}

static int	find_pa(t_istack *stk1, t_istack *stk2, int value, int out)
{
	int	i;

	i = 0;
	while (stk2->top && stk2->top->i != value)
		i += ps_rb(stk2, out);
	i += ps_pa(stk1, stk2, out);
	i += ps_execute1(stk2, i - 1, out, ps_rrb);
	return (i);
}
