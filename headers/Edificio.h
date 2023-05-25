#ifndef TPPOO_EDIFICIO_H
#define TPPOO_EDIFICIO_H

#include <iostream>

using namespace std;

class Edificio {

public:
    string tipo;
    int nivel;
    int ligar;
    int armazenamento;
    int diasConstrucao;

    Edificio(){}
    Edificio(string type, int level, int power, int storage, int consDay) : tipo(type) , nivel(level), ligar(power), armazenamento(storage), diasConstrucao(consDay){}

    string getTipo();
    void setTipo(string nome);
    int getArmazenamento();
    void addArmazenamento(int a);
    void aumentarDiasConstrucao();
    int getDiasConstrucao();
};


class MinaFerro : public Edificio {

public:
    MinaFerro(string t = "mnF", int level=1, int power=0, int storage=0, int consDay=1) : Edificio(t,level,power,storage,consDay) {};
};

class MinaCarvao : public Edificio{

public:
    MinaCarvao(string t = "mnC", int level=1, int power=0, int storage=0, int consDay=1) : Edificio(t,level,power,storage,consDay) {};
};

class CentralEletrica : public Edificio{

public:
    CentralEletrica(string t = "elec", int level=1, int power=0, int storage=0, int consDay=1) : Edificio(t,level,power,storage,consDay) {};
};

class Bateria : public Edificio{

public:
    Bateria(string t = "bat", int level=1, int power=0, int storage=0, int consDay=1) : Edificio(t,level,power,storage,consDay) {};
};

class Fundicao : public Edificio{

public:
    Fundicao(string t = "fun", int level=1, int power=0, int storage=0, int consDay=1) : Edificio(t,level,power,storage,consDay) {};
};

class EdificioX : public Edificio{

public:
    EdificioX(string t = "edX", int level=1, int power=0, int storage=0, int consDay=1) : Edificio(t,level,power,storage,consDay) {};
};

#endif //TPPOO_EDIFICIO_H
