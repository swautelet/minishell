/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:37:41 by swautele          #+#    #+#             */
/*   Updated: 2022/05/09 15:07:44 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_infile(t_param *data, int i)
{
	char	*name;

	if (data->str[i + 1] == '<')
	{
		data->str = ralloc_cut_string(data->str, i, i + 1);
		name = find_next_element(data, i);
		while (data->str[i] == ' ' || data->str[i] == '\f' || data->str[i] == '\n'
			|| data->str[i] == '\r' || data->str[i] == '\t' || data->str[i] == '\v')
			i++;
		data->str = ralloc_cut_string(data->str, i, i + (ft_strlen(name)));
		if (name[0] == '"' || name[0] == "'"[0])
		{
			name = ralloc_cut_string(name, ft_strlen(name) - 1, ft_strlen(name) - 1);
			name = ralloc_cut_string(name, 0, 0);
		}
		data->fdin = create_heredoc(name);
		printf("got heredoc infile name=%s\n", name);
		free(name);
	}
	else
	{
		data->str = ralloc_cut_string(data->str, i, i);
		name = find_next_element(data, i);
		while (data->str[i] == ' ' || data->str[i] == '\f' || data->str[i] == '\n'
			|| data->str[i] == '\r' || data->str[i] == '\t' || data->str[i] == '\v')
			i++;
		data->str = ralloc_cut_string(data->str, i, i + (ft_strlen(name)));
		if (name[0] == '"' || name[0] == "'"[0])
		{
			name = ralloc_cut_string(name, ft_strlen(name) - 1, ft_strlen(name) - 1);
			name = ralloc_cut_string(name, 0, 0);
		}
		data->fdin = open(name, O_RDONLY);
		printf("got normal infile name=%s\n", name);
		free(name);
	}
}

static void	get_outfile(t_param *data, int i)
{
	char	*name;

	if (data->str[i + 1] == '>')
	{
		data->str = ralloc_cut_string(data->str, i, i + 1);
		name = find_next_element(data, i);
		while (data->str[i] == ' ' || data->str[i] == '\f' || data->str[i] == '\n'
			|| data->str[i] == '\r' || data->str[i] == '\t' || data->str[i] == '\v')
			i++;
		data->str = ralloc_cut_string(data->str, i, i + (ft_strlen(name)));
		if (name[0] == '"' || name[0] == "'"[0])
		{
			name = ralloc_cut_string(name, ft_strlen(name) - 1, ft_strlen(name) - 1);
			name = ralloc_cut_string(name, 0, 0);
		}
		data->fdout = open(name, O_WRONLY | O_CREAT | O_APPEND);
		printf("got addoutfile name=%s\n", name);
		free(name);
	}
	else
	{
		data->str = ralloc_cut_string(data->str, i, i);
		name = find_next_element(data, i);
		while (data->str[i] == ' ' || data->str[i] == '\f' || data->str[i] == '\n'
			|| data->str[i] == '\r' || data->str[i] == '\t' || data->str[i] == '\v')
			i++;
		data->str = ralloc_cut_string(data->str, i, i + (ft_strlen(name)));
		if (name[0] == '"' || name[0] == "'"[0])
		{
			name = ralloc_cut_string(name, ft_strlen(name) - 1, ft_strlen(name) - 1);
			name = ralloc_cut_string(name, 0, 0);
		}
		data->fdout = open(name, O_WRONLY | O_CREAT | O_TRUNC);
		printf("got normal outfile name=%s\n", name);
		free(name);
	}
}

void	just_parse_it(t_param *data, char **envp)
{
	int	i;
	int	id;
	int	status;

	i = -1;
	// printf("i begin parsing\n");
	while (data->str[++i])
	{
		if (data->str[i] == '<')
			get_infile(data, i);
		if (data->str[i] == '>')
			get_outfile(data, i);
	}
	id = fork();
	if (id == 0)
		pipex(data, envp);
	else
		waitpid(id, &status, 0);
	// printf("parsing done str = %s\nfdin = %d	fdout = %d\n", data->str, data->fdin, data->fdout);
	if (data->fdin != 0)
		close (data->fdin);
	if (data->fdout != 1)
		close (data->fdout);
	free (data->str);
}
