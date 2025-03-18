/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:11:06 by bnespoli          #+#    #+#             */
/*   Updated: 2024/09/02 21:28:27 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include "../libft/libft.h"

//server.c
void	create_chr(int signo, siginfo_t *siginfo, void *context);

//client.c
int		ft_verify(int argc, char *pid);
void	signal_receipt(int signo);
void	send_bit(int server_pid, char c);

# define TRUE 1
# define FALSE 0

#endif