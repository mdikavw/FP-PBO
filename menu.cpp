#include "menu.h"
#include <iostream>
#include <fstream>
#include <sstream>

Menu::Menu()
{
    int switcher = 1;
    int id = 1;
    std::string menuString;
    std::ifstream menuFile("main.txt");

    while (std::getline(menuFile, menuString))
    {
        std::string namaHarga;
        std::string nama;
        std::string harga;
        std::istringstream iss(menuString);

        while (std::getline(iss, namaHarga, ','))
        {
            if (switcher == 1)
            {
                nama = namaHarga;
                switcher++;
            }
            else if (switcher == 2)
            {
                harga = namaHarga;
                switcher--;
            }
        }

        Item newItem(id, nama, std::stoi(harga));
        daftarMenu.push_back(newItem);
        id++;
    }

    menuFile.close();
}

void Menu::printMenu()
{
    for (int i = 0; i < daftarMenu.size(); i++)
    {
        std::cout << daftarMenu[i].idItem << " " << daftarMenu[i].nama << " --- " << daftarMenu[i].harga << std::endl;
    }
}
