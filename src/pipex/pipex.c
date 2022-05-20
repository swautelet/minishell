/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:17:12 by swautele          #+#    #+#             */
/*   Updated: 2022/05/20 15:08:47 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipex(t_param *data, char **envp)
{
	t_read	r;
	char	**arg;

	r.i = 0;
	r.fd[r.i] = data->fdin;
	r.out = data->fdout;
	arg = split_with_escape(data->str, '|');
	if (arg[0] == NULL)
		return (1);
	while (arg[r.i] != NULL)
	{
		r.i++;
		if (r.fd[r.i - 1] != 0)
		{
			if (dup2(r.fd[r.i - 1], 0) == -1)
				exit_error("dup2 failed");
		}
		if (arg[r.i] != NULL)
			r.fd[r.i] = prep_command(arg[r.i - 1], envp);
		else
			prep_last_command(arg[r.i - 1], envp, r.out);
	}
	write_and_exit(r, 1);
	return (-1);
}

int	write_and_exit(t_read r, int first)
{
	close(r.out);
	while (waitpid(-1, &r.len, 0) != -1)
		;
	while (r.i >= first)
	{
		close(r.fd[r.i]);
		r.i--;
	}
	exit(WEXITSTATUS(r.len));
}

void	exit_error(char *str)
{
	perror(str);
	exit(errno);
}
