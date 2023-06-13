#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item{
    public:
        int idItem;
        std::string nama;
        int harga;
        Item(int x, std::string y, int z);
};

#endif
