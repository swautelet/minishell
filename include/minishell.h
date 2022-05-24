/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:28:18 by swautele          #+#    #+#             */
/*   Updated: 2022/05/24 18:39:11 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "pipex.h"
# include <curses.h>
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <term.h>
# include <termios.h>

typedef struct s_skip{
	int		i;
	char	flag;
	int		j;
	int		decal;
}t_skip;

typedef struct s_var{
	char	flag;
	int		i;
	char	*name;
	char	*var;
}t_var;

t_param	*g_data;

char	**ft_split(char const *str, char c);
char	*ralloc_cut_string(char *str, size_t begin, size_t end);
size_t	ft_strlen(const char *str);
void	just_parse_it(t_param *data);
void	*ft_calloc(size_t count, size_t size);
int		create_heredoc(char *end);
void	check_multiple_command(t_param *data);
void	free_table(char **strs);
char	**split_with_escape(char *str, char c);
char	*find_next_element(t_param *data, int i);
char	*find_next_escape(char *str);
char	*find_next_name(t_param *data, int i);
void	buccle_readline(t_param *data);
void	new_readline(int sig);
void	write_table(char **envp);
char	*ralloc_insert_string(char *str, int i, char *var);
char	*insert_variable(char *str);
char	*find_variable(char *name);
char	*find_name_variable(char *str);
char	*insert_variable(char *str);
int		is_whitespace(char c);
int		check_built_in(t_param *data);
void	move_dir(t_param *data);
void	unset_env(t_param *data);
void	export_env(t_param *data);
void	write_echo(char *str);
int		size_table(char **env);
void	free_table(char **str);
char	*where_am_i(void);
t_list	*convert_to_list(char **envp);
char	**convert_to_char(t_list *env);
void	print_list(t_list *env);
int		check_built_in_output(char *str, char **envp);
int		check_echo(char *str);
void	remove_escape(char **str);
t_list	*ft_lstsearch(t_list *env, char *searched);
char	*my_getenv(t_param *data, char *searched);
char	*find_variable_name(char *str);
int		prep_last_command(char *com, char **envp, int fdout);
void	cut_beginning_whitespace(char *str);
size_t	ft_count(const char *str, const char c);
int		with_escape(t_param *data, int *i, int j, char *begin);
void	remove_escape_string(char *str);
void	ft_lst_replace_content(t_list *node, char *str);
void	ft_lst_addback_new(t_list *node, char *str);

void	rl_replace_line(const char *text, int clear_undo);

#endif
