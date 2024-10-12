cmake_minimum_required(VERSION 3.29)
project(fund_alg_task3 C)

set(CMAKE_C_STANDARD 23)

FILE(GLOB ${sources} "${PROJECT_SOURCE_DIR}/*.h" "${PROJECT_SOURCE_DIR}/*.c")


message("${PROJECT_SOURCE_DIR}/*.c")

add_executable(${PROJECT_NAME}
       ${sources}
)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
