#include "shell.h"

/**
 * main - a function that creates a simple shell
 * @ac: arg count input
 * @av: arg vector input
 * @env: environmental variables
 *
 * Return: 0 on success
 */
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	prompt(env);

	return (0);
}
