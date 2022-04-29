/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:28:24 by swautele          #+#    #+#             */
/*   Updated: 2022/04/29 17:11:57 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	const char	*prompt = "minishell$>";
	t_param		*data;

	(void)argc;
	(void)argv;
	(void)envp;
	data = malloc(sizeof(t_param));
	while (1)
	{
		data->str = readline(prompt);
		data->fdin = 0;
		data->fdout = 1;
		if (data->str)
			just_parse_it(data);
	}
	free (data);
	return (0);
}
