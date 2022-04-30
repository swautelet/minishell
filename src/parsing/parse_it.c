/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:37:41 by swautele          #+#    #+#             */
/*   Updated: 2022/04/30 17:44:19 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_infile(t_param *data, int i)
{
	char	*name;

	if (data->str[i + 1] == '<')
	{
		data->str = my_cut_string(data->str, i, i + 1);
		name = find_next_element(data->str, i);
		while (data->str[i] == ' ' || data->str[i] == '\f' || data->str[i] == '\n'
			|| data->str[i] == '\r' || data->str[i] == '\t' || data->str[i] == '\v')
			i++;
		data->str = my_cut_string(data->str, i, i + (ft_strlen(name)));
		data->fdin = create_heredoc(name);
		printf("got heredoc infile name=%s\n", name);
		free(name);
	}
	else
	{
		data->str = my_cut_string(data->str, i, i);
		name = find_next_element(data->str, i);
		while (data->str[i] == ' ' || data->str[i] == '\f' || data->str[i] == '\n'
			|| data->str[i] == '\r' || data->str[i] == '\t' || data->str[i] == '\v')
			i++;
		data->str = my_cut_string(data->str, i, i + (ft_strlen(name)));
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
		data->str = my_cut_string(data->str, i, i + 1);
		name = find_next_element(data->str, i);
		while (data->str[i] == ' ' || data->str[i] == '\f' || data->str[i] == '\n'
			|| data->str[i] == '\r' || data->str[i] == '\t' || data->str[i] == '\v')
			i++;
		data->str = my_cut_string(data->str, i, i + (ft_strlen(name)));
		data->fdout = open(name, O_WRONLY | O_CREAT | O_APPEND);
		printf("got addoutfile name=%s\n", name);
		free(name);
	}
	else
	{
		data->str = my_cut_string(data->str, i, i);
		name = find_next_element(data->str, i);
		while (data->str[i] == ' ' || data->str[i] == '\f' || data->str[i] == '\n'
			|| data->str[i] == '\r' || data->str[i] == '\t' || data->str[i] == '\v')
			i++;
		data->str = my_cut_string(data->str, i, i + (ft_strlen(name)));
		data->fdout = open(name, O_WRONLY | O_CREAT | O_TRUNC);
		printf("got normal outfile name=%s\n", name);
		free(name);
	}
}

void	just_parse_it(t_param *data)
{
	int	i;

	i = -1;
	printf("i begin parsing\n");
	while (data->str[++i])
	{
		if (data->str[i] == '<')
			get_infile(data, i);
		if (data->str[i] == '>')
			get_outfile(data, i);
	}
	// pipex(str);
	printf("parsing done str = %s\nfdin = %d	fdout = %d\n", data->str, data->fdin, data->fdout);
	if (data->fdin != 0)
		close (data->fdin);
	if (data->fdout != 1)
		close (data->fdout);
	free (data->str);
}
