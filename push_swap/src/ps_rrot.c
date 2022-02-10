/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cmds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 14:00:27 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/06 14:33:10 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_rra(t_istack *stk, int out)
{
	if (!stk)
		return (0);
	ft_rrot_istack(stk);
	if (out == 1)
		write(STDOUT_FD, "rra\n", 4);
	return (1);
}

int	ps_rrb(t_istack *stk, int out)
{
	if (!stk)
		return (0);
	ft_rrot_istack(stk);
	if (out == 1)
		write(STDOUT_FD, "rrb\n", 4);
	return (1);
}

int	ps_rrr(t_istack *stk1, t_istack *stk2, int out)
{
	if (!stk1 || !stk2)
		return (0);
	ft_rrot_istack(stk1);
	ft_rrot_istack(stk2);
	if (out == 1)
		write(STDOUT_FD, "rrr\n", 4);
	return (1);
}
