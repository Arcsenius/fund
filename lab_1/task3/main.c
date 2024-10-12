#include "functions.h"
#include "parse_args.h"
#include "handlers.h"

int main(const int argc, const char** argv) {

    KOpts option;
    int argsCount;
    const double args[5];
    int (*handlersMass[3])(const double*) = {
        HandlerOptQ,
        HandlerOptM,
        HandlerOptT
    };


    if(!GetOpts(argc, argv, &option, &argsCount, args)) {
        handlersMass[option](args);
    }
    return 0;
}