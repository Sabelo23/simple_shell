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
char *_which(char *str, list_t *env);
char *get_env(char *str, list_t *env);
int find_env(list_t *env, char *str);
int _unsetenv(list_t **env, char **str);
int _setenv(list_t **env, char **str);
int _env(char **str, list_t *env);
list_t *env_linked_list(char **env);
int __exit(char **s, list_t *env, int num, char **command);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int c_atoi(char *s);
int __exit(char **str, list_t *env, int num, char **command);
size_t get_line(char **str);
char *_strcat(char *dest, char *src);

#endif
