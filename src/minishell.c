/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:28:24 by swautele          #+#    #+#             */
/*   Updated: 2022/05/09 18:22:10 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	new_readline(int sig)
{
	// char	eof;

	(void)sig;
	rl_redisplay();
	rl_on_new_line();
	// rl_replace_line();
	// g_data->str = readline("\nprompt$>");
	// printf("%d\n", sig);
	// rl_replace_line();
	// eof = 0;
	// write(1, &eof, 1);
	// free (g_data->str);
	// g_data->str = readline("minishell$>");
}

int	main(int argc, char **argv, char **envp)
{
	const char	*prompt = "minishell$>";
	t_param		*data;

	(void)argc;
	(void)argv;
	data = malloc(sizeof(t_param));
	g_data = data;
	signal(2, &new_readline);
	data->str = readline(prompt);
	while (data->str)
	{
		// printf("readline i sumon you \n");
		// printf("test\n");
		if (data->str && *data->str)
			add_history (data->str);
		data->fdin = 0;
		data->fdout = 1;
		if (strncmp("exit", data->str, 4) == 0 && (data->str[4] == '\0' || data->str[4] == ' ' || data->str[4] == '\t'))
			break ;
		else if (data->str)
			check_multiple_command(data, envp);
			// just_parse_it(data, envp);
		data->str = readline(prompt);
	}
	free (data);
	write(1, "exit\n", 5);
	return (0);
}
