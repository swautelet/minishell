/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:28:24 by swautele          #+#    #+#             */
/*   Updated: 2022/05/10 17:40:03 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	buccle_readline(t_param *data)
{
	// if (signal(SIGINT, new_readline) == SIG_ERR)
	// 	printf("failed to register interrupts with kernel\n");
	// write_table(data->envp);
	while (data->str)
	{
		// printf("readline i sumon you \n");
		data->str = readline(data->prompt);
		if (data->str && *data->str)
			add_history (data->str);
		data->fdin = 0;
		data->fdout = 1;
		if (data->str && ft_strncmp("exit", data->str, 4) == 0 && (data->str[4] == '\0' || data->str[4] == ' ' || data->str[4] == '\t'))
			break ;
		// printf("test\n");
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

	// kill(0, SIGSTOP);
	printf("received sig %d\n", sig);
	kill(g_data->id, SIGINT);
	// signal(2, &new_readline);
	// (void)sig;
	// write(0, "\n", 1);
	write(1, "\n", 1);
	g_data->str = readline(g_data->prompt);
	return ;
	// if (signal(SIGINT, new_readline) == SIG_ERR)
	// 	printf("failed to register interrupts with kernel\n");
	// free (g_data->str);
	// free (g_data->str);
	// g_data->str = readline(g_data->prompt);
	// buccle_readline(*g_data);
	// rl_on_new_line();
	// g_data->str = readline(g_data->prompt);	
	// rl_replace_line();
	// g_data->str = readline("\nprompt$>");
	// printf("%d\n", sig);
	// rl_replace_line();
	// eof = 0;
	// write(1, &eof, 1);
	// free (g_data->str);
	// g_data->str = readline("minishell$>");
}

void	write_table(char **envp)
{
	int	i;

	if (envp)
	{
		i = -1;
		while (envp[++i])
			printf("%s\n", envp[i]);
	}
}

int	main(int argc, char **argv, char **envp)
{
	// const char	*prompt = "minishell$>";
	t_param		*data;

	(void)argc;
	(void)argv;
	data = malloc(sizeof(t_param));
	data->envp = envp;
	data->prompt = "minishell$>";
	data->str = "";
	data->lastex = 0;
	g_data = data;
	// write_table(data->envp);
	if (signal(SIGINT, new_readline) == SIG_ERR)
		printf("failed to register interrupts with kernel\n");
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		printf("failed to register interrupts with kernel\n");
	// data->str = readline(data->prompt);
	buccle_readline(data);
	free (data);
	write(1, "exit\n", 5);
	return (0);
}
