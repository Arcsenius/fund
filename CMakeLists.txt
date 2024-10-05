cmake_minimum_required(VERSION 3.29)
project(fund_alg C)

set(CMAKE_C_STANDARD 23)

add_executable(fund_alg
        "lab_1/task 2/main.c"
        "lab_1/task 2/functions/Ln2_calc/Lim/Handler_Ln2_Lim.c"
        "lab_1/task 2/functions/Ln2_calc/Quation/Handler_ln2_Quation.c"
        "lab_1/task 2/functions/E_calc/Quation/Handler_E_Quation.c"
        "lab_1/task 2/functions/Ln2_calc/Series/Handler_ln2_Series.c"
        "lab_1/task 2/functions/Ln2_calc/Series/Handler_ln2_Series.h"
        "lab_1/task 2/functions/Pi_calc/Handler_Pi_Lim.c"
        "lab_1/task 2/functions/Pi_calc/Handler_Pi_Lim.h"
)
