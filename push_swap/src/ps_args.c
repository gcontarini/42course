/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:32:04 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/23 12:16:35 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_check_args(int ac, char *av[])
{
	long	n;
	char	*p;
	int		i;

	if (ac < 2)
		ps_xerror("");
	i = 1;
	while (av[i])
	{
		if (!ps_onlydigits(av[i]))
			ps_xerror("Error\n");
		n = ps_atol(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			ps_xerror("Error\n");
		p = ft_strchr(av[i++], ' ');
		while (p)
		{
			n = ps_atol(p);
			if (n > INT_MAX || n < INT_MIN)
				ps_xerror("Error\n");
			p = ft_strchr(p + 1, ' ');
		}
	}
	return ;
}

int	ps_check_dup(t_istack *stk)
{
	t_isunit	*curr1;
	t_isunit	*curr2;

	curr1 = stk->top;
	while (curr1)
	{
		curr2 = curr1->last;
		while (curr2)
		{
			if (curr1->i == curr2->i)
				return (0);
			curr2 = curr2->last;
		}
		curr1 = curr1->last;
	}
	return (1);
}

int	ps_arg2stack(t_istack *stk, int ac, char *av[])
{
	int		i;
	char	*trim;
	char	*p;

	i = 1;
	while (i < ac)
	{
		trim = ft_strtrim(av[i++], " ");
		if (!trim)
			return (0);
		if (!ft_addbase_istack(stk, ft_atoi(trim)))
			return (ps_memerror_int(trim));
		p = ft_strchr(trim, ' ');
		while (p && *p)
		{
			if (*(p + 1) != ' ' && *(p + 1) != 0)
				if (!ft_addbase_istack(stk, ft_atoi(p)))
					return (ps_memerror_int(trim));
			p = ft_strchr(p + 1, ' ');
		}
		free(trim);
	}
	return (1);
}
