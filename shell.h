#ifndef SHELL
#define SHELL


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

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

size_t get_line(char **str);
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
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int __exit(char **s, list_t *env, int num, char **command);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _cd(char **str, list_t *env, int num);
void non_interactive(list_t *env);
char **_str_tok(char *str, char *delm);
char **c_str_tok(char *str, char *delm);
list_t *add_end_node(list_t **head, char *str);
size_t print_list(list_t *h);
void cant_cd_to(char *str, int c_n, list_t *env);
int t_strlen(char *str, int pos, char delm);
char *ignore_space(char *str);
int prompt(char **env);
char *int_to_string(int num);
void illegal_number(char *str, int c_n, list_t *env);
int built_in(char **token, list_t *env, int num, char **command);
int delete_nodeint_at_index(list_t **head, int index);
int _execve(char *argv[], list_t *env, int num);


#endif
