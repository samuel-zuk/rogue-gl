#include "utils.cpp"
#include "fighter.hpp"
#include "item.hpp"

class World {
    private:
        const int type_prob[NUMTYPES * 2] = {
        /*  Describes the likelihood of each type
         *  of item appearing in the dungeon 
         *  =====================================
         *  Item Type   Probability (out of 100) */ 
            T_POTION,   27,
            T_SCROLL,   27,
            T_FOOD,     18,
            T_WEAPON,   9,
            T_ARMOR,    9,
            T_MAGIC,    5,
            T_RING,     5
        };
        Player player;
}
