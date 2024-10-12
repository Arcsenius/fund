cmake_minimum_required(VERSION 3.29)
project(fund_alg C)

set(CMAKE_C_STANDARD 23)

add_executable(fund_alg
        "lab_1/task 3/main.c"
        "lab_1/task 3/functions.c"
        "lab_1/task 3/parse_args.c"
        "lab_1/task 3/handlers.c"
)
