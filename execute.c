//
// Created by mohamed on 26/10/18.
//

#include "execute.h"
#include "parser.h"
#include "sig-handler.h"

int execute(char** tokens) {

    int execute = 1;


    // the exit and cd commands must be executed in the parent process
    // the exit command
    if (strcmp(tokens[0], "exit") == 0) {
        exit(0);
    }

        // the cd command
        // make sure that the second argument is correct
    else if (strcmp(tokens[0], "cd") == 0) {

        if (tokens[1] == NULL) {
            printf("error please specify a directory\n");
            return execute;
        }

        int chdirCheck = chdir(tokens[1]);
        if (chdirCheck != 0) {
            printf("error cannot change directory\n");
            return execute;
        }
        printf("\n");

    }
        // commands that can be executed using execvp and will be executed on a child process
    else {

        // only the parent process will execute the next line since the child will execute execvp() and then terminate
        // before reaching the next iteration of the main loop
        bool background = checkBackground(tokens);

        pid_t pid;
        pid = fork();

        if (pid == 0) {
            // child code
            int execvpCheck = execvp(tokens[0], tokens);

            if (execvpCheck == -1) {
                printf("error cannot execute this command\n");
            }
            printf("\n");
            exit(0); // make sure that the child only performs the command then exits;

        } else if (pid < 0) {
            printf("error cannot create a child process\n");
        } else {
            // parent code
            signal(SIGCHLD, sigHandler);
            if (!background) {
                wait(NULL);
            }
            return execute;

        }

    }


    return execute;
}

