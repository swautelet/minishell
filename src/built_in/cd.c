/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:43:38 by swautele          #+#    #+#             */
/*   Updated: 2022/05/24 16:39:36 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	new_pwd(t_param *data)
{
	t_list	*way;
	char	*temp;

	way = ft_lstsearch(data->envp, "PWD");
	free(way->content);
	temp = where_am_i();
	way->content = ft_strjoin("PWD=", temp);
	free(temp);
}

static void	move_from_here(char **fuck, t_param *data)
{
	char	*path;
	char	*temp;

	path = where_am_i();
	temp = ft_strjoin(path, "/");
	free (path);
	path = ft_strjoin(temp, fuck[1]);
	free(temp);
	if (chdir(path) == 0)
	{
		new_pwd(data);
	}
	else
		perror(path);
	free(path);
}

void	move_dir(t_param *data)
{
	char	**fuck;

	fuck = ft_split(data->str, ' ');
	if (fuck[1] == NULL)
	{
		if (chdir(my_getenv(data, "HOME")) == -1)
			perror(my_getenv(data, "HOME"));
		else
			new_pwd(data);
	}
	else if (fuck[1][0] == '/')
	{
		if (chdir(fuck[1]) == -1)
			perror(fuck[1]);
		else
			new_pwd(data);
	}
	else
		move_from_here(fuck, data);
	free_table(fuck);
}
