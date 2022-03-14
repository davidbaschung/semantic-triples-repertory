cmake_minimum_required(VERSION 3.13)
project(projet_SOP)

set(CMAKE_C_STANDARD 99)

add_executable(projet_SOP
		src/test.c
		src/insert.c
		src/match.c
		src/erase.c)