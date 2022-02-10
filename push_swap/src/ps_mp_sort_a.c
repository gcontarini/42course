/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_md_sort_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:38:00 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/23 11:00:58 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get2min(t_istack *stk, int depth, int *min1, int *min2);
static int	mv2min_pb(t_istack *stk1, t_istack *stk2, int depth, int out);
static int	find_pb(t_istack *stk1, t_istack *stk2, int value, int out);

int	el3_sort1(t_istack *stk1, t_istack *stk2, int depth, int out)
{
	int	i;

	i = 0;
	if (stk2->top && stk1->top->last && stk2->top->last
		&& stk1->top->i > stkget(stk1, 1) && stk2->top->i < stkget(stk2, 1))
		i += ps_ss(stk1, stk2, out);
	else if (stk2->top && stk2->top->last && stk2->top->i < stkget(stk2, 1))
		i += ps_sb(stk2, out);
	else if (stk1->top->i > stkget(stk1, 1))
		i += ps_sa(stk1, out);
	if (depth < 3 || (stkget(stk1, 1) < stkget(stk1, 2)))
		return (i);
	if (stk1->top->i < stkget(stk1, 2))
	{
		i += ps_pb(stk1, stk2, out);
		i += ps_sa(stk1, out);
		i += ps_pa(stk1, stk2, out);
		return (i);
	}
	i += do_pb_2times(stk1, stk2, out);
	i += ps_ra(stk1, out);
	i += do_pa_2times(stk1, stk2, out);
	i += ps_rra(stk1, out);
	return (i);
}

int	el5_sort1(t_istack *stk1, t_istack *stk2, int depth, int out)
{
	int	i;
	int	j;

	if (depth < 4)
		return (el3_sort1(stk1, stk2, depth, out));
	i = 0;
	i += mv2min_pb(stk1, stk2, depth, out);
	i += el3_sort1(stk1, stk2, depth - 2, out);
	j = 2;
	while (j--)
		i += ps_pa(stk1, stk2, out);
	return (i);
}

static int	get2min(t_istack *stk, int depth, int *min1, int *min2)
{
	t_istack	*stkcpy;

	stkcpy = ps_cpy_depth_istack(stk, depth);
	if (!stkcpy || !ft_sort_istack(stkcpy))
	{
		ft_clean_istack(stkcpy);
		return (0);
	}
	*min1 = ft_peek_istack(stkcpy, 0)->i;
	*min2 = ft_peek_istack(stkcpy, 1)->i;
	ft_clean_istack(stkcpy);
	return (1);
}

static int	mv2min_pb(t_istack *stk1, t_istack *stk2, int depth, int out)
{
	int			i;
	int			min1;
	int			min2;

	if (!get2min(stk1, depth, &min1, &min2))
		return (0);
	i = 0;
	if (steps_to_value(stk1, min1) < steps_to_value(stk1, min2))
	{
		i += find_pb(stk1, stk2, min1, out);
		i += find_pb(stk1, stk2, min2, out);
		return (i);
	}
	i += find_pb(stk1, stk2, min2, out);
	i += find_pb(stk1, stk2, min1, out);
	return (i);
}

static int	find_pb(t_istack *stk1, t_istack *stk2, int value, int out)
{
	int	i;

	i = 0;
	while (stk1->top && stk1->top->i != value)
		i += ps_ra(stk1, out);
	i += ps_pb(stk1, stk2, out);
	i += ps_execute1(stk1, i - 1, out, ps_rra);
	return (i);
}
