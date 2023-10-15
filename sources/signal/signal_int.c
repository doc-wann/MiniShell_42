/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:35:26 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/14 19:40:25 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
/*
The following functon is a very simple yer effective signal handler.
It receives the signal identificator, which we name Signum (signal number)

If the signal is suposed to kill the program execution, it will print a new line
and do nothing else. If the program receives any other signal, it shall keep the
program going, but making a few changes in it's operation.

Below is a list of the changes made. In the right there are their former uses,
and in the left, their actual uses.

ctrl-C displays a new prompt on a new line.		<- ctrl-C ends the program. 
ctrl-D exits the shell.			<- ctrl-D sends EOF to the terminal
ctrl-\ does nothing.			<- ctrl-\ sends a SIGQUIT command to the program

The case of ctrl-D is the trickiest to solve, since it is not a standard signal.
It simply returns EOF, which is 'sensed' by readline, therefore it's call for
action is in the loop function.
*/

void	signal_handler_sigint(int signum)
{
	if (signum == SIGINT)
		write(1, "\n", 1);
}

void	signal_handler_sigquit(int signum)
{
	if (signum == SIGQUIT)
		write(1, "\b\b\033[K", 6);
}
