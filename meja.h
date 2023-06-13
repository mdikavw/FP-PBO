#ifndef MEJA_H
#define MEJA_H

#include <vector>
#include "menu.h"
#include "pelanggan.h"
#include "nota.h"
#include "nota_individu.h"

class Meja{
    public:
        int jumlahPelanggan;
        int idMeja;
        int idPemesanan;
        std::vector<Pelanggan> pelanggan;

    Meja(int x, int y, int z ,Menu menu);

    void tambahPelanggan(int id, Menu menu);

    ~Meja();
};

#endif
