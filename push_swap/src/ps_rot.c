/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 14:15:07 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/06 14:46:43 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_ra(t_istack *stk, int out)
{
	if (!stk)
		return (0);
	ft_rot_istack(stk);
	if (out == 1)
		write(STDOUT_FD, "ra\n", 3);
	return (1);
}

int	ps_rb(t_istack *stk, int out)
{
	if (!stk)
		return (0);
	ft_rot_istack(stk);
	if (out == 1)
		write(STDOUT_FD, "rb\n", 3);
	return (1);
}

int	ps_rr(t_istack *stk1, t_istack *stk2, int out)
{
	if (!stk1 || !stk2)
		return (0);
	ft_rot_istack(stk1);
	ft_rot_istack(stk2);
	if (out == 1)
		write(STDOUT_FD, "rr\n", 3);
	return (1);
}
