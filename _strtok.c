#include "shell.h"

/**
 * t_strlen - a function that returns token string length
 * @str: input token
 * @pos: input value
 * @delm: input value
 *
 * Return: the token's length
 */

int t_strlen(char *str, int pos, char delm)
{
	int len = 0;

	while ((str[pos] != delm) && (str[pos] != '\0'))
	{
		pos++;
		len++;
	}
	return (len);
}

/**
 * t_size - a function that a number of delim
 * @str: input value
 * @delm: input delimeter (" ");
 *
 * Return: the number of delims
 */

int t_size(char *str, char delm)
{
	int i = 0, num_delm = 0;

	while (str[i] != '\0')
	{
		if ((str[i] == delm) && (str[i + 1] != delm))
		{
			num_delm++;
		}
		if ((str[i] == delm) && (str[i + 1] == '\0'))
		{
			num_delm--;
		}
		i++;
	}
	return (num_delm);
}

/**
 * ignore_delm - a function that returns a string version
 * @str: input string
 * @delm: delimiter (" ")
 *
 * Return: it returns a new string
 */

char *ignore_delm(char *str, char delm)
{
	while (*str == delm)
		str++;
	return (str);
}

/**
 * _str_tok - function that tokenize a string and will returns array of tokens
 * @str: input value
 * @delm: input delimeter (" ")
 *
 * Return: it returns array of tokens
 */

char **_str_tok(char *str, char *delm)
{
	int buffsize = 0, p = 0, si = 0, i = 0, len = 0, se = 0, t = 0;
	char **toks = NULL, d_ch;

	d_ch = delm[0];
	str = ignore_delm(str, d_ch);
	buffsize = t_size(str, d_ch);
	toks = malloc(sizeof(char *) * (buffsize + 2));
	if (toks == NULL)
		return (NULL);
	while (str[se] != '\0')
		se++;
	while (si < se)
	{
		if (str[si] != d_ch)
		{
			len = t_strlen(str, si, d_ch);
			toks[p] = malloc(sizeof(char) * (len + 1));
			if (toks[p] == NULL)
				return (NULL);
			i = 0;
			while ((str[si] != d_ch) && (str[si] != '\0'))
			{
				toks[p][i] = str[si];
				i++;
				si++;
			}
			toks[p][i] = '\0';
			t++;
		}
		if (si < se && (str[si + 1] != d_ch && str[si + 1] != '\0'))
			p++;
		si++;
	}
	p++;
	toks[p] = NULL;
	return (toks);
}

/**
 * free_double_ptr - The function that free malloced arrays
 * @str: The array of strings
 */

void free_double_ptr(char **str)
{
	int i = 0;

	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
