#ifndef NOTA_H
#define NOTA_H

#include <vector>
#include <string>
#include <fstream>
#include "item.h"
#include "pelanggan.h"

class Nota{
    public:
        int idNota;
        int idPemesanan;
        int total = 0;
        std::vector<Item> daftarPesanan;
        std::vector<int> jumlahPesanan;
    Nota(int x, int y);

    void printNota();
    void generateDaftarPesanan(std::vector<Pelanggan> pelanggan);
    void printHeader(int x);
    void hitungTotal(std::vector<Pelanggan> pelanggan);
};

#endif
