/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:19:49 by swautele          #+#    #+#             */
/*   Updated: 2022/05/10 17:38:50 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <limits.h>

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

typedef struct s_command{
	char		*str;
	int			fdin;
	int			fdout;
	const char	*prompt;
	char		**envp;
	int			lastex;
	int			id;
}	t_param;

int		find_path_line(char **envp);
void	free_table(char **str);
char	*find_path(char *str, char *name);
int		prep_command(char *argv, char **envp);
int		f_strcmp(char *str1, char *str2);
int		write_and_exit(t_read r, int first);
void	exit_error(char *str);
int		pipex(t_param *data, char **envp);

#endif