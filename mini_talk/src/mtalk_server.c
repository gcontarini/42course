/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtalk_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:55:02 by gcontari          #+#    #+#             */
/*   Updated: 2022/02/09 20:07:12 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtalk.h"

t_message	g_msg;

int	main(void)
{	
	struct sigaction	action;

	if (!mtalk_start_msg(&g_msg, MTALK_BSIZE))
		return (mtalk_xerror("MEMORY ERROR"));
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = mtalk_listen;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	sigaction(SIGINT, &action, NULL);
	ft_printf("SERVER LISTENING...\nPID: %u\n", getpid());
	while (1)
		pause();
	return (0);
}

void	mtalk_listen(int sig, siginfo_t *info, void *uap)
{
	if (sig == SIGINT)
		mtalk_xclean(&g_msg, 0, "\nBye bye.");
	mtalk_getmsg(&g_msg, sig);
	if (g_msg.eomsg == 1)
	{
		ft_printf("%s", g_msg.p);
		kill(info->si_pid, SIGUSR2);
		g_msg.index = 0;
		g_msg.eomsg = 0;
	}
	(void) *uap;
}

void	mtalk_getmsg(t_message *msg, int signal)
{
	signal = signal - 30;
	msg->curr = (signal << msg->i) | msg->curr;
	if (++(msg->i) >= SIZE_CHAR)
	{
		if (msg->curr == 0)
			msg->eomsg = 1;
		else if (!mv_msg(msg))
			mtalk_xclean(msg, -1, "MEMORY ERROR");
		msg->i = 0;
		msg->curr = 0;
	}
}
