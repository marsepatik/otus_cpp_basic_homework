#include <iostream>
#include <ctime>
#include <cstdlib>
#include "random.h"

int random_value()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    const int random_value = std::rand() % 100;

    return random_value;
}