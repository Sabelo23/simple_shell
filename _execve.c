#include "shell.h"

/**
 * c_exit - frees user's linked list and command before exit
 * @str: input value
 * @env: input value
 */
void c_exit(char **str, list_t *env)
{
	free_double_ptr(str);
	free_linked_list(env);
	_exit(0);
}

/**
 * _execve - execute command typed into shell by user
 * @s: input command
 * @env: environmental variable
 * @num: input value
 *
 * Return: 0 on success
 */
int _execve(char **s, list_t *env, int num)
{
	char *holder;
	int status = 0, t = 0;
	pid_t pid;

	if (access(s[0], F_OK) == 0)
	{
		holder = s[0];
		t = 1;
	}

	else
		holder = _which(s[0], env);

	if (access(holder, X_OK) != 0)
	{
		not_found(s[0], num, env);
		free_double_ptr(s);
		return (127);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(holder, s, NULL) == -1)
			{
				not_found(s[0], num, env);
				c_exit(s, env);
			}
		}
		else
		{
			wait(&status);
			free_double_ptr(s);
			if (t == 0)
				free(holder);
		}
	}
	return (0);
}

