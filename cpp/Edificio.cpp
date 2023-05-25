#include "../headers/Edificio.h"

void Edificio::setTipo(string nome){
    tipo = nome;
}

string Edificio::getTipo(){
    return tipo;
};

int Edificio::getArmazenamento(){
    return armazenamento;
}

void Edificio::addArmazenamento(int a){
    armazenamento += a;
}

void Edificio::aumentarDiasConstrucao(){
    diasConstrucao += 1;
}

int Edificio::getDiasConstrucao(){
    return diasConstrucao;
}