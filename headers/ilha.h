#ifndef TPPOO_ILHA_H
#define TPPOO_ILHA_H

#include <string>
#include <vector>
#include "interface.h"
#include "Zona.h"
#include "engine.h"
#include "utils.h"

using namespace std;

class Zona;
class Edificio;
class Trabalhador;

class ilha{
protected:
    int nlinhas;
    int ncolunas;
    int nTrabalhadores=0;

public:
    ilha(){};
    ilha(int linhas, int colunas) : nlinhas(linhas), ncolunas(colunas){}

    void configIlha();
    void mostrarIlha();

    void rZona(int a);
    void rEdificio(int a);
    void rTrabalhadores(int a);

    vector <Zona> pointerZonas;

    int sucessoEdificio=0;

    // Recursos e informação
    float dinheiro = 250;
    int dia = 1;
    int vigasMadeira = 99;
    int madeira = 10;
    float ferro = 10.0f;            // f no final para o compilador nao tornar o valor em double por default
    int barrasAco = 10;
    float carvao = 10.0f;
    int eletricidade = 10;
    // =====================

    // Recolher recursos
    void producaoMinaF();
    void producaoMinaC();
    void producaoCentralE();
    void armazentamentoBateria();
    void producaoFundicao();
    void producaoEdX();
    void producaoMontanha();
    void producaoFloresta();
    void zonaZNZ();

    void addFerro(float quantidade);
    void addCarvao(float quantidade);
    void addEletricidade(int quantidade);
    void addAco(int quantidade);
    void addVigas(int quantidade);
    // ==================================================

    // Edificios
    int configEdificio(string ed, int linha, int coluna);
    void ligarEdificio(int lin, int col);
    void desligarEdificio(int lin, int col);
    void upgradeEdificio(int lin, int col);
    void incrementarDiasEdificios();
    void vendeEdificio(int linha, int coluna);
    void desabarEdificio();

    // Trabalhadores
    void contratarTrabalhador(string tipo);
    int getNumeroTrabalhadores(int a);
    void moverTrabalhador(string id, int lin, int col);
    void incrementarDiasTrabalhador();
    void despedirDiasContrato();
    int contadorMineiros = 0;
    int contadorOperarios = 0;
    int contadorLenhadores = 0;
    void debkillTrabalhador(string id);

    bool verificaFimJogo();
};


#endif //TPPOO_ILHA_H
