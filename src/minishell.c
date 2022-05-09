/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:28:24 by swautele          #+#    #+#             */
/*   Updated: 2022/05/09 22:56:42 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	buccle_readline(t_param *data)
{
	while (data->str)
	{
		// printf("readline i sumon you \n");
		// printf("test\n");
		data->str = readline(data->prompt);
		if (data->str && *data->str)
			add_history (data->str);
		data->fdin = 0;
		data->fdout = 1;
		if (strncmp("exit", data->str, 4) == 0 && (data->str[4] == '\0' || data->str[4] == ' ' || data->str[4] == '\t'))
			break ;
		else if (data->str)
			check_multiple_command(data, data->envp);
			// just_parse_it(data, envp);
	}
	free (data);
	write(1, "exit\n", 5);
	exit (0);
}

void	new_readline(int sig)
{
	// char	eof;

	kill(0, SIGINT);
	signal(2, &new_readline);
	(void)sig;
	// free (g_data->str);
	write(1, "\n", 1);
	// free (g_data->str);
	// g_data->str = readline(g_data->prompt);
	buccle_readline(g_data);
	// rl_redisplay();
	// rl_on_new_line();
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
	// const char	*prompt = "minishell$>";
	t_param		*data;

	(void)argc;
	(void)argv;
	data = malloc(sizeof(t_param));
	data->envp = envp;
	g_data = data;
	data->prompt = "minishell$>";
	signal(2, &new_readline);
	// data->str = readline(data->prompt);
	data->str = "";
	buccle_readline(data);
	free (data);
	write(1, "exit\n", 5);
	return (0);
}
