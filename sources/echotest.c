#include <stdio.h>

int main(int argc, char **argv)
{
	while (*argv)
	{
		printf("%s\n", *argv++);
	}
	printf("%d\n", argc -1);
	return (0);
}