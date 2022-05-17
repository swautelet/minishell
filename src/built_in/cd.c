/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:43:38 by swautele          #+#    #+#             */
/*   Updated: 2022/05/17 16:21:41 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	move_dir(char *str)
{
	int		i;
	char	*path;

	i = 2;
	while (is_whitespace(str[i]) == TRUE)
		i++;
	if (str[i] == '/')
		chdir(&str[i]);
	else
	{
		path = ft_strjoin(getenv("pwd"), &str[i]);
		chdir(path);
		free (path);
	}
}
