/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:43:38 by swautele          #+#    #+#             */
/*   Updated: 2022/05/18 14:36:43 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	move_dir(char *str)
{
	int		i;
	char	*path;
	char	*temp;
	// char	*test;

	i = 2;
	// printf("%s\n", str);
	while (is_whitespace(str[i]) == TRUE)
		i++;
	if (str[i] == '/')
	{
		// printf("i go to %s\n", &str[i]);
		chdir(&str[i]);
	}
	else
	{
		temp = ft_strjoin(getenv("PWD"), "/");
		path = ft_strjoin(temp, &str[i]);
		// printf("i go to %s\n", path);
		chdir(path);
		// test = getenv("PWD");
		// test = getcwd(&str[i], 200);
		// printf("%s\n", getcwd(&str[i], 200));
		free (path);
		free (temp);
	}
}
