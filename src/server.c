/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:53:16 by bnespoli          #+#    #+#             */
/*   Updated: 2024/09/02 19:30:19 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	create_chr(int signo, siginfo_t *siginfo, void *context)
{
	static unsigned char	c;
	static unsigned int		bits_chr;

	(void)context;
	bits_chr++;
	if (signo == SIGUSR2)
			c |= 1;
	if (bits_chr == 8)
	{
		write (1, &c, 1);
		bits_chr = 0;
		c = 0;
	}
	c <<= 1;
	if (kill(siginfo->si_pid, SIGUSR1))
		exit(EXIT_FAILURE);
}

int	main(void)
{
	struct sigaction	create;

	create.sa_sigaction = create_chr;
	create.sa_flags = SA_SIGINFO;
	ft_printf("Server's PID is: %i\n\n", getpid());
	sigaction(SIGUSR1, &create, NULL);
	sigaction(SIGUSR2, &create, NULL);
	while (TRUE)
		pause();
}
