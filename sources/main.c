#include "../includes/mini.h"

static int	print_env(char **ep)
{
	int	i;

	i = 0;
	while(ep[i])
		ft_putendl(ep[i++]);
	return (1);
}

static int		run(char **args, int status)
{
	char	*path;
	pid_t	pid;

	if (!(path = param_search(g_environ_vars, "PATH", args[0], SEARCH_ON)))
		path = args[0];
	else
		path = ft_strrealloc(path, args[0]); //How are we gonna free path if this happens?
	pid = fork();
	if (pid == 0)
	{
		execve(path, args, g_environ_vars);
		ft_putstr("Error opening: ");
		ft_putendl(*args);
		return (0);
	}
	while (status)
	{
		waitpid(pid, &status, WUNTRACED);
		if (WIFEXITED(status) || WIFSIGNALED(status))
			break ;
	}
	return (1);
}

static int		unsetenv_checker(char **args)
{
	if (args[1])
		ft_unsetenv(args[1]);
	else
		mini_error("No arguments.", 0);
	return (1);
}

static int		setenv_checker(char **args)
{
	if (ft_strarrlen(args) != 3)
		mini_error("Incorrect amount of arguments", 0);
	else
		ft_setenv(args[1], args[2], ft_strlen(args[1]), ft_strlen(args[2]));
	return (1);
}

static int		run_exec(char **args)
{
	int		status;

	status = 1;
	if (!args || !*args || !**args)
		return (1);
	if (ft_strcmp(*args, "exit") == 0)
		return (0);
	else if (ft_strcmp(*args, "env") == 0)
		return(print_env(g_environ_vars));
	else if (ft_strcmp(*args, "setenv") == 0)
	 	return (setenv_checker(args));
	else if (ft_strcmp(*args, "cd") == 0)
		return (ft_cd(args[1]));
	else if (ft_strcmp(*args, "unsetenv") == 0)
		return(unsetenv_checker(args));
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
		if(get_next_line(STDIN_FILENO, &input) == -1)
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

int		main(int ac, char *av[], char *env[])
{
	(void)ac;
	(void)av;
	if (!env)
		g_environ_vars = ft_strarrdup(environ); // Lets test this
	else
		g_environ_vars = ft_strarrdup(env);
	msh_read();
	ft_strstrdel(&g_environ_vars);
	return (0);
}