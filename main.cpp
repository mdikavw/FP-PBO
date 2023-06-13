#include "item.h"
#include "meja.h"
#include "nota.h"
#include "nota_individu.h"
#include "pelanggan.h"
#include "menu.h"
#include "randomizer.h"
#include <iostream>

int main(){
    char ulang;
    do{
    Menu menu;
    int pilihan;
    std::cout << "1. Tambah meja" << std::endl;
    std::cout << "2. Keluar" << std::endl;
    std::cout << "Masukkan pilihan: ";
    std::cin >> pilihan;
        switch(pilihan){
        case 1: {
            int idMeja;
            int jumlahPelanggan;
            std::cout << "Masukkan id meja: ";
            std::cin >> idMeja;
            std::cout << "Masukkan jumlah pelanggan: ";
            std::cin >> jumlahPelanggan;
            Meja meja(idMeja, jumlahPelanggan, randomizer(), menu);
            break;
        }
        case 2: {
            std::cout << "Program selesai" << std::endl;
            break;
        }
        default: {
            std::cout << "Pilihan tidak tersedia" << std::endl;
            break;
        }
        }
        std::cout << "Ingin menambahkan meja (y/n)? ";
        std::cin >> ulang;
    } while (ulang == 'y');
    
    
    

    return 0;
}