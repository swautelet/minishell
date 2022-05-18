/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:58:13 by swautele          #+#    #+#             */
/*   Updated: 2022/05/18 12:10:01 by swautele         ###   ########.fr       */
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

char	**export_env(t_param *data)
{
	char	**new;
	int		i;
	int		j;
	int		k;

	new = ft_calloc(size_table(data->envp) + 2, sizeof(char *));
	i = -1;
	while (data->envp[++i])
	{
		new[i] = ft_calloc(sizeof(char), ft_strlen(data->envp[i]));
		j = -1;
		while (data->envp[i][++j])
			new[i][j] = data->envp[i][j];
	}
	j = 6;
	while (is_whitespace(data->str[j]) == TRUE)
		j++;
	new[i] = ft_calloc(sizeof(char), ft_strlen(&data->str[j]));
	j--;
	k = 0;
	while (data->str[++j])
		new[i][k++] = data->str[j];
	return (new);
}
