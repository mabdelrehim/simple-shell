//
// Created by mohamed on 23/10/18.
//

#include <limits.h>
#include "parser.h"
#include "execute.h"

int main(int argc, char ** argv) {


    while(1) {

        printf("simple shell: ");
        char cwd[PATH_MAX];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("%s: ", cwd);
        } else {
            perror("can't get current directory: ");
            return 1;
        }
        char* fullCommand = readLine();
        char** tokenizedCommand = splitLine(fullCommand);

        // terminates when the function execute returns 0
        if (execute(tokenizedCommand) == 0) {
            break;
        }



    }

    return 0;
}