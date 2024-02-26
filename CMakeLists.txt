cmake_minimum_required(VERSION 3.5)

project(03.guess_the_number)

add_executable(guess_the_number 
    Guess_The_Number.cpp
    welcome.cpp
    welcome.h
    user_name.cpp
    user_name.h
    random.cpp
    random.h
    game.cpp
    game.h
)

set_target_properties(guess_the_number PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)