/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:37:41 by swautele          #+#    #+#             */
/*   Updated: 2022/05/16 15:34:49 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_infile(t_param *data, int i)
{
	char	*name;

	if (data->str[i + 1] == '<')
	{
		data->str = ralloc_cut_string(data->str, i, i + 1);
		name = find_next_name(data, i);
		while (is_whitespace(data->str[i]) == TRUE)
			i++;
		data->str = ralloc_cut_string(data->str, i, i + (ft_strlen(name)));
		if (name[0] == '"' || name[0] == "'"[0])
		{
			name = ralloc_cut_string(name, ft_strlen(name)
					- 1, ft_strlen(name) - 1);
			name = ralloc_cut_string(name, 0, 0);
		}
		data->fdin = create_heredoc(name);
		free(name);
	}
	else
	{
		data->str = ralloc_cut_string(data->str, i, i);
		name = find_next_name(data, i);
		while (is_whitespace(data->str[i]) == TRUE)
			i++;
		data->str = ralloc_cut_string(data->str, i, i + (ft_strlen(name)));
		if (name[0] == '"' || name[0] == "'"[0])
		{
			name = ralloc_cut_string(name, ft_strlen(name)
					- 1, ft_strlen(name) - 1);
			name = ralloc_cut_string(name, 0, 0);
		}
		data->fdin = open(name, O_RDONLY);
		free(name);
	}
}

static void	get_outfile(t_param *data, int i)
{
	char	*name;

	if (data->str[i + 1] == '>')
	{
		data->str = ralloc_cut_string(data->str, i, i + 1);
		name = find_next_name(data, i);
		while (is_whitespace(data->str[i]) == TRUE)
			i++;
		data->str = ralloc_cut_string(data->str, i, i + (ft_strlen(name)));
		if (name[0] == '"' || name[0] == "'"[0])
		{
			name = ralloc_cut_string(name, ft_strlen(name)
					- 1, ft_strlen(name) - 1);
			name = ralloc_cut_string(name, 0, 0);
		}
		data->fdout = open(name, O_WRONLY | O_CREAT | O_APPEND);
		free(name);
	}
	else
	{
		data->str = ralloc_cut_string(data->str, i, i);
		name = find_next_name(data, i);
		while (is_whitespace(data->str[i]) == TRUE)
			i++;
		data->str = ralloc_cut_string(data->str, i, i + (ft_strlen(name)));
		if (name[0] == '"' || name[0] == "'"[0])
		{
			name = ralloc_cut_string(name, ft_strlen(name)
					- 1, ft_strlen(name) - 1);
			name = ralloc_cut_string(name, 0, 0);
		}
		data->fdout = open(name, O_WRONLY | O_CREAT | O_TRUNC);
		free(name);
	}
}

void	just_parse_it(t_param *data, char **envp)
{
	int	i;
	int	status;

	i = -1;
	while (data->str[++i])
	{
		if (data->str[i] == '<')
			get_infile(data, i);
		if (data->str[i] == '>')
			get_outfile(data, i);
	}
	data->id = fork();
	if (data->id == 0)
		pipex(data, envp);
	else
		waitpid(data->id, &status, 0);
	data->lastex = WEXITSTATUS(status);
	if (data->fdin != 0)
		close (data->fdin);
	if (data->fdout != 1)
		close (data->fdout);
	free (data->str);
}
