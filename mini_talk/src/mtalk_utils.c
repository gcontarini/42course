/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtalk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:53:14 by gcontari          #+#    #+#             */
/*   Updated: 2022/02/09 19:12:07 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtalk.h"

void	mtalk_xclean(t_message *msg, int status, const char *errmsg)
{
	if (msg->p)
		free(msg->p);
	ft_printf("%s\n", errmsg);
	exit(status);
}

int	mtalk_xerror(const char *msg)
{
	ft_printf("%s\n", msg);
	exit(-1);
	return (-1);
}

int	mv_msg(t_message *msg)
{
	unsigned char	*tmp;

	if (msg->index >= msg->tot_size)
	{
		msg->tot_size *= 2;
		tmp = malloc((msg->tot_size + 1) * sizeof(unsigned char));
		if (!tmp)
			return (0);
		ft_strlcpy((char *) tmp, (const char *) msg->p, msg->index + 1);
		free(msg->p);
		msg->p = tmp;
	}
	(msg->p)[msg->index++] = msg->curr;
	(msg->p)[msg->index] = 0;
	return (1);
}

int	mtalk_start_msg(t_message *msg, unsigned int n)
{
	msg->tot_size = n;
	msg->index = 0;
	msg->eomsg = 0;
	msg->curr = 0;
	msg->i = 0;
	msg->p = (unsigned char *) malloc((n + 1) * sizeof(unsigned char));
	if (!msg->p)
		return (0);
	return (1);
}
