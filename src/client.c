/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:28:22 by masantos          #+#    #+#             */
/*   Updated: 2026/01/12 16:28:22 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

volatile sig_atomic_t	g_ack_sig = 0;

static void	ack_handler(int signal)
{
	(void)signal;
	g_ack_sig = 1;
}

static void	signal_encoder(pid_t server_pid, char strchar, unsigned int i)
{
	char	bit;

	while (i--)
	{
		g_ack_sig = 0;
		bit = (strchar >> i) & 1;
		if (bit == 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		while (!g_ack_sig)
			pause();
	}
}

int	main(int ac, char **av)
{
	struct sigaction	actions;
	size_t				i;
	size_t				len;

	if (ac != 3)
		return (0);
	sigemptyset(&actions.sa_mask);
	actions.sa_handler = ack_handler;
	actions.sa_flags = 0;
	sigaction(SIGUSR1, &actions, NULL);
	i = 0;
	len = ft_strlen(av[2]);
	while (i < len + 1)
		signal_encoder(ft_atoi(av[1]), av[2][i++], 8);
	return (0);
}
