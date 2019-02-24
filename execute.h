//
// Created by mohamed on 23/10/18.
//

#ifndef SIMPLE_SHELL_EXECUTE_H
#define SIMPLE_SHELL_EXECUTE_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <wait.h>


/* takes an array of strings representing a shell command and executes that command
 */
int execute(char**);

#endif //SIMPLE_SHELL_EXECUTE_H
