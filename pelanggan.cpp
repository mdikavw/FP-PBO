#include <iostream>
#include "pelanggan.h"

void Pelanggan::tambahPesanan(Menu menu){
    int idItem;
        char pilihan;
        do{
            system("CLS");
            menu.printMenu();
            std::cout << "Pilih pesanan untuk pelanggan " << idPelanggan << ": " << std::endl;
            std::cin >> idItem;
            pesanan.push_back(menu.daftarMenu[idItem - 1]);
            std::cout << "Apakah pelanggan " << idPelanggan << " ingin menambah pesanan?(y/n): ";
            std::cin >> pilihan;
        } while(pilihan == 'y');
}
