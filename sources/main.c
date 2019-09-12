#include "../includes/mini.h"

void	print_env(char **ep)
{
	int	i;

	i = 0;
	while(ep[i])
		ft_putendl(ep[i++]);
}
int		run_exec(char **args)
{
	char	*path;
	pid_t	pid;
	int		status;

	if (ft_strcmp(*args, "exit") == 0)
		return (0);
	else if (ft_strcmp(*args, "env") == 0)
	{
		print_env(g_environ_vars);
		return (1);
	}
	// else if (ft_strcmp(*args, "setenv") == 0)
	//  	return (ft_setenv(env));
	else if (ft_strcmp(*args, "./a.out") == 0)
	 	execve("./a.out", args, g_environ_vars);
	else if (ft_strcmp(*args, "cd") == 0)
		return (ft_cd(args[1]));
	status = 1;
	if (!(path = param_search(g_environ_vars, "PATH", args[0], SEARCH_ON)))
		path = args[0];
	else
		path = ft_strrealloc(path, args[0]);
	pid = fork();
	if (pid == 0)
	{
		if ((ft_strcmp(*args, "./print_mem") == 0))
			execve("./print_mem", args, g_environ_vars);
		else
		{
			execve(path, args, g_environ_vars);
			ft_putstr("Error opening: ");
			ft_putendl(*args);
		}
		return (0);
	}
	//else if (pid > 0)
	while (status)
	{
		waitpid(pid, &status, WUNTRACED);
		if (WIFEXITED(status) || WIFSIGNALED(status))
			break ;
		// wait(NULL);
	}
	return (1);
}

void	msh_read(void)
{
	char	*input;
	char	**args;
	char	*temp;
	int		status;

	status = 1;
	input = NULL;
	while (status)
	{
		ft_putstr("msh > ");
		if(get_next_line(STDIN_FILENO, &input) == -1)
			mini_error("error reading stdin.", FATAL_ME);
		temp = ft_strtrim(input);
		ft_strdel(&input);
		input = temp;
		args = parser(input);
		//free input here;
		//$ expantion call
		expand(args);
		print_env(args);
		status = run_exec(args);
		//free args here
	}
}

int		main(int ac, char *av[], char *env[])
{
	(void)ac;
	(void)av;
	g_environ_vars = ft_strarrdup(env);
	msh_read();
	ft_strstrdel(&g_environ_vars);
	return (0);
}