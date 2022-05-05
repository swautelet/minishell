/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:17:12 by swautele          #+#    #+#             */
/*   Updated: 2022/05/05 20:28:51 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

int	pipex(t_param *data, char **envp)
{
	t_read	r;
	char	**arg;
	// int		i;

	r.i = 0;
	r.fd[r.i] = data->fdin;
	r.out = data->fdout;
	arg = split_with_escape(data->str, '|');
	if (arg[0] == NULL)
		return (0);
	// i = 0;
	// while (arg[i])
	// {
	// 	printf("%s\n", arg[i]);
		// i++;
	// }
	while (arg[r.i] != NULL)
	{
		r.i++;
		if (r.fd[r.i - 1] != 0)
			if (dup2(r.fd[r.i - 1], 0) == -1)
				exit_error("dup2 failed");
		r.fd[r.i] = prep_command(arg[r.i - 1], envp);
	}
	write_and_exit (r, 1);
	return (-1);
}

int	write_and_exit(t_read r, int first)
{
	r.len = read(r.fd[r.i], r.buffer, 999);
	if (r.len == -1)
		perror("failed to read");
	while (r.len > 0)
	{
		write(r.out, r.buffer, r.len);
		r.len = read(r.fd[r.i], r.buffer, 999);
	}
	close(r.out);
	while (waitpid(-1, &r.len, 0) != -1)
		;
	while (r.i >= first)
	{
		close (r.fd[r.i]);
		r.i--;
	}
	exit (WEXITSTATUS(r.len));
}

void	exit_error(char *str)
{
	perror(str);
	exit (errno);
}

// void	free_table(char **str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		free (str[i]);
// 		i++;
// 	}
// 	free(str);
// }
