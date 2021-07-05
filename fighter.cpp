#include "fighter.hpp"

Player::Player() {
    /* Roll stats */
    lvl = 1;
    exp = 0;
    hp_max = 12;
    hp_now = 12;
    armor = 10;
    if( rand_range(100) == 7 ) {
        str_base = 18;
        str_mod = rand_range(100) + 1;
    }
    else {
        str_base = 16;
        str_mod = 0;
    }
}
