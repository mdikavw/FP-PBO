#ifndef PELANGGAN_H
#define PELANGGAN_H

#include <vector>
#include "menu.h"

class Pelanggan{
    public:
        int idPelanggan;
        std::vector<Item> pesanan;
    Pelanggan(int x):idPelanggan(x){};
    
    void tambahPesanan(Menu menu);
};

#endif
