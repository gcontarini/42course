/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_one_stack_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:48:04 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/17 16:33:49 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_short_path_min(t_istack *stk, int min);

int	ps_selection_sort(t_istack *stk1, t_istack *stk2, int out)
{
	int			i;
	int			min;

	i = 0;
	while (stk1->top && !ps_checksort_single(stk1))
	{
		min = ps_min(stk1);
		if (find_short_path_min(stk1, min))
			while (stk1->top->i != min)
				i += ps_ra(stk1, out);
		else
			while (stk1->top->i != min)
				i += ps_rra(stk1, out);
		i += ps_pb(stk1, stk2, out);
	}
	while (stk2->top)
		i += ps_pa(stk1, stk2, out);
	return (i);
}

static int	find_short_path_min(t_istack *stk, int min)
{
	size_t		steps;
	t_isunit	*curr;

	curr = stk->top;
	steps = 0;
	while (curr->i != min)
	{
		steps++;
		curr = curr->last;
	}
	if (steps < ft_len_istack(stk) / 2)
		return (1);
	return (0);
}
