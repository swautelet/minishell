/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:19:49 by swautele          #+#    #+#             */
/*   Updated: 2022/05/24 11:44:01 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <limits.h>
# include <stdio.h>

typedef struct s_path{
	int		pl;
	char	*path;
	char	**arg;
	int		pip[2];
	int		id;
	int		w;
}	t_path;

typedef struct s_read{
	int		i;
	int		fd[FOPEN_MAX];
	char	buffer[1000];
	int		out;
	int		len;
}	t_read;

typedef struct s_fuck{
	char	**possible;
	int		i;
	char	*temp;
	int		j;
	int		k;
}	t_explore;

typedef struct s_exit{
	int	fd;
	int	excod;
}	t_exit;

typedef struct s_param{
	char		*str;
	int			fdin;
	int			fdout;
	const char	*prompt;
	t_list		*envp;
	int			lastex;
	int			id;
}	t_param;

int		find_path_line(char **envp);
void	free_table(char **str);
char	*find_path(char *str, char *name);
int		prep_command(char *argv, char **envp, int pos, int *ids);
int		f_strcmp(char *str1, char *str2);
int		write_and_exit(t_read r, int first, int *lastid);
void	exit_error(char *str);
int		pipex(t_param *data, char **envp, char **arg);

#endif