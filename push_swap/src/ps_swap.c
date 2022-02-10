/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 14:13:58 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/06 14:25:34 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_sa(t_istack *stk, int out)
{
	if (!stk)
		return (0);
	ft_swap_istack(stk);
	if (out == 1)
		write(STDOUT_FD, "sa\n", 3);
	return (1);
}

int	ps_sb(t_istack *stk, int out)
{
	if (!stk)
		return (0);
	ft_swap_istack(stk);
	if (out == 1)
		write(STDOUT_FD, "sb\n", 3);
	return (1);
}

int	ps_ss(t_istack *stk1, t_istack *stk2, int out)
{
	if (!stk1 || !stk2)
		return (0);
	ft_swap_istack(stk1);
	ft_swap_istack(stk2);
	if (out == 1)
		write(STDOUT_FD, "ss\n", 3);
	return (1);
}
