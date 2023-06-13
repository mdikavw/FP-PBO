#include "nota.h"
#include <iostream>
#include <fstream>
#include <ctime>

Nota::Nota(int x, int y):idNota(x), idPemesanan(y){}

void Nota::printNota(){
    time_t rawtime;
    struct tm*timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    std::strftime(buffer, 80, "%d%m%Y", timeinfo);
    std::string str(buffer);
    std::ofstream fileNota; 
    fileNota.open("nota_" +str+"_"+ std::to_string(idPemesanan) + ".txt", std::fstream::app);
        for(int i = 0; i < daftarPesanan.size() - 1; i++){
            for(int j = i + 1; j < daftarPesanan.size(); j++){
                if(daftarPesanan[i].idItem == daftarPesanan[j].idItem){
                    daftarPesanan.erase(daftarPesanan.begin() + j);
                    jumlahPesanan.erase(jumlahPesanan.begin() + j);
                    jumlahPesanan[i]++;
                    j--;
                }
            }
            }
        for(int i = 0; i < daftarPesanan.size(); i++){
            fileNota << daftarPesanan[i].nama << std::endl;
            std::cout << daftarPesanan[i].nama << std::endl;
            fileNota << "x" << jumlahPesanan[i] << "\t\t\t" << daftarPesanan[i].harga*jumlahPesanan[i]<< std::endl << std::endl;
            std::cout << "x" << jumlahPesanan[i] << "\t\t\t" << daftarPesanan[i].harga*jumlahPesanan[i]<< std::endl << std::endl;
        }
        fileNota << std::endl << "Total:\t\t\t" << total << std::endl;
        std::cout << std::endl << "Total:\t\t\t" << total << std::endl;
}

void Nota::generateDaftarPesanan(std::vector<Pelanggan> pelanggan){
    for(int i = 0; i < pelanggan.size(); i++){
            for(int j = 0; j < pelanggan[i].pesanan.size(); j++){
                daftarPesanan.push_back(pelanggan[i].pesanan[j]);
            }
        }
        for(int i = 0; i < daftarPesanan.size(); i++){
            jumlahPesanan.push_back(1);
        }
}

void Nota::printHeader(int x){
    time_t rawtime;
    struct tm*timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    std::strftime(buffer, 80, "%d%m%Y", timeinfo);
    std::string str(buffer);
    std::ofstream fileNota; 
        fileNota.open("nota_" +str+"_"+ std::to_string(idPemesanan) + ".txt", std::fstream::app);
        fileNota << "----------Nota----------" << std::endl;
        std::cout << "----------Nota----------" << std::endl;
        std::cout << str <<std::endl;
        fileNota << "Id Pemesanan: " << idPemesanan << std::endl;
        std::cout << "Id Pemesanan: " << idPemesanan << std::endl;
        fileNota << "Id Meja: " << idNota << std::endl;
        std::cout << "Id Meja: " << idNota << std::endl;
        fileNota << "Jumlah pelanggan: " << x << std::endl;
        std::cout << "Jumlah pelanggan: " << x << std::endl;
        fileNota << std::endl << std::endl;        
        std::cout << std::endl << std::endl;    
}

void Nota::hitungTotal(std::vector<Pelanggan> pelanggan){
    for(int i = 0; i < pelanggan.size(); i++){
            for(int j = 0; j < pelanggan[i].pesanan.size(); j++){
                total = total + pelanggan[i].pesanan[j].harga;
            }
        }
}
