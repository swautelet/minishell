/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_escape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:25:49 by swautele          #+#    #+#             */
/*   Updated: 2022/05/18 16:30:15 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_escape(char **str)
{
	int		i;
	char	flag;
	int		j;

	i = 0;
	flag = 0;
	while (str && str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == "'"[0] || str[i][j] == '"')
				flag == str[i][j];
			else if (flag != 0 && str[i][j] == flag)
			{
				flag = 0;
			}
			if (flag != 0)
			{
				str[i][j] = str[i][j + 1];
			}
			j++;
		}
	}
}