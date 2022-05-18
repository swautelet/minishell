/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_escape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:25:49 by swautele          #+#    #+#             */
/*   Updated: 2022/05/18 19:08:14 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_escape(char **str)
{
	int		i;
	char	flag;
	int		j;
	int		decal;

	i = -1;
	flag = 0;
	decal = 0;
	while (str && str[++i])
	{
		j = -1;
		while (str[i][++j] && str[i][j + decal])
		{
			if (str[i][j] == "'"[0] || str[i][j] == '"')
			{
				flag = str[i][j];
				decal++;
			}
			else if (flag != 0 && str[i][j + decal] == flag)
			{
				flag = 0;
				decal++;
			}
			str[i][j] = str[i][j + decal];
			// printf("%s\n", str[i]);
		}
		// str[i][j - 1] = '\0';
	}
}
