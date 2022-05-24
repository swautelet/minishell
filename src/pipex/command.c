/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:08:19 by swautele          #+#    #+#             */
/*   Updated: 2022/05/24 12:50:54 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_path_line(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T' &&
			env[i][3] == 'H' && env[i][4] == '=')
			return (i);
		i++;
	}
	return (-1);
}

char	*find_path(char *str, char *name)
{
	t_explore	e;

	if (name == NULL)
		return (NULL);
	if (access(name, X_OK) == 0)
	{
		e.temp = ft_calloc(sizeof(char), ft_strlen(name) + 1);
		if (e.temp == NULL)
			exit(1);
		e.j = -1;
		while (name[++e.j])
			e.temp[e.j] = name[e.j];
		return (e.temp);
	}
	e.possible = ft_split(str, ':');
	if (e.possible == NULL)
		exit(1);
	e.i = -1;
	while (e.possible[++e.i])
	{
		e.temp = ft_calloc(ft_strlen(e.possible[e.i]) + ft_strlen(name) + 2, 1);
		if (e.temp == NULL)
			exit(1);
		e.j = -1;
		while (e.possible[e.i][++e.j])
			e.temp[e.j] = e.possible[e.i][e.j];
		e.temp[e.j] = '/';
		e.j++;
		e.k = -1;
		while (name[++e.k])
			e.temp[e.j + e.k] = name[e.k];
		if (access(e.temp, X_OK) == 0)
		{
			free_table(e.possible);
			return (e.temp);
		}
		free(e.temp);
	}
	free_table(e.possible);
	return (NULL);
}

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
	printf("%s %p\n", p.arg[0], p.arg);
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
