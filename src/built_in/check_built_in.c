/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_built_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:03:02 by swautele          #+#    #+#             */
/*   Updated: 2022/05/18 19:09:56 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_buit_in(t_param *data)
{
	// int	i;

	
	if (strncmp("cd", data->str, 2) == 0 && (is_whitespace(data->str[2]) == TRUE || !data->str[2]))
	{
		move_dir(data);
		// ralloc_cut_string(data->str, )
	}
	if (strncmp("export", data->str, 6) == 0 && (is_whitespace(data->str[6]) == TRUE || !data->str[6]))
	{
		export_env(data);
		return (1);
	}
	if (strncmp("unset", data->str, 5) == 0 && (is_whitespace(data->str[5]) == TRUE || !data->str[5]))
	{
		unset_env(data);
		return (1);
	}
	return (0);
}

int	check_built_in_output(char *str, char **envp)
{
	// printf("|%s|\n", str);
	if (strncmp("env", str, 3) == 0 && (is_whitespace(str[3]) == TRUE || !str[3]))
	{
		write_table(envp);
		return (TRUE);
	}
	if (strncmp("pwd", str, 3) == 0 && (is_whitespace(str[3]) == TRUE || !str[3]))
	{
		where_am_i();
		return (TRUE);
	}
	if (strncmp("echo", str, 4) == 0 && (is_whitespace(str[4]) == TRUE || !str[4]))
	{
		write_echo(str);
		return (TRUE);
	}
	return (FALSE);
}

int	check_echo(char *str)
{
	if (strncmp("echo", str, 4) == 0 && (is_whitespace(str[4]) == TRUE || !str[4]))
	{
		return (TRUE);
	}
	if (strncmp("env", str, 3) == 0 && (is_whitespace(str[3]) == TRUE || !str[3]))
	{
		return (TRUE);
	}
	if (strncmp("pwd", str, 3) == 0 && (is_whitespace(str[3]) == TRUE || !str[3]))
	{
		return (TRUE);
	}
	return (FALSE);
}
