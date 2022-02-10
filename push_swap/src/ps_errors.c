/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:31:14 by gcontari          #+#    #+#             */
/*   Updated: 2021/12/17 14:18:59 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_xmemerror(t_istack *stk1, t_istack *stk2)
{
	if (stk1)
		ft_clean_istack(stk1);
	if (stk2)
		ft_clean_istack(stk2);
	ps_xerror("Memory Error\n");
	return ;
}

void	ps_xduperror(t_istack *stk1, t_istack *stk2)
{
	if (stk1)
		ft_clean_istack(stk1);
	if (stk2)
		ft_clean_istack(stk2);
	ps_xerror("Error\n");
	return ;
}

void	ps_xerror(char *errmsg)
{
	write(STDERR_FD, errmsg, ft_strlen(errmsg));
	exit(EXIT_FAILURE);
}

int	ps_memerror_int(char *str)
{
	free(str);
	return (0);
}
