/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:25:23 by swautele          #+#    #+#             */
/*   Updated: 2022/05/25 11:58:05 by swautele         ###   ########.fr       */
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

static char	*test_possibilities(t_explore e, char *name)
{
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

char	*find_path(char *str, char *name)
{
	t_explore	e;

	if (name == NULL || name[0] == '\0')
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
	return (test_possibilities(e, name));
}
