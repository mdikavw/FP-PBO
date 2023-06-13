#include "nota_individu.h"
#include <iostream>
#include <fstream>
#include <ctime>

NotaIndividu::NotaIndividu(int x, int y):Nota(x, y){}

void NotaIndividu::generateJumlahPesanan(std::vector<Item> pesanan){
    for(int i = 0; i < pesanan.size(); i++){
            jumlahPesanan.push_back(1);
        }
}

void NotaIndividu::printHeader(int x, int y){
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
        fileNota << "Id Pemesanan: " << idPemesanan << std::endl;
        std::cout << "Id Pemesanan: " << idPemesanan << std::endl;
        fileNota << "Id Meja: " << x << std::endl;
        std::cout << "Id Meja: " << x << std::endl;
        fileNota << "Id Pelanggan: " << y << std::endl;
        std::cout << "Id Pelanggan: " << y << std::endl;
        fileNota << std::endl << std::endl;        
        std::cout << std::endl << std::endl;
        fileNota.close();
}

void NotaIndividu::printNota(std::vector<Item> pesanan){
    time_t rawtime;
    struct tm*timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    std::strftime(buffer, 80, "%d%m%Y", timeinfo);
    std::string str(buffer);
    std::ofstream fileNota;
        fileNota.open("nota_" +str+"_"+ std::to_string(idPemesanan) + ".txt", std::fstream::app);
        for(int i = 0; i < pesanan.size() - 1; i++){
            for(int j = i + 1; j < pesanan.size(); j++){
                if(pesanan[i].idItem == pesanan[j].idItem){
                    pesanan.erase(pesanan.begin() + j);
                    jumlahPesanan.erase(jumlahPesanan.begin() + j);
                    jumlahPesanan[i]++;
                    j--;
                }
            }
        }
        for(int i = 0; i < pesanan.size(); i++){
            fileNota << pesanan[i].nama << std::endl;
            std::cout << pesanan[i].nama << std::endl;
            fileNota << "x" << jumlahPesanan[i] << "\t\t\t" << pesanan[i].harga*jumlahPesanan[i]<< std::endl << std::endl;
            std::cout << "x" << jumlahPesanan[i] << "\t\t\t" << pesanan[i].harga*jumlahPesanan[i]<< std::endl << std::endl;
        }
        fileNota << std::endl << "Total:\t\t\t" << total << std::endl << std::endl;
        std::cout << std::endl << "Total:\t\t\t" << total << std::endl << std::endl;
        fileNota.close();
    }

void NotaIndividu::hitungTotal(std::vector<Item> pesanan){
    for(int i = 0; i < pesanan.size(); i++){
            total = total + pesanan[i].harga;
        }
}
