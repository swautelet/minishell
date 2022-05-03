/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:28:24 by swautele          #+#    #+#             */
/*   Updated: 2022/05/03 14:41:06 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	const char	*prompt = "minishell$>";
	t_param		*data;

	(void)argc;
	(void)argv;
	data = malloc(sizeof(t_param));
	data->str = "1";
	while (data)
	{
		// printf("readline i sumon you \n");
		data->str = readline(prompt);
		// printf("test\n");
		data->fdin = 0;
		data->fdout = 1;
		if (strncmp("exit", data->str, 6) == 0)
			break ;
		else if (data->str)
			just_parse_it(data, envp);
	}
	free (data);
	return (0);
}
