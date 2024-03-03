#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int _strlen(const char *s);
char *_strcopy(char *s);
void _strcpy(char *dest, char *s);
void _strcat(char *dest, char *s);

char **toknizing_envp_path(char *envp[]);
void free_array(char *array[]);

void display_prompt(void);
void get_line(char **cmd_line, size_t cmd_len, char *paths[], int exit_code);

int execExit(char **cmd_line, char *paths[], int cct, int *exit_code, char *argv);
char *compare_with_path(char *_1_tok, char *path_array[]);
int _execute_some(char *pathname, char *cmd_line, int tok_count, char *envp[]);
void _input(char **cM, size_t cL, char *pt[], int cct, char *av[], char *ev[]);
int check_if_spaces(char *cmd_line);
void execCd(char *cmd, char *envp[]);
int builtin(char **cmd_line, char *paths[], int cmd_count, int *exit_code, char *argv_zero, char *envp[]);

#endif
