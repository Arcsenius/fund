long long Factorial(int N) {
    long long Result = 1;


    if (N == 0 || N == 1) {
        return 1;
    }

    for(int i = 1; i <= N; ++i) {
        Result *= i;
    }

    return Result;

    }
