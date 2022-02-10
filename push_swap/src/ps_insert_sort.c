/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_naive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:06:19 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/17 16:42:07 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_insert_sort(t_istack *stk1, t_istack *stk2, int out)
{
	t_isunit	*curr;
	int			i;

	i = 0;
	while (ps_checksort(stk1, stk2) == 0)
	{
		while (stk1->top)
		{
			curr = stk1->top->last;
			if (curr && stk1->top->i > curr->i)
				i += ps_sa(stk1, out);
			i += ps_pb(stk1, stk2, out);
		}
		while (stk2->top)
			i += ps_pa(stk1, stk2, out);
	}
	return (i);
}

int	ps_insert_sort2(t_istack *stk1, t_istack *stk2, int out)
{
	t_isunit	*curr;
	int			i;

	i = 0;
	while (ps_checksort(stk1, stk2) == 0)
	{
		while (stk1->top && !ps_checksort_single(stk1))
		{
			curr = stk1->top->last;
			if (curr && stk1->top->i > curr->i)
				i += ps_sa(stk1, out);
			i += ps_pb(stk1, stk2, out);
		}
		while (stk2->top)
		{
			curr = stk2->top->last;
			if (curr && stk2->top->i < curr->i)
				i += ps_sb(stk2, out);
			i += ps_pa(stk1, stk2, out);
		}
	}
	return (i);
}
