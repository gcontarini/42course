/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:58:06 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/23 11:06:24 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_fnsort	sort_algo[TOT_ALGOS];
	t_istack	*stack_a;
	t_istack	*stack_b;

	ps_check_args(ac, av);
	stack_a = ft_start_istack();
	stack_b = ft_start_istack();
	if (!stack_a || !stack_b)
		ps_xmemerror(stack_a, stack_b);
	if (!ps_arg2stack(stack_a, ac, av))
		ps_xmemerror(stack_a, stack_b);
	if (!ps_check_dup(stack_a))
		ps_xduperror(stack_a, stack_b);
	fill_fnsortarr(sort_algo);
	if (!ps_checksort(stack_a, stack_b))
		(ps_find_best_algo(stack_a, stack_b, sort_algo)(stack_a, stack_b, 1));
	ft_clean_istack(stack_a);
	ft_clean_istack(stack_b);
	return (0);
}

t_fnsort	ps_find_best_algo(t_istack *stk1, t_istack *stk2, t_fnsort *sa)
{
	t_istack	*stkcpy;
	int			mvs[TOT_ALGOS];
	int			i;

	i = 0;
	while (i < TOT_ALGOS)
	{
		stkcpy = ft_cpy_istack(stk1);
		if (!stkcpy)
			ps_xmemerror(stk1, stk2);
		mvs[i] = sa[i](stkcpy, stk2, 0);
		ft_clean_istack(stkcpy);
		i++;
	}
	return (sa[ps_min_index(mvs, TOT_ALGOS)]);
}

void	fill_fnsortarr(t_fnsort *sort_algo)
{
	sort_algo[0] = ps_insert_sort;
	sort_algo[1] = ps_selection_sort;
	sort_algo[2] = ps_insert_sort2;
	sort_algo[3] = ps_naive_sort;
	sort_algo[4] = ps_3el_naive_sort;
	sort_algo[5] = ps_5el_naive_sort;
	sort_algo[6] = ps_radix_sort;
	sort_algo[7] = ps_midpoint_sort;
}
