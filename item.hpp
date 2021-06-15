/* all the types of object an item can be */
#define CAT_POTION  0
#define CAT_SCROLL  1
#define CAT_WEAPON  2
#define CAT_ARMOR   3
#define CAT_RING    4
#define CAT_MAGIC   5 /* rods, wands, staves */  
#define CAT_AMULET  6

class Item {
    private:
        int category;   /* item category (potion, weapon, etc) */
        int qty;        /* how many of this item there is */
        int type;       /* what {potion, weapon, etc} is this */
    public:
        Item(int, int, int);
};
