/* all the types of object an item can be */
#define T_POTION    0
#define T_SCROLL    1
#define T_FOOD      2
#define T_WEAPON    3
#define T_ARMOR     4
#define T_MAGIC     5 /* rods, wands, staves */  
#define T_RING      6
#define NUMTYPES    7

class Item {
    private:
        int type;       /* item category (potion, weapon, etc) */
        int which;      /* what {potion, weapon, etc} is this */
    public:
        Item(int, int);
};

