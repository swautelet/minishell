/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:58:15 by swautele          #+#    #+#             */
/*   Updated: 2022/05/18 18:56:09 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	where_am_i(void)
{
	int		i;
	char	*path;

	i = 20;
	path = ft_calloc(sizeof(char), i);
	while (getcwd(path, i - 1) == NULL)
	{
		i *= 2;
		free (path);
		path = ft_calloc(sizeof(char), i);
	}
	printf("%s\n", path);
	free (path);
}
