/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 14:14:36 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/06 14:21:29 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_pa(t_istack *stk1, t_istack *stk2, int out)
{
	if (!stk1 || !stk2)
		return (0);
	ft_mvto_istack(stk2, stk1);
	if (out == 1)
		write(STDOUT_FD, "pa\n", 3);
	return (1);
}

int	ps_pb(t_istack *stk1, t_istack *stk2, int out)
{
	if (!stk1 || !stk2)
		return (0);
	ft_mvto_istack(stk1, stk2);
	if (out == 1)
		write(STDOUT_FD, "pb\n", 3);
	return (1);
}
