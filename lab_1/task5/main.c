


#include "functions.h"

int main(const int argc, const char** argv) {
    long double precision, x;
    if(!GetArgs(argc, argv, &precision, &x)) {
        SeriesA(precision, x);
        SeriesB(precision, x);
        SeriesC(precision, x);
        SeriesD(precision, x);
    }

    return 0;
}
