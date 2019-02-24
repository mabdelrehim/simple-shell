//
// Created by mohamed on 26/10/18.
//

#include "sig-handler.h"



void sigHandler(int signum) {

    // change the path when running on a different environment
    // needs to be static because the cd command will cause it to create log files in various locations
    FILE* f = fopen("/home/mohamed/CLionProjects/simple-shell/simple-shell-log.txt", "a+");

    // a+ (create + append) option will allow appending which is useful in a log file
    if (f == NULL) {
        printf("failed to log\n");
    } else {
        fprintf(f, "child terminated\n");
        wait(NULL); // I don't know why. Kan fe wa7ed 3amelha weshtaghalet sa7!!!!
    }


}
