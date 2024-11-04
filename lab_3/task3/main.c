#include <stdio.h>
#include "ParseArgs.h"
#include "Hanlers.h"


int main(int argc,  char **argv) {
    kOption opt;

    // char cwd[1024];
    // if (getcwd(cwd, sizeof(cwd)) != NULL) {
    //     printf("Current working directory: %s\n", cwd);
    // } else {
    //     perror("getcwd() error");
    // }


    char* file1;
    char* file2;
    kState code = ParseArgs(argc, argv, &file1, &opt, &file2);
    if (code != kS_OK) {
        LogErrors(code);
        return 1;
    }
    kState (*Handlers[2])(char*, char*) = {
        HandlerOptA,
        HandlerOptD
    };


    code = Handlers[opt](file1, file2);
    if (code != kS_OK) {
        LogErrors(code);
        return 1;
    }
    return 0;
}
