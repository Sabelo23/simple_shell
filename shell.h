#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <wait.h>
#include <fcntl.h>
/**
 * struct list - linked list for environmental variables
 * @var: holds environmental variable string
 * @next: points to next node
 */
typedef struct list
{
	char *var;
	struct list *next;

} list_t;

void free_double_ptr(char **str);
void free_linked_list(list_t *list);
void not_found(char *str, int num, list_t *env);
char *which(char *str, list_t *env);
#endif
