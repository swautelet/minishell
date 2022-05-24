/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_escape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:25:49 by swautele          #+#    #+#             */
/*   Updated: 2022/05/24 14:09:35 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_escape(char **str)
{
	t_skip	f;

	f.i = -1;
	f.flag = 0;
	f.decal = 0;
	while (str && str[++f.i])
	{
		f.j = -1;
		while (str[f.i][++f.j] && str[f.i][f.j + f.decal])
		{
			if (str[f.i][f.j] == "'"[0] || str[f.i][f.j] == '"')
			{
				f.flag = str[f.i][f.j];
				f.decal++;
			}
			else if (f.flag != 0 && str[f.i][f.j + f.decal] == f.flag)
			{
				f.flag = 0;
				f.decal++;
			}
			str[f.i][f.j] = str[f.i][f.j + f.decal];
		}
	}
}
