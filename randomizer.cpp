#include "randomizer.h"
#include <random>

int randomizer(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(100000, 999999);
    int randomNumber = dist(gen);

    return randomNumber;
}
