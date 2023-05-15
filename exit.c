#include "shell.h"

/**
 * c_atoi - Funtion that make atoi coverts string to int
 * @s: Pointing at the string
 * Return: A number if successful or -1 if not successful, not a number.
 */

int c_atoi(char *s)
{
	int i = 0;
	unsigned int num = 0;

	while (s[i] != '\0')
	{
	if (s[i] >= '0' && s[i] <= '9')
		num = num * 10 + (s[1] - '0');

	if (s[i] > '9' || s[i] < '0')

	return (-1);
	i++;
	}
	return (num);
}

/**
 * __exit - a function that frees user input and exits main program
 * @str: A command from the user on shell
 * @env: An environmental variable to free error
 * @num: A nth user command line input to print in error msg
 * @command: An command to free
 * Return: It will return 0 if successful or 2 if not successful
 */

int __exit(char **str, list_t *env, int num, char **command)
{
	int e_value = 0;

	if (str[1] != NULL)
		e_value = c_atoi(str[1]);

	if (e_value == -1)
	{
		illegal_number(str[1], num, env);
		free_double_ptr(str);
		return (2);
	}
	free_double_ptr(str);
	free_linked_list(env);
	if (command != NULL)
		free_double_ptr(command);
	exit(e_value);
}
