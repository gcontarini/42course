/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:07:13 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/22 18:21:13 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_istack	*ps_cpy_depth_istack(t_istack *stk, int depth)
{
	t_istack	*new_stk;
	t_isunit	*curr;

	new_stk = ft_start_istack();
	if (!new_stk)
		return (NULL);
	curr = stk->top;
	while (curr && depth--)
	{
		if (!ft_addbase_istack(new_stk, curr->i))
		{
			ft_clean_istack(new_stk);
			return (NULL);
		}
		curr = curr->last;
	}
	return (new_stk);
}

int	find_short_path(t_istack *stk, int value)
{
	size_t		steps;
	t_isunit	*curr;

	curr = stk->top;
	steps = 0;
	while (curr->i != value)
	{
		steps++;
		curr = curr->last;
	}
	if (steps < ft_len_istack(stk) / 2)
		return (1);
	return (0);
}

int	steps_to_value(t_istack *stk, int value)
{
	size_t		steps;
	t_isunit	*curr;

	curr = stk->top;
	steps = 0;
	while (curr->i != value)
	{
		steps++;
		curr = curr->last;
	}
	if (steps < ft_len_istack(stk) / 2)
		return (steps);
	return (ft_len_istack(stk) - steps);
}
