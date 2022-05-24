/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:43:38 by swautele          #+#    #+#             */
/*   Updated: 2022/05/24 12:31:47 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	move_dir(t_param *data)
{
	char	*path;
	char	*temp;
	t_list	*way;
	char	**fuck;

	fuck = ft_split(data->str, ' ');
	if (fuck[1] == NULL)
	{
		if (chdir(my_getenv(data, "HOME")) == -1)
			perror(my_getenv(data, "HOME"));
	}
	else if (fuck[1][0] == '/')
	{
		if (chdir(fuck[1]) == -1)
			perror(fuck[1]);
	}
	else
	{
		path = where_am_i();
		temp = ft_strjoin(path, "/");
		free (path);
		path = ft_strjoin(temp, fuck[1]);
		free(temp);
		if (chdir(path) == 0)
		{
			way = ft_lstsearch(data->envp, "PWD");
			free(way->content);
			temp = where_am_i();
			way->content = ft_strjoin("PWD=", temp);
			free(temp);
		}
		else
			perror(path);
		free(path);
	}
	free_table(fuck);
}
