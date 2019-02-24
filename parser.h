//
// Created by mohamed on 23/10/18.
//

#ifndef SIMPLE_SHELL_PARSER_H
#define SIMPLE_SHELL_PARSER_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*  returns a string representing the full command entered by the user
 */
char* readLine();

/*  takes the command as one strings to separate it on spaces
 *  returns an array of string tokens terminated by a null string
 */
char** splitLine(char*);

/*  takes an array of strings and checks whether the '&' character is present at the end of the last string or not
 *  if '&' is present it removes it
 */
bool checkBackground(char**);

#endif //SIMPLE_SHELL_PARSER_H
