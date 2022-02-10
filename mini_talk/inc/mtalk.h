/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtalk.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:03:47 by gcontari          #+#    #+#             */
/*   Updated: 2022/02/09 19:11:41 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTALK_H
# define MTALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "ft_printf.h"
# include "libft.h"

# define MTALK_BSIZE 200
# define SIZE_CHAR 8

typedef struct s_mtalk_darray
{
	unsigned char	*p;
	unsigned int	tot_size;
	unsigned int	index;	
	unsigned char	curr;	
	unsigned int	i;	
	unsigned char	eomsg;
}	t_message;

extern t_message	g_msg;

// mtalk_server
void	mtalk_listen(int sig, siginfo_t *info, void *uap);
void	mtalk_getmsg(t_message *msg, int signal);

// mtalk_client
void	sendmessage(pid_t spid, const char *msg);
void	mtalk_confirm(int signal);

// mtalk_utils
int		mtalk_xerror(const char *msg);
void	mtalk_xclean(t_message *msg, int status, const char *errmsg);
int		mv_msg(t_message *msg);
int		mtalk_start_msg(t_message *msg, unsigned int n);

#endif
