/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 10:52:08 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/22 18:34:29 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_execute1(t_istack *stk, int n, int out, t_ps1 f)
{
	int	i;

	i = 0;
	while (n--)
		i += f(stk, out);
	return (i);
}

int	do_pa_2times(t_istack *stk1, t_istack *stk2, int out)
{
	int	i;

	i = 2;
	while (i--)
		ps_pa(stk1, stk2, out);
	return (2);
}

int	do_pb_2times(t_istack *stk1, t_istack *stk2, int out)
{
	int	i;

	i = 2;
	while (i--)
		ps_pb(stk1, stk2, out);
	return (2);
}
