/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:53:32 by kostya            #+#    #+#             */
/*   Updated: 2021/09/18 18:40:06 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <linux/limits.h>

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <termios.h>

#define OUT_APPEND	(char *)1
#define OUT_WRITE	(char *)2
#define HEREDOC		(char *)3
#define INPUT		(char *)4
#define PIPE		(char *)5
#define UNO_QUOTE	(char *)6
#define DBL_QUOTE	(char *)7

# define ft_strlen strlen
# define ft_strcat strcat
# define ft_strchr strchr
# define ft_memcpy memcpy
# define ft_memcmp memcmp
# define ft_calloc calloc
# define ft_atoi(n) strtol((n), NULL, 10)
# define ft_itoa(n) ({char __ans[12]; int __n = (n); sprintf(__ans, "%d", __n); __ans;})
# define ft_isalnum isalnum
# define ft_isdigit isdigit
# define ft_isalpha isalpha
# define ft_isspace isspace
# define ft_strcmp strcmp

char	**ft_split(char const *s, int (*f)(int));
char	**ft_split_special(char const *s, int (*f)(int));
char		**smart_split(const char *input, int (*skip)(int));
long long	ft_atol_s(const char *str, int *error);
int			ft_atoi_s(const char *str, int *error);
void		clear_split(char **array);
int			not_so_simple_parser(const char *input);
int			set_autoattr(int desc, int value, int what);

int			builtin_echo(char *const *argv);
int			builtin_cd(char *const *argv);
int			builtin_pwd(char *const *argv);
int			builtin_export(char *const *argv);
int			builtin_export_split(const char *string, char *restrict *key, char *restrict *value);
int			builtin_unset(char *const *argv);
int			builtin_env(char *const *argv);
int			builtin_exit(char *const *argv);
int			builtin_execve(char *const *argv);
char		*builtin_heredoc(const char *end);



#endif
