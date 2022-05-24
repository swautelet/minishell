/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:17:12 by swautele          #+#    #+#             */
/*   Updated: 2022/05/24 17:21:34 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipex(t_param *data, char **envp, char **arg)
{
	t_read	r;
	int		ids[21];

	r.i = 0;
	r.fd[r.i] = data->fdin;
	r.out = data->fdout;
	if (size_table(arg) > 20)
	{
		free_table(arg);
		exit_error("Error\nToo many pipe\n");
	}
	if (arg[0] == NULL)
		return (1);
	while (arg[r.i++] != NULL)
	{
		if (r.fd[r.i - 1] != 0 && dup2(r.fd[r.i - 1], 0) == -1)
			exit_error("dup2 failed");
		if (arg[r.i] != NULL)
			r.fd[r.i] = prep_command(arg[r.i - 1], envp, r.i - 1, ids);
		else
			ids[20] = prep_last_command(arg[r.i - 1], envp, r.out);
	}
	free (arg);
	write_and_exit(r, ids);
	return (-1);
}

static int	decrease_i(int i, int *ids)
{
	if (i == 20)
		while (ids[--i] == 0)
			;
	else
		i--;
	return (i);
}

int	write_and_exit(t_read r, int *ids)
{
	int	i;

	i = 20;
	while (i >= 0)
	{
		waitpid(ids[i], &r.len, 0);
		if (WIFEXITED(r.len) && i == 20)
		{
			close(r.out);
			r.i++;
			while (--r.i >= 0)
				close(r.fd[r.i]);
		}
		else if (WIFSIGNALED(r.len) && i == 20)
		{
			g_data->lastex = WTERMSIG(r.len) + 128;
			if (WCOREDUMP(r.len))
				printf("Quit (core dumped)\n");
			else if (WTERMSIG(r.len) == SIGINT)
				printf("\n");
		}
		i = decrease_i(i, ids);
	}
	exit(WEXITSTATUS(r.len));
}

void	exit_error(char *str)
{
	perror(str);
	exit(errno);
}
