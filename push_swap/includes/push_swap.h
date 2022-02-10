/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:02:12 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/23 10:06:34 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include "ft_stack.h"

# define TOT_ALGOS 8
# define STDERR_FD 2
# ifndef STDOUT_FD
#  define STDOUT_FD 1
# endif

typedef int	(*t_fnsort)(t_istack *, t_istack *, int);
typedef int	(*t_ps1)(t_istack *, int);
typedef int	(*t_ps2)(t_istack *, t_istack *, int);

typedef struct s_radix_utilities
{
	size_t		max_bits;
	size_t		bits;
	size_t		max_number;
	size_t		i;
}	t_radix_utils;

// ps_main
t_fnsort		ps_find_best_algo(t_istack *stk1, t_istack *stk2, t_fnsort *sa);
void			fill_fnsortarr(t_fnsort *sort_algo);

// ps_args
void			ps_check_args(int ac, char *av[]);
int				ps_check_dup(t_istack *stk);
int				ps_arg2stack(t_istack *stk, int ac, char *av[]);

// ps_errors
void			ps_xmemerror(t_istack *stk1, t_istack *stk2);
void			ps_xduperror(t_istack *stk1, t_istack *stk2);
void			ps_xerror(char *errmsg);
int				ps_memerror_int(char *str);

// ps_utils
long			ps_atol(const char *str);
int				ps_onlydigits(char *str);
unsigned int	ps_min_index(int *arr, size_t len);
int				stkget(t_istack *stk, size_t index);

// ps_stats
int				ps_min(t_istack *stk);
int				ps_max(t_istack *stk);
int				ps_median(t_istack *stk);

// ps_stats_depth
int				ps_min_depth(t_istack *stk, int depth);
int				ps_max_depth(t_istack *stk, int depth);
int				ps_median_depth(t_istack *stk, int depth);

// ps_swap
int				ps_sa(t_istack *stk, int out);
int				ps_sb(t_istack *stk, int out);
int				ps_ss(t_istack *stk1, t_istack *stk2, int out);

// ps_push
int				ps_pa(t_istack *stk1, t_istack *stk2, int out);
int				ps_pb(t_istack *stk1, t_istack *stk2, int out);

// ps_rot
int				ps_ra(t_istack *stk, int out);
int				ps_rb(t_istack *stk, int out);
int				ps_rr(t_istack *stk1, t_istack *stk2, int out);

// ps_rrot
int				ps_rra(t_istack *stk, int out);
int				ps_rrb(t_istack *stk, int out);
int				ps_rrr(t_istack *stk1, t_istack *stk2, int out);

// ps_stack
t_istack		*ps_cpy_depth_istack(t_istack *stk, int depth);
int				find_short_path(t_istack *stk, int value);
int				steps_to_value(t_istack *stk, int value);

// ps_checksort
int				ps_checksort(t_istack *stk1, t_istack *stk2);
int				ps_checksort_single(t_istack *stk);
int				ps_checksort_single2(t_istack *stk);

// ps_execute
int				ps_execute1(t_istack *stk, int n, int out, t_ps1 f);
int				do_pa_2times(t_istack *stk1, t_istack *stk2, int out);
int				do_pb_2times(t_istack *stk1, t_istack *stk2, int out);

// ps_naive_sort
int				ps_naive_sort(t_istack *stk1, t_istack *stk2, int out);
int				ps_3el_naive_sort(t_istack *stk1, t_istack *stk2, int out);
int				ps_5el_naive_sort(t_istack *stk1, t_istack *stk2, int out);

// ps_insert_sort
int				ps_insert_sort(t_istack *stk1, t_istack *stk2, int out);
int				ps_insert_sort2(t_istack *stk1, t_istack *stk2, int out);

// ps_selection_sort
int				ps_selection_sort(t_istack *stk1, t_istack *stk2, int out);

// ps_mp_sort
int				ps_midpoint_sort(t_istack *stk1, t_istack *stk2, int out);
// ps_mp_sort_a
int				el3_sort1(t_istack *stk1, t_istack *stk2, int depth, int out);
int				el5_sort1(t_istack *stk1, t_istack *stk2, int depth, int out);

// ps_mp_sort_b
int				el3_sort2(t_istack *stk1, t_istack *stk2, int depth, int out);
int				el5_sort2(t_istack *stk1, t_istack *stk2, int depth, int out);

// ps_radix_sort
int				ps_radix_sort(t_istack *stk1, t_istack *stk2, int out);

#endif
