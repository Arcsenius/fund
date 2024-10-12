#ifndef PARSE_ARGS_H
#define PARSE_ARGS_H
typedef enum {
    OptQ,
    OptM,
    OptT
} KOpts;


int GetOpts (const int,   char* s[] , KOpts*,  int*, double*);
#endif //PARSE_ARGS_H
