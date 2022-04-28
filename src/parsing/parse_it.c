/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:37:41 by swautele          #+#    #+#             */
/*   Updated: 2022/04/28 19:36:11 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_infile(t_param *data, int i)
{
	char	*name;

	if (data->str[i + 1] == '>')
	{
		data->str = my_cut_string(data->str, i, i + 2);
		name = find_next_element(data->str, i + 2);
		while (data->str[i] == ' ' || data->str[i] == '\f' || data->str[i] == '\n'
			|| data->str[i] == '\r' || data->str[i] == '\t' || data->str[i] == '\v')
			i++;
		data->str = my_cut_string(data->str, i, i + (ft_strlen(name)));
		data->fdin = create_heredoc(name);
		dup2(data->fdin, 0);
		free(name);
	}
	else
	{
		data->str = my_cut_string(data->str, i, i + 1);
		name = find_next_element(data->str, i + 1);
		while (data->str[i] == ' ' || data->str[i] == '\f' || data->str[i] == '\n'
			|| data->str[i] == '\r' || data->str[i] == '\t' || data->str[i] == '\v')
			i++;
		data->str = my_cut_string(data->str, i, i + (ft_strlen(name)));
		data->fdin = open(name, O_RDONLY);
		dup2(data->fdin, 0);
		free(name);
	}
}

static void	get_outfile(t_param *data, int i)
{
	char	*name;

	if (data->str[i + 1] == '<')
	{
		data->str = my_cut_string(data->str, i, i + 2);
		name = find_next_element(data->str, i + 2);
		while (data->str[i] == ' ' || data->str[i] == '\f' || data->str[i] == '\n'
			|| data->str[i] == '\r' || data->str[i] == '\t' || data->str[i] == '\v')
			i++;
		data->str = my_cut_string(data->str, i, i + (ft_strlen(name)));
		data->fdout = open(name, O_WRONLY | O_CREAT | O_APPEND);
		dup2(data->fdout, 1);
		free(name);
	}
	else
	{
		data->str = my_cut_string(data->str, i, i + 1);
		name = find_next_element(data->str, i + 1);
		while (data->str[i] == ' ' || data->str[i] == '\f' || data->str[i] == '\n'
			|| data->str[i] == '\r' || data->str[i] == '\t' || data->str[i] == '\v')
			i++;
		data->str = my_cut_string(data->str, i, i + (ft_strlen(name)));
		data->fdout = open(name, O_WRONLY | O_CREAT | O_TRUNC);
		dup2(data->fdout, 0);
		free(name);
	}
}

void	just_parse_it(t_param *data)
{
	int	i;

	i = -1;
	while (data->str[++i])
	{
		if (data->str[i] == '<')
			get_infile(data, i);
		if (data->str[i] == '>')
			get_outfile(data, i);
	}
	// pipex(str);
	printf("str = %s	fdin = %d	fdout = %d\n", data->str, data->fdin, data->fdout);
	if (data->fdin != 0)
		close (data->fdin);
	if (data->fdout != 1)
		close (data->fdout);
}
