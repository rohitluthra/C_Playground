cmake_minimum_required(VERSION 3.17)
project(Pointers)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(1_Pointers_and_Memory)
include_directories(2_Dynamic_Memory_Management_In_C)
include_directories(3_Pointers_And_Functions)
include_directories(4_Pointers_And_Arrays)
include_directories(5_Pointers_And_Strings)
include_directories(6_Pointers_And_Structures)
include_directories(7_Security_Issues_And_Improper_Use_Of_Pointers)
include_directories(8_Odds_And_Ends)

add_executable(Pointers
        1_Pointers_and_Memory/main.c
        README.md 2_Dynamic_Memory_Management_In_C/main.c 3_Pointers_And_Functions/main.c)
