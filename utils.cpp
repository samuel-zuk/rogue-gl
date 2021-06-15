#include "utils.hpp"

int rand_range(int max) {
    srand(time(NULL)); 
    return rand() % max;
}
