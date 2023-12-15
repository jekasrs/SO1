cmake_minimum_required(VERSION 3.26)
project(lab5 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab5 main1.c
        geoCoord.h
        functions.c
        functions.h
        main2.c
)
