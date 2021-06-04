cmake_minimum_required(VERSION 3.5.1)

## defines project's name and version
project(BarcodeScanner VERSION 0.6.2)

## set the C standard to 11
set(CMAKE_C_STANDARD 11)

## set var for build directory
set(BLD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)

## set var for the include directory
set(INCL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

## set var for the source directory
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

## check if the builld tool matches the needed and set warning levels for compilation
if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall
                        -Wextra
                        -Werror
                        -Wundef
                        -Wuninitialized
                        -Wshadow
                        -Wpointer-arith
                        -Wcast-align
                        -Wcast-qual
                        -Wunused-parameter
                        -Wlogical-op
                        -Wdouble-promotion
                        -Wduplicated-cond
                        -Wduplicated-branches
                        -Wnull-dereference)
endif()

## generate project binary
add_executable(
    ${PROJECT_NAME}-${PROJECT_VERSION}

    ${SRC_DIR}/main.c
    ${SRC_DIR}/decoder.c
    ${SRC_DIR}/getSensorsData.c
    ${SRC_DIR}/reverser.c
    ${SRC_DIR}/strrev.c
    ${SRC_DIR}/checkDigit.c
)

## include the include folder with the header files
include_directories(
    ${PROJECT_NAME}

    PRIVATE

    ${INCL_DIR}
)

## message when launchin cmake to display info about the project
message(STATUS "Project: ${PROJECT_NAME} v${PROJECT_VERSION}")
