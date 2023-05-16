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

/**
 * _realloc - The function that allocate memory and make all values to 0
 * @ptr: A pointer to the memory that previously allocated (malloc(old_size))
 * @old_size: A size that is previously allocated
 * @new_size: A new size to re-allocate
 * Return: A pointer to re-alloate memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *p;
	unsigned int i;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (p == NULL)
			return (NULL);
		else
			return (p);
	}

	p = malloc(new_size);
	if (p == NULL)
		return (NULL);

	for (i = 0; i < old_size && i < new_size; i++)
		*((char *)p + i) = *((char *)ptr + i);
	free(ptr);
	return (p);
}

/**
 * get_line - It stores into malloced buffer the user's command into shell
 * @str: Pointer to a buffer
 * Return: A number of charaters read
 */

size_t get_line(char **str)
{
	size_t i = 0, size = 0, t = 0, t2 = 0, n = 0;
	char buff[1024];

	while (t2 == 0 && (i = read(STDIN_FILENO, buff, 1024 - 1)))
	{
		if (i == -1)
			return (-1);

		buff[i] = '\0';
		n = 0;
		while (buff[n] != '\0')

		{
			if (buff[n] == '\n')
				t2 = 1;
			n++;
		}
		if (t == 0)

		{
			i++;
			*str = malloc(sizeof(char) * i);
			*str = _strcpy(*str, buff);
			size = i;
			t = 1;
		}
		else
		{
			size += i;
			*str = _strcat(*str, buff);
		}
	}
	return (size);
}
