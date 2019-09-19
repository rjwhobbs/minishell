/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasahmed <wasahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:11:47 by wasahmed          #+#    #+#             */
/*   Updated: 2019/09/18 14:51:10 by rhobbs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini.h"

static void	getpath(char **args, char **path)
{
	char *tmp;

	if (!(tmp = param_search(g_env, "PATH", args[0], SEARCH_ON)))
	{
		*path = args[0];
		return ;
	}
	else
		tmp = ft_strrealloc(tmp, args[0]);
	ft_strcpy(*path, tmp);
	free(tmp);
}

static int	run(char **args, int status)
{
	char	tmp_path[PATH_MAX];
	pid_t	pid;
	char	*path;

	path = tmp_path;
	getpath(args, &path);
	if (!access_control(path))
		return (1);
	pid = fork();
	if (pid == 0)
	{
		execve(path, args, g_env);
		ft_putstr("Error opening: ");
		ft_putendl(*args);
		exit(EXIT_FAILURE);
	}
	wait(&status);
	return (1);
}

static int	run_exec(char **args)
{
	int		status;

	status = 1;
	if (!args || !*args || !**args)
		return (1);
	if (ft_strcmp(*args, "exit") == 0)
		return (0);
	else if (ft_strcmp(*args, "env") == 0)
		return (print_env(g_env));
	else if (ft_strcmp(*args, "setenv") == 0)
		return (setenv_checker(args));
	else if (ft_strcmp(*args, "cd") == 0)
		return (ft_cd(args[1]));
	else if (ft_strcmp(*args, "unsetenv") == 0)
		return (unsetenv_checker(args));
	else if (ft_strcmp(*args, "echo") == 0)
		return (ft_echo(args));
	else
		return (run(args, status));
}

static void	msh_read(void)
{
	char	*input;
	char	**args;
	char	*input_trimed;
	int		status;

	status = 1;
	input = NULL;
	while (status)
	{
		ft_putstr("msh > ");
		if (get_next_line(STDIN_FILENO, &input) == -1)
			mini_error("error reading stdin.", NONFATAL_ME);
		input_trimed = ft_strtrim(input);
		ft_strdel(&input);
		args = parser(input_trimed);
		ft_strdel(&input_trimed);
		expand(args);
		status = run_exec(args);
		if (args)
			ft_strstrdel(&args);
	}
}

int			main(int ac, char *av[], char *env[])
{
	(void)ac;
	(void)av;
	g_env = ft_strarrdup(env);
	msh_read();
	ft_strstrdel(&g_env);
	return (0);
}
