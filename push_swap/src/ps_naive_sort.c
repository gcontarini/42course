/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_naive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:57:49 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/22 19:09:11 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_mv2mins(t_istack *stk1, t_istack *stk2, int out);
static int	mv_to_stk2(t_istack *stk1, t_istack *stk2, int value, int out);

int	ps_naive_sort(t_istack *stk1, t_istack *stk2, int out)
{
	ps_sa(stk1, out);
	if (ps_checksort(stk1, stk2))
		return (1);
	return (-1);
}

int	ps_3el_naive_sort(t_istack *stk1, t_istack *stk2, int out)
{
	int	min;
	int	i;

	i = 0;
	min = ps_min(stk1);
	if (ft_len_istack(stk1) < 3 || ps_checksort_single(stk1))
		return (-1);
	if (min == stk1->top->i
		|| (ps_max(stk1) == stk1->top->i
			&& min == stk1->base->i))
		i += ps_sa(stk1, out);
	if (stk1->top->i > stk1->top->last->i)
		i += ps_ra(stk1, out);
	else
		i += ps_rra(stk1, out);
	if (ps_checksort(stk1, stk2))
		return (i);
	return (-1);
}

int	ps_5el_naive_sort(t_istack *stk1, t_istack *stk2, int out)
{
	int	i;

	i = 0;
	if (ft_len_istack(stk1) < 5)
		return (-1);
	i += ps_mv2mins(stk1, stk2, out);
	if (stk1->top->i > stk1->top->last->i
		&& stk2->top->i < stk2->top->last->i)
		i += ps_ss(stk1, stk2, out);
	else if (stk1->top->i > stk1->top->last->i)
		i += ps_sa(stk1, out);
	else if (stk2->top->i < stk2->top->last->i)
		i += ps_sb(stk2, out);
	i += ps_3el_naive_sort(stk1, stk2, out);
	i += ps_pa(stk1, stk2, out);
	i += ps_pa(stk1, stk2, out);
	if (ps_checksort(stk1, stk2))
		return (i);
	return (-1);
}

static int	ps_mv2mins(t_istack *stk1, t_istack *stk2, int out)
{
	t_istack	*stkcpy;
	int			i;
	int			min;
	int			min2;

	stkcpy = ft_cpy_istack(stk1);
	if (!stkcpy || !ft_sort_istack(stkcpy))
	{
		ft_clean_istack(stkcpy);
		return (0);
	}
	min = ft_peek_istack(stkcpy, 0)->i;
	min2 = ft_peek_istack(stkcpy, 1)->i;
	ft_clean_istack(stkcpy);
	i = 0;
	if (steps_to_value(stk1, min) <= steps_to_value(stk1, min2))
	{
		i += mv_to_stk2(stk1, stk2, min, out);
		i += mv_to_stk2(stk1, stk2, min2, out);
		return (i);
	}
	i += mv_to_stk2(stk1, stk2, min2, out);
	i += mv_to_stk2(stk1, stk2, min, out);
	return (i);
}

static int	mv_to_stk2(t_istack *stk1, t_istack *stk2, int value, int out)
{
	int	i;

	i = 0;
	if (find_short_path(stk1, value))
		while (stk1->top->i != value)
			i += ps_ra(stk1, out);
	else
		while (stk1->top->i != value)
			i += ps_rra(stk1, out);
	i += ps_pb(stk1, stk2, out);
	return (i);
}
