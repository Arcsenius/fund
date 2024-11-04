#include "ParseArgs.h"
#include "states.h"
kState ParseArgs(int argc,  char **argv,  char** file1, kOption* opt, char** file2) {
    if (argc != 4) {
        return kE_INVALID_NUMBER_ARGS;
    }

    *file1 = argv[1];
    *file2 = argv[3];
    char* flag = argv[2];
    if (flag[0] != '-' && flag[0] != '/') {
        return kE_INVALID_FLAG;
    }
    switch (flag[1]) {
        case 'a':
            *opt = kOPT_A;
            break;
        case 'd':
            *opt = kOPT_D;
            break;
        default:
            return kE_INVALID_FLAG;
    }
    return kS_OK;
}
