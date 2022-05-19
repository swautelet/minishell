/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:43:38 by swautele          #+#    #+#             */
/*   Updated: 2022/05/19 16:57:32 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	move_dir(t_param *data)
{
	int		i;
	char	*path;
	char	*temp;
	// char	*test;
	t_list	*way;

	i = 2;
	// printf("%s\n", str);
	while (is_whitespace(data->str[i]) == TRUE)
		i++;
	if (data->str[i] == '/')
	{
		// printf("i go to %s\n", &str[i]);
		chdir(&data->str[i]);
	}
	else
	{
		// way = ft_lstsearch(data->envp, )
		temp = ft_strjoin(my_getenv(data, "PWD"), "/");
		path = ft_strjoin(temp, &data->str[i]);
		free (temp);
		// printf("i go to %s\n", path);
		if (chdir(path) == 0)
		{
			way = ft_lstsearch(data->envp, "PWD");
			free(way->content);
			temp = where_am_i();
			way->content = ft_strjoin("PWD=", temp);
		}
		// test = getenv("PWD");
		// test = getcwd(&str[i], 200);
		// printf("%s\n", getcwd(&str[i], 200));
		free (temp);
		free (path);
	}
	
}
