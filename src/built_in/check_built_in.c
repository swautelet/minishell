/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_built_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:03:02 by swautele          #+#    #+#             */
/*   Updated: 2022/05/17 17:39:38 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_buit_in(t_param *data)
{
	char	**temp;

	if (strncmp("echo", data->str, 4) == 0 && is_whitespace(data->str[4]) == TRUE)
	{
		write_echo(data);
		return (1);
	}
	if (strncmp("cd", data->str, 2) == 0 && is_whitespace(data->str[2]) == TRUE)
	{
		move_dir(data->str);
		return (1);
	}
	if (strncmp("pwd", data->str, 3) == 0 && is_whitespace(data->str[3]) == TRUE)
	{
		where_am_i(data);
		return (1);
	}
	if (strncmp("export", data->str, 6) == 0 && is_whitespace(data->str[6]) == TRUE)
	{
		temp = export_env(data);
		free (data->envp);
		data->envp = temp;
		return (1);
	}
	if (strncmp("unset", data->str, 5) == 0 && is_whitespace(data->str[5]) == TRUE)
	{
		unset_env(data);
		return (1);
	}
	if (strncmp("env", data->str, 3) == 0 && is_whitespace(data->str[3]) == TRUE)
	{
		write_table(data->envp);
		return (1);
	}
	return (0);
}