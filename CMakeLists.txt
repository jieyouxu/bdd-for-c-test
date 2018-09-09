CMAKE_MINIMUM_REQUIRED(VERSION 3.12)
PROJECT(bdd_for_c_test C)

SET(CMAKE_C_STANDARD 11)

INCLUDE_DIRECTORIES(.)

SET(PROJECT_SOURCES
    floating-point-comparison.spec.c
    floating-point-comparison.c
    floating-point-comparison.h
    bdd-for-c.h)

ADD_EXECUTABLE(project_sources ${PROJECT_SOURCES})