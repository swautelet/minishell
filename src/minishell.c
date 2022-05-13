/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:28:24 by swautele          #+#    #+#             */
/*   Updated: 2022/05/13 12:44:18 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	buccle_readline(t_param *data)
{
	while (data->str)
	{
		data->str = readline(data->prompt);
		data->fdin = 0;
		data->fdout = 1;
		if (data->str && ft_strncmp("exit", data->str, 4) == 0
			&& (is_whitespace(data->str[4]) == TRUE || !data->str[4]))
			break ;
		else if (data->str)
			check_multiple_command(data, data->envp);
	}
	free (data);
	write(1, "exit\n", 5);
	exit (0);
}

void	new_readline(int sig)
{
	(void)sig;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	return ;
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
	t_param		*data;

	(void)argc;
	(void)argv;
	data = malloc(sizeof(t_param));
	data->envp = envp;
	data->prompt = "minishell$>";
	data->str = "";
	data->id = 1;
	data->lastex = 0;
	g_data = data;
	if (signal(SIGINT, new_readline) == SIG_ERR)
		printf("failed to register interrupts with kernel\n");
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		printf("failed to register interrupts with kernel\n");
	buccle_readline(data);
	free (data);
	write(1, "exit\n", 5);
	return (0);
}
