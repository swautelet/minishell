/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:37:41 by swautele          #+#    #+#             */
/*   Updated: 2022/05/24 14:16:12 by swautele         ###   ########.fr       */
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
		data->fdin = create_heredoc(name);
	}
	else
	{
		data->str = ralloc_cut_string(data->str, i, i);
		name = find_next_name(data, i);
		data->fdin = open(name, O_RDONLY);
	}
	free(name);
	name = find_next_element(data, i);
	while (is_whitespace(data->str[i]) == TRUE)
		i++;
	data->str = ralloc_cut_string(data->str, i, i + (ft_strlen(name) - 1));
	free(name);
}

static void	get_outfile(t_param *data, int i)
{
	char	*name;

	if (data->str[i + 1] == '>')
	{
		data->str = ralloc_cut_string(data->str, i, i + 1);
		name = find_next_name(data, i);
		data->fdout = open(name, O_WRONLY | O_CREAT | O_APPEND, 00644);
	}
	else
	{
		data->str = ralloc_cut_string(data->str, i, i);
		name = find_next_name(data, i);
		data->fdout = open(name, O_WRONLY | O_CREAT | O_TRUNC, 00644);
	}
	free(name);
	while (is_whitespace(data->str[i]) == TRUE)
		i++;
	name = find_next_element(data, i);
	data->str = ralloc_cut_string(data->str, i, i + (ft_strlen(name) - 1));
	free(name);
}

static void	prepare_pipex(t_param *data)
{
	char	**arg;
	int		i;
	int		status;

	arg = split_with_escape(data->str, '|');
	i = -1;
	while (arg[++i])
		arg[i] = insert_variable(arg[i]);
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

void	just_parse_it(t_param *data)
{
	int		i;
	char	flag;

	flag = 0;
	i = -1;
	while (data->str[++i])
	{
		if ((data->str[i] == '"' || data->str[i] == "'"[0]) && flag == 0)
			flag = data->str[i];
		else if (flag == data->str[i] && flag != 0)
			flag = 0;
		if (data->str[i] == '<' && flag == 0)
			get_infile(data, i);
		if (data->str[i] == '>' && flag == 0)
			get_outfile(data, i);
	}
	prepare_pipex(data);
}
