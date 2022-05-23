/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:49:24 by swautele          #+#    #+#             */
/*   Updated: 2022/05/23 15:02:48 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	last_command(char *path, char **arg, char **env, int fdout)
{
	int	ret;

	ret = check_built_in_output(arg[0], env);
	if (path == NULL && ret == FALSE)
		exit_error("command not found");
	if (fdout != 1)
	{
		if (dup2(fdout, 1) == -1)
			exit_error("failed to dup2");
	}
	if (ret == 0)
		return (execve(path, arg, env));
	else
	{
		free(path);
		free_table(arg);
		exit(0);
	}
}

int	prep_last_command(char *argv, char **envp, int fdout)
{
	t_path	p;
	int		flag;

	flag = check_echo(argv);
	if (flag == FALSE)
	{
		p.arg = split_with_escape(argv, ' ');
		remove_escape(p.arg);
	}
	else
		p.arg = split_with_escape(argv, '\0');
	if (p.arg == NULL)
		exit(1);
	p.pl = find_path_line(envp);
	p.path = find_path(&envp[p.pl][5], p.arg[0]);
	p.id = fork();
	// printf("lastid = %d\n", p.id);
	if (p.id == -1)
		exit_error("failed to fork");
	if (p.id == 0)
		last_command(p.path, p.arg, envp, fdout);
	free(p.path);
	free_table(p.arg);
	return (p.id);
}