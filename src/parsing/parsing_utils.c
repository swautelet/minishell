/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:36:27 by simonwautel       #+#    #+#             */
/*   Updated: 2022/05/25 11:10:34 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	launching_pipex(t_param *data, char **arg)
{
	int	status;

	if (!data->str)
		minishell_free_and_exit();
	if (arg[1] == NULL && check_built_in(data) == TRUE)
		;
	else
	{
		data->id = fork();
		if (data->id == 0)
			pipex(data, convert_to_char(data->envp), arg);
		else
			waitpid(data->id, &status, 0);
		data->lastex = WEXITSTATUS(status);
	}
	if (data->fdin != 0)
		close(data->fdin);
	if (data->fdout != 1)
		close(data->fdout);
	free(data->str);
}
