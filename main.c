#include "shell.h"
#include <stdio.h>

/**
 * main - A function that creates simple shell
 * @ac: It an argument count
 * @av: it an argument vectors
 * @env: it an environmental variables
 * Return: Zero if successful
 */

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	prompt(env);

	return (0);
}

