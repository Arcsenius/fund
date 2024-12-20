#include <stdio.h>
 #include <stdlib.h>
#include "handlers.h"
#include "parseArgs.h"
#include "states.h"

int main(int argc, char** argv) {
    Input* input = ParseArgs(argc, argv);
    if (input->code != kS_OK) {
        LogErrors(input->code);
        kState code = input->code;
        FreeInput(input);
        return code;
    }
    char* output;
    kState (*handlers[5])(Input*, char**) = {
        HandlerOptL, HandlerOptR, HandlerOptU, HandlerOptN, HandlerOptC,
    };
    kState code = handlers[input->opt](input, &output);
    if (code != kS_OK) {
        LogErrors(code);
    } else {
        printf("%s\n", output);
    }
    FreeInput(input);
    free(output);
    return code;
}