#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

/**
 * struct commands_help - sadsad
 * @name: char variable
 * @func: void
*/

typedef struct commands_help
{
	char *name;
	void (*func)();
} help_t;

/**
 * struct builtins - sadsad
 * @name: dsfasdf
 * @func: sadfasdf
*/

typedef struct builtins
{
	char *name;
	int (*func)();
} builtins_t;

/* Global variables */
extern char **environ;
int cantLoops;
int flag;

void launch(void);
void constructor(char **);
void execute(char **);
char **parse(char *);
char **findpath(char **);
char *path_concat(char *, char *);
char *path_copy(char *);
int isbuiltin(char **, char *);
int issame(char *, char *);
void print_number(int n);
void signals(int);

/* Easter egg functions */
int yazF(void);

/* Help functions */
void exitH(void);
void envH(void);
void unsetH(void);
void helpH(void);
void help_me(void);

/* Builtin functions */
int exitF(char **, char *);
int envF(char **);
int unsetF(char **);
int helpF(char **);

/* Functions derived from the STRING library */
char *_strtok(char *, const char *);
char *_strcat(char *, char *);
int _strncmp(char *, char *, int);
int _strlen(char *);
char *_strdup(char *);
char *_strchr(char *, char);

/* Functions derived from the STDLIB library */
int _atoi(char *);
void *alloc(size_t);
void freeall(char **);

/* Functions derived from the STDIO library */
void _puts(char *);
int _putchar(char);

void exitH(void);
void envH(void);
void unsetenvH(void);
void helpH(void);

#endif
