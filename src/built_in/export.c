/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:58:13 by swautele          #+#    #+#             */
/*   Updated: 2022/05/18 15:57:30 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	size_table(char **env)
{
	int	i;

	i = 0;
	if (!env)
		return (-1);
	while (env[i])
	{
		i++;
	}
	return (i);
}

// void	free_table(char **str)
// {
// 	int	i;

// 	i = -1;
// 	while (str[++i])
// 		free (str[i]);
// 	free (str);
// }

void	export_env(t_param *data)
{
	(void)data;
}
