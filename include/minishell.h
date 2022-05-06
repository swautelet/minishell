/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:28:18 by swautele          #+#    #+#             */
/*   Updated: 2022/05/06 13:46:51 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include "libft.h"
# include "pipex.h"

char	**ft_split(char const *str, char c);
char	*ralloc_cut_string(char *str, size_t begin, size_t end);
size_t	ft_strlen(const char *str);
void	just_parse_it(t_param *data, char **envp);
void	*ft_calloc(size_t count, size_t size);
int		create_heredoc(char *end);
void	check_multiple_command(t_param *data, char **envp);
void	free_table(char **strs);
// char	**split_with_escape(char *str, char c);
char	*find_next_element(t_param *data, int i);
char	*find_next_escape(char *str);

#endif
