/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:58:15 by swautele          #+#    #+#             */
/*   Updated: 2022/05/20 15:08:44 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*where_am_i(void)
{
	int		i;
	char	*path;

	i = 20;
	path = ft_calloc(sizeof(char), i);
	while (getcwd(path, i - 1) == NULL)
	{
		i *= 2;
		free(path);
		path = ft_calloc(sizeof(char), i);
	}
	return (path);
}
