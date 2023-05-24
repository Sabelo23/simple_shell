#include "shell.h"

/**
 * _strcpy - It copy the string pointed to by src including the terminating
 * -NULL byte 0 to the buffer pointed to by dest
 *  @dest: It copy the source to the buffer
 *  @src: The source to copy
 *  Return: The copy of the origin source
 */

char *_strcpy(char *dest, char *src)
{
	int i, len;

	for (len = 0; src[len] != '\0'; len++)
		;

	for (i = 0; i <= len; i++)
		dest[i] = src[i];

	return (dest);
}

/**
 * _strdup - Function that return a pointer to newly allocated space in memory
 * -that contains a copy of the string given as a parameter
 *  @str: The string to duplicate
 *  Return: A pointer to duplicate string in allocted memory
 */

char *_strdup(char *str)
{
	char *duplicate_str;
	int i, len = 0;

	if (str == NULL)
	return (NULL);

	while (*(str + len))
		len++;
	len++;

	duplicate_str = malloc(sizeof(char) * len);
	if (duplicate_str == NULL)
		return (NULL);

	i = 0;
	while (i < len)
	{
		*(duplicate_str + i) = *(str + i);
		i++;
	}
	return (duplicate_str);
}

/**
 * _strcmp - A function that compare two strings
 * @s1: Pointer at string 1
 * @s2: Pointer at string 2
 * Return: A int that tells num spaces in between 0 if exactly the same string
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (*(s1 + i) == *(s2 + i) && *(s1 + i))
	i++;
	if (*(s2 + i))

	return (*(s2 + i) - *(s2 + i));
	else
		return (0);
}

