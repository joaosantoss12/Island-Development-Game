#include "../headers/Trabalhador.h"

void Trabalhador::setID(int a, int day){
    id = to_string(a) + "." + to_string(day);
    cout << "ID do trabalhador: " << id << endl << endl;
};

void Trabalhador::setIDcopia(string idCopia){
    id = idCopia;
}

void Trabalhador::setTipo(string nomeTipo){
     tipo = nomeTipo;
};

string Trabalhador::getID(){
    return id;
};

string Trabalhador::getTipo(){
    return tipo;
};

void Trabalhador::aumentarDiasContrato(){
    diasContrato += 1;
};

int Trabalhador::getDiasContrato(){
    return diasContrato;
};
