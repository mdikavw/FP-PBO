#include "meja.h"
#include <iostream>

Meja::Meja(int x, int y, int z ,Menu menu):idMeja(x), jumlahPelanggan(y), idPemesanan(z){
        for(int i = 0; i < jumlahPelanggan; i++){
            tambahPelanggan(i + 1, menu);
        }
    }

void Meja::tambahPelanggan(int id, Menu menu){
    Pelanggan newPelanggan(id);
        newPelanggan.tambahPesanan(menu);
        pelanggan.push_back(newPelanggan);
}

Meja::~Meja(){
    Nota nota(idMeja, idPemesanan);
        nota.hitungTotal(pelanggan);
        nota.generateDaftarPesanan(pelanggan);
        nota.printHeader(jumlahPelanggan);
        nota.printNota();
        std::cout << std::endl;
        for(int i = 0; i < pelanggan.size(); i++){
            NotaIndividu newNotaIndividu(i + 1, idPemesanan);
            newNotaIndividu.hitungTotal(pelanggan[i].pesanan);
            newNotaIndividu.generateJumlahPesanan(pelanggan[i].pesanan);
            newNotaIndividu.printHeader(idMeja, i + 1);
            newNotaIndividu.printNota(pelanggan[i].pesanan);
        }
        system("PAUSE");
}
