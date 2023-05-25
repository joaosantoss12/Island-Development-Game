#ifndef TPPOO_MUNDO_H
#define TPPOO_MUNDO_H

#include <string>
#include <vector>
#include <iostream>
#include <ctime>
#include <unistd.h>
#include "Edificio.h"
#include "Trabalhador.h"
#include "utils.h"

using namespace std;

class Trabalhador;
class Edificio;

class Zona {

protected:
    int linha;
    int coluna;
    string tipo;

    Edificio edificio;

public:
    Zona(){};
    Zona(string tipo, int lin, int col) : tipo(tipo), linha(lin), coluna(col) {}

    vector <Trabalhador> pointerTrabalhador;

    string getTipo();
    void zZNZ();

    // Edificios
    void construirEdificio(string tipo);
    void setTipoEdificio(string tipo);
    string getEdificio();
    void aumentarDiasEdificios();
    void desabamentoEdificio(int flag_pantano);
    int getArmazenamentoEdificio();
    void addArmazenamentoEdificio(int valor);
    void setPower(int a);
    int getPower();
    void setNivelEdificio();
    int getNivelEdificio();

    // Recursos (extra)
    int produzMontanha();
    int produzFloresta();

    // Trabalhadores
    void configTrabalhador(string tipo, Trabalhador trab);
    string getTrabalhadorTipo();
    string getTrabalhadorID(int nPosicao);
    int getNumTrabalhadores();
    void getTrabalhador();
    void incrementarDiasContrato();
    void despedirTrabalhadorDia(string zona);
    void removerTrabalhador(int posicao);
    Trabalhador copia(int posicao);

    bool trabalhadorMineiro();
    bool trabalhadorOperario();
    bool trabalhadorLenhador();
};

#endif //TPPOO_MUNDO_H
