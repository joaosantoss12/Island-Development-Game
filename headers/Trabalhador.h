#ifndef TPPOO_TRABALHADOR_H
#define TPPOO_TRABALHADOR_H

#include <iostream>
#include <string.h>
using namespace std;

class Trabalhador {


public:
    Trabalhador(){};
    Trabalhador(string id, float probability, int contDay) : id(id), probabilidade(probability), diasContrato(contDay) {};

    // Variáveis do trabalhador
    string id;
    string tipo;
    double probabilidade;
    int diasContrato;

    void setTipo(string nomeTipo);
    string getTipo();

    void setID(int a, int dia);
    string getID();
    void setIDcopia(string idCopia);

    void aumentarDiasContrato();
    int getDiasContrato();

};


class Mineiro : public Trabalhador{
public:
    Mineiro(string id, float probability, int contDay = 1) : Trabalhador(id,probability,contDay) {}
};

class Operario : public Trabalhador{
    public:
    Operario(string id, float probability, int contDay = 1) : Trabalhador(id,probability,contDay) {}
};

class Lenhador : public Trabalhador{
    public:
    Lenhador(string id, float probabilidade, int contDay = 1) : Trabalhador(id,probabilidade,contDay){}
};

#endif //TPPOO_TRABALHADOR_H
