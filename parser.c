//
// Created by mohamed on 26/10/18.
//

#include "parser.h"


char* readLine() {

    char *buffer = NULL;
    size_t bufferSize = 0;      //getline will allocate buffer
    getline(&buffer, &bufferSize, stdin);

    return buffer;

}


char** splitLine(char* line) {

    int bufferSize = 100;
    int tokensCount = 0;
    char** tokens = malloc(bufferSize * sizeof(char*));
    char* temp;

    while ((temp = strsep(&line, " ")) != NULL) {
        tokens[tokensCount] = temp;
        tokensCount++;
    }

    tokens[tokensCount - 1][strlen(tokens[tokensCount - 1]) - 1] = '\0'; //remove newline character

    tokens[tokensCount] = NULL;


    return tokens;

}

bool checkBackground(char** tokens) {

    bool background = false;

    int index = 0;
    while (tokens[index] != NULL) {
        index ++;
    }
    index--;

    // first check if the user entered a space between the command and '&'
    if (strcmp(tokens[index], "&") == 0) {
        tokens[index] = NULL;
        background = true;
    }
    // next check if the user just appended '&' to the end of the last word in the command
    else {
        int innerIndex = 0;
        while (tokens[index][innerIndex] != '\0') {
            innerIndex++;
        }
        innerIndex--;

        if (tokens[index][innerIndex] == '&') {
            background = true;
        }

        if (background) {
            tokens[index][innerIndex] = '\0';
        }
    }


    return background;

}


