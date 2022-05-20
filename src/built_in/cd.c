/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:43:38 by swautele          #+#    #+#             */
/*   Updated: 2022/05/20 15:08:43 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	move_dir(t_param *data)
{
	int		i;
	char	*path;
	char	*temp;
	t_list	*way;

	i = 2;
	while (is_whitespace(data->str[i]) == TRUE)
		i++;
	if (data->str[i] == '/')
	{
		chdir(&data->str[i]);
	}
	else
	{
		temp = ft_strjoin(my_getenv(data, "PWD"), "/");
		path = ft_strjoin(temp, &data->str[i]);
		free(temp);
		if (chdir(path) == 0)
		{
			way = ft_lstsearch(data->envp, "PWD");
			free(way->content);
			temp = where_am_i();
			way->content = ft_strjoin("PWD=", temp);
		}
		free(temp);
		free(path);
	}
}
