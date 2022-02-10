/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quecpyn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:25:55 by gcontari          #+#    #+#             */
/*   Updated: 2022/02/04 14:37:04 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

t_queue2	*ft_quecpyn(t_queue2 *queue, void *(*cpy)(),
				size_t n, void (*del)())
{
	t_queue2		*new_que;
	t_queue_unit	*curr;
	void			*p;

	new_que = ft_questart();
	if (!new_que)
		return (NULL);
	curr = queue->rear;
	while (curr && n--)
	{
		p = cpy(curr->content);
		if (!p || !ft_enque(new_que, p))
		{
			ft_queclean(new_que, del);
			return (NULL);
		}
		curr = curr->next;
	}
	return (new_que);
}
