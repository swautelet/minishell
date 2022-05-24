/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:08:19 by swautele          #+#    #+#             */
/*   Updated: 2022/05/24 17:26:09 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	command(char *path, char **arg, char **env, int pip[2])
{
	int	ret;

	close(pip[0]);
	if (dup2(pip[1], 1) == -1)
		exit_error("failed to dup2");
	ret = check_built_in_output(arg[0], env);
	if (path == NULL && ret == FALSE)
		exit_error("command not found");
	if (ret == 0)
		return (execve(path, arg, env));
	else
	{
		free(path);
		close(pip[1]);
		free_table(arg);
		exit(0);
	}
}

int	prep_command(char *argv, char **envp, int pos, int *ids)
{
	t_path	p;
	int		flag;

	cut_beginning_whitespace(argv);
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
	if (pipe(p.pip) == -1)
		exit_error("failed to pipe");
	ids[pos] = fork();
	if (ids[pos] == -1)
		exit_error("failed to fork");
	if (ids[pos] == 0)
		command(p.path, p.arg, envp, p.pip);
	close(p.pip[1]);
	free(p.path);
	free_table(p.arg);
	return (p.pip[0]);
}
