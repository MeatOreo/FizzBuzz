cmake_minimum_required(VERSION 3.10.0)
project(FizzBuzz VERSION 0.1.0 LANGUAGES C)

add_executable(FizzBuzz main.c)



add_compile_options(-static -Wall -Wpedantic)

include(CTest)
enable_testing()

add_executable(testFizz testFizz.c)
add_test(NAME FizzBuzzVerifier COMMAND testFizz)