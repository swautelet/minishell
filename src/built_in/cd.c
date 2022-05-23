/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:43:38 by swautele          #+#    #+#             */
/*   Updated: 2022/05/23 13:55:57 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	move_dir(t_param *data)
{
	// int		i;
	char	*path;
	char	*temp;
	t_list	*way;
	char	**fuck;

	// i = 2;
	// while (is_whitespace(data->str[i]) == TRUE)
	// 	i++;
	fuck = ft_split(data->str, ' ');
	if (fuck[1] == NULL)
	{
		chdir(my_getenv(data, "HOME"));
	}
	else if (fuck[1][0] == '/')
	{
		chdir(fuck[1]);
	}
	else
	{
		temp = ft_strjoin(my_getenv(data, "PWD"), "/");
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
		free(path);
	}
	free_table(fuck);
}
