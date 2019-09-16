#include "../includes/mini.h"
#include <signal.h>

void	siginthandler(int signal)
{
	pid_t id;
	ft_putendl("Welcome to the handler.");
	id = getpid();
	kill(id, SIGKILL);
}

void func(void)
{
	char *input;
	while (1)
	{
		get_next_line(1, &input);
	}
}

int		main(void)
{
	signal(SIGINT, handler);
	func();
}