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

void c_exit(char **str, list_t *env);
int _execve(char **s, list_t *env, int num);
size_t print_list(list_t *h);
list_t *add_end_node(list_t **head, char *str);
int delete_nodeint_at_index(list_t **head, int index);
void free_linked_list(list_t *list);
void ctrl_c(int n);
int built_in(char **token, list_t *env, int num, char **command);
char *ignore_space(char *str);
void ctrl_D(int i, char *command, list_t *env);
int prompt(char **en);
int c_atoi(char *s);
int __exit(char **str, list_t *env, int num, char **command);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
size_t get_line(char **str);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *c_strcat(char *dest, char *src);
int c_setenv(list_t **env, char *name, char *dir);
void cd_only(list_t *env, char *current);
int cd_execute(list_t *env, char *current, char *dir, char *str, int num);
int _cd(char **str, list_t *env, int num);
char *c_strdup(char *str, int cs);
char *get_env(char *str, list_t *env);
int find_env(list_t *env, char *str);
int _unsetenv(list_t **env, char **str);
int _setenv(list_t **env, char **str);
char *c_ignore(char *str);
void non_interactive(list_t *env);
int t_strlen(char *str, int pos, char delm);
int t_size(char *str, char delm);
char *ignore_delm(char *str, char delm);
char **_str_tok(char *str, char *delm);
void free_double_ptr(char **str);
int c_t_size(char *str, char delm);
char **c_str_tok(char *str, char *delm);
int numlen(int n);
char *int_to_string(int number);
void not_found(char *str, int c_n, list_t *env);
void cant_cd_to(char *str, int c_n, list_t *env);
void illegal_number(char *str, int c_n, list_t *env);
char *_which(char *str, list_t *env);
char *_strcat(char *dest, char *src);
list_t *env_linked_list(char **env);
int _env(char **str, list_t *env);

#endif
