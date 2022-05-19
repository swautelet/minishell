/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:43:38 by swautele          #+#    #+#             */
/*   Updated: 2022/05/19 14:50:06 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	move_dir(t_param *data)
{
	int		i;
	char	*path;
	char	*temp;
	// char	*test;

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
		temp = ft_strjoin(getenv("PWD"), "/");
		path = ft_strjoin(temp, &data->str[i]);
		printf("i go to %s\n", path);
		chdir(path);
		// test = getenv("PWD");
		// test = getcwd(&str[i], 200);
		// printf("%s\n", getcwd(&str[i], 200));
		free (path);
		free (temp);
	}
	
}
