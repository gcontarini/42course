/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:20:27 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/22 18:21:17 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_checksort(t_istack *stk1, t_istack *stk2)
{
	t_isunit	*curr;

	if (stk2->top)
		return (0);
	curr = stk1->top;
	while (curr && curr->last)
	{
		if (curr->i > curr->last->i)
			return (0);
		curr = curr->last;
	}
	return (1);
}

int	ps_checksort_single(t_istack *stk)
{
	t_isunit	*curr;

	curr = stk->top;
	while (curr && curr->last)
	{
		if (curr->i > curr->last->i)
			return (0);
		curr = curr->last;
	}
	return (1);
}

int	ps_checksort_single2(t_istack *stk)
{
	t_isunit	*curr;

	curr = stk->top;
	while (curr && curr->last)
	{
		if (curr->i < curr->last->i)
			return (0);
		curr = curr->last;
	}
	return (1);
}
