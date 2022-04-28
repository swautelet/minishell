/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:28:24 by swautele          #+#    #+#             */
/*   Updated: 2022/04/28 19:35:13 by swautele         ###   ########.fr       */
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
	while (data)
	{
		data->str = readline(prompt);
		data->fdin = 0;
		data->fdout = 1;
		just_parse_it(data);
		printf("str = %s	fdin = %d	fdout = %d\n", data->str, data->fdin, data->fdout);
	}
	free (data);
	return (0);
}
