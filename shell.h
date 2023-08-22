#ifndef SHELL_H
#define SHELL_H

#include <stdio.h> /* for printf*/
#include <unistd.h> /* for fork, execve*/
#include <stdlib.h>
#include <string.h> /* for strtok*/
#include <stddef.h>
#include <errno.h> /* for errno and perror */
#include <sys/types.h> /* for type pid */
#include <sys/wait.h> /* for wait */
#include <sys/stat.h> /* for use of stat function */
#include <signal.h> /* for signal management */
#include <fcntl.h> /* for open files*/

/************* MACROS **************/

#include "macros.h" /* for msg help and prompt */

/************* STRUCTURE **************/

/**
 * struct info - Structure for storing program's data.
 *
 * @program_name: The name of the executable.
 * @input_line: Pointer to the input read by _getline.
 * @command_name: Pointer to the first command typed by the user.
 * @exec_counter: Number of executed commands.
 * @file_descriptor: File descriptor for the input of commands.
 * @tokens: Pointer to an array of tokenized input.
 * @env: Copy of the environment variables.
 * @alias_list: Array of pointers to aliases.
 */
typedef struct info
{
	char *program_name;
	char *input_line;
	char *command_name;
	int exec_counter;
	int file_descriptor;
	char **tokens;
	char **env;
	char **alias_list;
} data_of_program;

/**
 * struct builtins - structure for the builtins
 * @builtin: name of the builtin
 * @function: the associated function called for every builtin
 */
typedef struct builtins
{
	char *builtin;
	int (*function)(data_of_program *data);
} builtins;


/************* MAIN FUNCTIONS *************/


/*========  shell.c  ========*/

/* Initialize the structure with the info of program */
void inicialize_data(data_of_program *data, int arc, char *argv[], char **env);

/* Makes the infinite loop that shows the prompt*/
void sisifo(char *prompt, data_of_program *data);

/* Print the prompt in a new line */
void handle_ctrl_c(int opr UNUSED);


/*========  _getline.c  ========*/

/* Reading one line of the standar input*/
int _getline(data_of_program *data);

/* seprate every line for the logical operators if it exist */
int check_logic_ops(char *array_commands[], int i, char array_operators[]);


/*======== expansions.c ========*/

/* expanding variables */
void expand_variables(data_of_program *data);

/* expanding aliases */
void expand_alias(data_of_program *data);

/* append string to the ending of buffer*/
int buffer_add(char *buffer, char *str_to_add);


/*======== str_token.c ========*/

/* Separating string in token using a designed delimiter */
void tokenize(data_of_program *data);

/* Creates a pointer to part of a string */
char *_strtok(char *line, char *delim);


/*======== execute.c ========*/

/* Execute a command with its entire path */
int execute(data_of_program *data);


/*======== builtins_list.c ========*/

/* If match a builtin, executes it */
int builtins_list(data_of_program *data);


/*======== find_in_path.c ========*/

/* Creates an array of the path directories */
char **tokenize_path(data_of_program *data);

/* Search for program in path */
int find_program(data_of_program *data);


/************** BUILTIN **************/


/*======== builtins_and_more.c ========*/

/* Closing shell */
int builtin_exit(data_of_program *data);

/* Changing the current directory */
int builtin_cd(data_of_program *data);

/* set the working directory */
int set_work_directory(data_of_program *data, char *new_dir);

/* display help information */
int builtin_help(data_of_program *data);

/* set unset and display alias */
int builtin_alias(data_of_program *data);


/*======== builtins_env.c ========*/

/* display the environment where the shell runs */
int builtin_env(data_of_program *data);

/* create  override a variable of env */
int builtin_set_env(data_of_program *data);

/* remove a variable of environment */
int builtin_unset_env(data_of_program *data);


/************** HELP FOR ENVR VARIABLES MANAGEMENT **************/


/*======== env_manag.c ========*/

/* Gets the value of an environment variable */
char *env_get_key(char *name, data_of_program *data);

/* Overwrite values of the environment variables */
int env_set_key(char *key, char *value, data_of_program *data);

/* delete key from the environment */
int env_remove_key(char *key, data_of_program *data);

/* display the current environ */
void print_environ(data_of_program *data);


/************** HELP FOR displaying **************/

/* display string in the standard output */
int _print(char *string);

/* display a string in the standard error */
int _printe(char *string);

/* display string in the standar error */
int _print_error(int errorcode, data_of_program *data);


/************** HELP FOR STRINGS MANAGEMENT **************/


/*======== helpe1.c ========*/

/* Counts the num of char of  string */
int str_length(char *string);

/* Duplicates the string */
char *str_duplicate(char *string);

/* Compares 2 strings */
int str_compare(char *string1, char *string2, int number);

/* Concatenates 2 strings */
char *str_concat(char *string1, char *string2);

/* Reverse the string */
void str_reverse(char *string);


/*======== help_num.c ========*/

/* Cast from into string */
void long_to_string(long number, char *string, int base);

/* convert an string into number */
int _atoi(char *s);

/* count coincidences of chara in string */
int count_characters(char *string, char *character);


/*======== alias_manag.c ========*/

/* display the list of alias */
int print_alias(data_of_program *data, char *alias);

/* obtain alias name */
char *get_alias(data_of_program *data, char *alias);

/* write alias name */
int set_alias(char *alias_string, data_of_program *data);


#endif /* SHELL_H */
