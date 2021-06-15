#include "utils.hpp"
#include "item.hpp"

class Fighter {
    int lvl, exp, armor, hp_now, hp_max, str_base, str_mod;

};

class Player : public Fighter {
    private:
        std::vector<Item> inventory; 
    public:
        Player();
};
