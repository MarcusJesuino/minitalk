/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:47:33 by masantos          #+#    #+#             */
/*   Updated: 2026/01/12 16:47:33 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void decode_signal(int sig, siginfo_t *info, void *ucontext)
{
	static int bits;
	static unsigned char current_c;
	static unsigned int bit_count;

	if (sig == SIGUSR1)
		bits = 0;
	else
		bits = 1;
	current_c = (current_c << 1) | bits;
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &current_c, 1);
		current_c = 0;
		bit_count = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int main(void)
{
	pid_t pid;
	struct sigaction actions;

	pid = getpid();
	sigemptyset(&actions.sa_mask);
	actions.sa_sigaction = decode_signal;
	actions.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &actions, NULL);
	sigaction(SIGUSR2, &actions, NULL);
	ft_printf("Server PID: %d\n", pid);
	while(1)
		pause();
}