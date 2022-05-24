/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:17:12 by swautele          #+#    #+#             */
/*   Updated: 2022/05/24 11:50:04 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipex(t_param *data, char **envp, char **arg)
{
	t_read	r;
	// char	**arg;
	int		ids[21];

	r.i = 0;
	r.fd[r.i] = data->fdin;
	r.out = data->fdout;
	// arg = split_with_escape(data->str, '|');
	if (size_table(arg) > 20)
	{
		free_table(arg);
		exit_error("Error\nToo many pipe\n");
	}
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
			r.fd[r.i] = prep_command(arg[r.i - 1], envp, r.i - 1, ids);
		else
			ids[20] = prep_last_command(arg[r.i - 1], envp, r.out);
	}
	free (arg);
	write_and_exit(r, 1, ids);
	return (-1);
}

int	write_and_exit(t_read r, int first, int* ids)
{
	int	i;

	(void)first;
	i = 20;
	// printf("lastid = %d\n", ids[20]);
	while (i >= 0)
	{
		waitpid(ids[i], &r.len, 0);
		if (WIFEXITED(r.len) && i == 20)
		{
			close (0);
			// close (1);
			close(r.out);
			while (r.i >= first)
			{
				close(r.fd[r.i]);
				r.i--;
			}
		}
		else if (WIFSIGNALED(r.len) && i == 20)
		{
			g_data->lastex = WTERMSIG(r.len) + 128;
			if (WCOREDUMP(r.len))
				printf("Quit (core dumped)\n");
			else if (WTERMSIG(r.len) == SIGINT)
				printf("\n");
		}
		if (i == 20)
			while (ids[--i] == 0)
				;
		else
			i--;
	}
	// close(r.out);
	// while (r.i >= first)
	// {
	// 	close(r.fd[r.i]);
	// 	r.i--;
	// }
	exit(WEXITSTATUS(r.len));
}

void	exit_error(char *str)
{
	perror(str);
	exit(errno);
}
