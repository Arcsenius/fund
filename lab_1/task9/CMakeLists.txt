cmake_minimum_required(VERSION 3.29)
project(fund_alg_task9 C)

set(CMAKE_C_STANDARD 23)

FILE(GLOB sources "${PROJECT_SOURCE_DIR}/*.h" "${PROJECT_SOURCE_DIR}/*.c")


message("${PROJECT_SOURCE_DIR}/*.h")

add_executable(${PROJECT_NAME}
        ${sources}
)
target_include_directories(${PROJECT_NAME} PUBLIC ../../..)
