#include "parse_args.h"
#include <stdio.h>
#include <stdlib.h>
#include "errors.h"




int GetOpts (const int argc,  char *argv[], KOpts *option,  int *argsCount, double* args) {
    if (argc < 2) {
        printf("Error: Not enough arguments\n");
        return ERROR_ARG;
    }


    if (argv[1][0] == '-' || argv[1][0] == '/') {
        switch (argv[1][1]) {
            case 'q':
                *option = OptQ;
                *argsCount = 4;
                break;
            case 'm':
                *option = OptM;
                *argsCount = 2;
                break;
            case 't':
                *option = OptT;
                *argsCount = 4;
                break;
            default:
                printf("Error: Unknown flag '%c'\n", argv[1][1]);
                return ERROR_FLAG;

        }

        if (argc != *argsCount + 2) {
            printf("Error: incorrect number of arguments\n");
            return ERROR_ARG;
        }

        for (int i = 0; i < *argsCount; ++i) {
            args[i] = atof(argv[i + 2]);
        }


        return EXIT_SUCCESS;
    }
    printf("Error: name flag starts '-' or '/' \n");
    return ERROR_FORM;
}




