cmake_minimum_required(VERSION 3.29)
project(fund_alg C)

set(CMAKE_C_STANDARD 23)

add_executable(fund_alg
        "lab_1/task 2/main.c"
        "lab_1/task 2/functions/E_calc/Lim/Handler_E_Lim.h"
        "lab_1/task 2/functions/E_calc/Lim/Handler_E_Lim.c"
        "lab_1/task 2/functions/E_calc/Series/Handler_E_Series.h"
        "lab_1/task 2/functions/E_calc/Series/Handler_E_Series.c"
        "lab_1/task 2/functions/E_calc/Series/etc/Factorial.h"
        "lab_1/task 2/functions/E_calc/Series/etc/Factorial.c"
        "lab_1/task 2/functions/E_calc/Quation/Handler_E_Quation.c"
        "lab_1/task 2/functions/E_calc/Quation/Handler_E_Quation.h"
)
