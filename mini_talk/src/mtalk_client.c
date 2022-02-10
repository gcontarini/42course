/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtalk_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:00:27 by gcontari          #+#    #+#             */
/*   Updated: 2022/02/09 19:03:00 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtalk.h"

int	main(int ac, char *av[])
{
	struct sigaction	action;
	pid_t				server_pid;

	if (ac != 3)
		return (mtalk_xerror("INVALID USAGE."));
	server_pid = (unsigned int) ft_atoi(av[1]);
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	action.sa_handler = mtalk_confirm;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	sendmessage(server_pid, av[2]);
	sleep(10);
	ft_printf("MESSAGE NOT CONFIRMED\n");
	return (0);
}

void	mtalk_confirm(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("MESSAGE CONFIRMED\n");
	exit(0);
}

void	sendmessage(pid_t spid, const char *msg)
{
	unsigned int	i;
	unsigned int	j;
	int				signal;

	i = 0;
	while (msg[i])
	{
		j = 0;
		while (j < 8)
		{
			signal = ((msg[i] >> j++) & 1) + 30;
			kill(spid, signal);
			usleep(100);
		}
		i++;
	}
	i = 0;
	while (i++ < 8)
	{
		kill(spid, SIGUSR1);
		usleep(100);
	}
}
