#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include "item.h"

class Menu{
    public:
        std::vector<Item> daftarMenu;

        Menu();
    
        void printMenu();
};

#endif
