cmake_minimum_required(VERSION 3.22.1)
project(fund_alg_task1 C)

set(CMAKE_C_STANDARD 23)

FILE(GLOB sources "${PROJECT_SOURCE_DIR}/*.h" "${PROJECT_SOURCE_DIR}/*.c")


message("${PROJECT_SOURCE_DIR}/*.h")

add_executable(${PROJECT_NAME}
        ${sources}
)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
