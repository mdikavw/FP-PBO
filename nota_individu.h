#ifndef NOTAINDIVIDU_H
#define NOTAINDIVIDU_H

#include <vector>
#include <string>
#include <fstream>
#include "nota.h"

class NotaIndividu : public Nota{
    public:
    NotaIndividu(int x, int y);

    void generateJumlahPesanan(std::vector<Item> pesanan);
    void printHeader(int x, int y);
    void printNota(std::vector<Item> pesanan);
    void hitungTotal(std::vector<Item> pesanan);
};

#endif
