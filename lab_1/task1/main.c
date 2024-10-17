#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "handlers.h"




int main(const int argc, const char* argv[]) {
    kOpts option = 0;
    int number = 0;
    int (*Handlers[6])(int) = {
    HandlerOptH,
    HandlerOptP,
    HandlerOptS,
    HandlerOptE,
    HandlerOptA,
    HandlerOptF
    };


    if (GetOpts(argc, argv, &option, &number)) {
            return EXIT_FAILURE;
    }
    Handlers[option](number);

return EXIT_SUCCESS;
}



















