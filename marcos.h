#ifndef HELPERS_H
#define HELPERS_H

/* Prompt to be printed */
#define PROMPT_MSG "$" /* Used in conjunction with signal handling */

/* Macro for marking unused attributes */
#define UNUSED __attribute__((unused))

/* Buffer size for each read call in _getline */
#define BUFFER_SIZE 1024

/**************** FORMATTED STRINGS FOR BUILTIN HELP ****************/

#define HELP_CD_MSG "cd=\n"\
"cd:\tcd [dir]\n\n"\
"Change the shell working directory.\n\n"\
"If no argument is provided, 'cd' will be interpreted as 'cd $HOME'.\n"\
"If the argument is '-', 'cd -' will be interpreted as 'cd $OLDPWD'.\n\n"

#define HELP_EXIT_MSG "exit=\n"\
"exit:\texit [STATUS]\n\n"\
"Exit the simple-shell.\n\n"\
"Exits the shell with a status of N. If N is omitted, the exit status\n"\
"is that of the last executed command.\n\n"

#define HELP_ENV_MSG "env=\n"\
"env:\tenv\n\n"\
"Print the environment.\n\n"\
"The 'env' command will display a complete list of environment variables.\n\n"

#define HELP_SETENV_MSG "setenv=\n"\
"setenv:\tsetenv VARIABLE VALUE\n\n"\
"Change or add an environment variable.\n\n"\
"Initialize a new environment variable or modify an existing one.\n"\
"When the correct number of arguments is not provided, an error message will be displayed.\n\n"

#define HELP_UNSETENV_MSG "unsetenv=\n"\
"unsetenv:\tunsetenv VARIABLE\n\n"\
"The 'unsetenv' function deletes a variable from the environment.\n\n"\
"When the correct number of arguments is not provided, an error message will be displayed.\n\n"

#define HELP_MSG "help=\n"\
"help:\thelp [BUILTIN_NAME]\n\n"\
"Display information about builtin commands.\n\n"\
"Displays brief summaries of builtin commands. If BUILTIN_NAME is\n"\
"specified, provides detailed help on commands matching BUILTIN_NAME,\n"\
"otherwise, a list of available help topics is displayed.\n"\
"Arguments:\n\n"\
"BUILTIN_NAME specifying a help topic.\n\n"\
"cd\t[dir]\n"\
"exit\t[status]\n"\
"env\n"\
"setenv\t[variable value]\n"\
"unset\t[variable]\n"\
"help\t[built_name]\n\n"

#endif /* HELPERS_H */
