/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:02:11 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/23 11:53:32 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	normalize_values(t_istack *stk);
static int	rot_or_pb(t_istack *stk1, t_istack *stk2, t_radix_utils r, int out);
static int	rot_or_pa(t_istack *stk1, t_istack *stk2, t_radix_utils r, int out);
static void	find_replace_value(t_isunit *stk, t_istack *stkcpy);

int	ps_radix_sort(t_istack *stk1, t_istack *stk2, int out)
{
	t_radix_utils	radix;
	size_t			i;

	if (!normalize_values(stk1))
		return (-1);
	radix.max_number = ft_len_istack(stk1) - 1;
	radix.max_bits = 0;
	while (radix.max_number >> radix.max_bits != 0)
		radix.max_bits++;
	radix.bits = 0;
	i = 0;
	while (radix.bits < radix.max_bits && !ps_checksort(stk1, stk2))
	{
		i += rot_or_pb(stk1, stk2, radix, out);
		radix.bits++;
		i += rot_or_pa(stk1, stk2, radix, out);
	}
	while (stk2->top)
		i += ps_pa(stk1, stk2, out);
	return (i);
}

static int	rot_or_pb(t_istack *stk1, t_istack *stk2, t_radix_utils r, int out)
{
	int	i;

	i = 0;
	r.i = 0;
	r.max_number = ft_len_istack(stk1);
	while (r.i++ < r.max_number && !ps_checksort_single(stk1))
	{
		if (stk1->top
			&& ((stk1->top->i >> r.bits) & 1) == 1)
			i += ps_ra(stk1, out);
		else if (stk1->top)
			i += ps_pb(stk1, stk2, out);
	}
	return (i);
}

static int	rot_or_pa(t_istack *stk1, t_istack *stk2, t_radix_utils r, int out)
{
	int	i;

	i = 0;
	r.i = 0;
	r.max_number = ft_len_istack(stk2);
	while (r.i++ < r.max_number)
	{
		if (r.bits == r.max_bits && ps_checksort_single2(stk2))
			break ;
		if (stk2->top
			&& ((stk2->top->i >> r.bits) & 1) == 0)
			i += ps_rb(stk2, out);
		else if (stk2->top)
			i += ps_pa(stk1, stk2, out);
	}
	return (i);
}

static int	normalize_values(t_istack *stk)
{
	t_istack	*stkcpy;
	t_isunit	*curr;

	stkcpy = ft_cpy_istack(stk);
	if (!stkcpy || !ft_sort_istack(stkcpy))
	{
		ft_clean_istack(stkcpy);
		return (0);
	}
	curr = stk->top;
	while (curr)
	{
		find_replace_value(curr, stkcpy);
		curr = curr->last;
	}
	ft_clean_istack(stkcpy);
	return (1);
}

static void	find_replace_value(t_isunit *stk, t_istack *stkcpy)
{
	t_isunit	*curr;
	int			i;

	curr = stkcpy->top;
	i = 0;
	while (curr && stk->i != curr->i)
	{
		i++;
		curr = curr->last;
	}
	stk->i = i;
	return ;
}
