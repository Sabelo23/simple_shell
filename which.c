#include "shell.h"

/**
 * _which - a fuction that directs to a PATH directory
 * @str: input string
 * @env: environmental variable
 *
 * Return: a PATH to a directory
 */

char *_which(char *str, list_t *env)
{
	char *pth, *cat = NULL, **toks;
	int i = 0;

	pth = get_env("PATH", env);
	toks = c_str_tok(pth, ":");
	free(pth);

	i = 0;
	while (toks[i] != NULL)
	{
		if (toks[i][0] == '\0')
			cat = getcwd(cat, 0);

		else
			cat = _strdup(toks[i]);
		cat = _strcat(cat, "/");
		cat = _strcat(cat, str);
		if (access(cat, F_OK) == 0)
		{
			free_double_ptr(toks);
			return (cat);
		}
		free(cat);
		i++;
	}
	free_double_ptr(toks);
	return (str);
}

/**
 * _strcat - a function that concatenate two strings
 * @dest: input string
 * @src: input string to append to
 *
 * Return: the concatenated string
 */

char *_strcat(char *dest, char *src)
{
	int len = 0;
	int len2 = 0;
	int total_len = 0;
	int j = 0;

	while (dest[len] != '\0')
	{
		len++;
		total_len++;
	}
	while (src[len2] != '\0')
	{
		len2++;
		total_len++;
	}

	dest = _realloc(dest, len, sizeof(char) * total_len + 1);

	while (src[j] != '\0')
	{
		dest[len] = src[j];
		len++;
		j++;
	}
	dest[len] = '\0';

	return (dest);
}

/**
 * env_linked_list - func that creates linked lists from environmental variable
 * @env: environmental variables
 *
 * Return: it returns a linked list
 */

list_t *env_linked_list(char **env)
{
	list_t *head;
	int i = 0;

	head = NULL;
	while (env[i] != NULL)
	{
		add_end_node(&head, env[i]);
		i++;
	}
	return (head);
}

/**
 * _env - a fuction that prints environmental variables
 * @str: input value
 * @env: environmental variables
 *
 * Return: 0 on success
 */

int _env(char **str, list_t *env)
{
	free_double_ptr(str);
	print_list(env);
	return (0);
}

