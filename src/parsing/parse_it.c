/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:37:41 by swautele          #+#    #+#             */
/*   Updated: 2022/04/29 15:00:35 by simonwautel      ###   ########.fr       */
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
		dup2(data->fdin, 0);
		free(name);
	}
	else
	{
		printf("str = %s\nfdin = %d	fdout = %d\n", data->str, data->fdin, data->fdout);
		data->str = my_cut_string(data->str, i, i);
		printf("str = %s\nfdin = %d	fdout = %d\n", data->str, data->fdin, data->fdout);
		name = find_next_element(data->str, i);
		printf("str = %s\nfdin = %d	fdout = %d\n", data->str, data->fdin, data->fdout);
		while (data->str[i] == ' ' || data->str[i] == '\f' || data->str[i] == '\n'
			|| data->str[i] == '\r' || data->str[i] == '\t' || data->str[i] == '\v')
			i++;
		data->str = my_cut_string(data->str, i, i + (ft_strlen(name)));
		printf("str = %s\nfdin = %d	fdout = %d\n", data->str, data->fdin, data->fdout);
		data->fdin = open(name, O_RDONLY);
		printf("str = %s\nfdin = %d	fdout = %d\n", data->str, data->fdin, data->fdout);
		dup2(data->fdin, 0);
		printf("str = %s\nfdin = %d	fdout = %d\n", data->str, data->fdin, data->fdout);
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
		dup2(data->fdout, 1);
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
	if (data->fdin != 0)
		close (data->fdin);
	printf(" boucle done str = %s\nfdin = %d	fdout = %d\n", data->str, data->fdin, data->fdout);
	if (data->fdout != 1)
		close (data->fdout);
	free (data->str);
}
