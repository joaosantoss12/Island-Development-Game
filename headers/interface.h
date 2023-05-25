#ifndef TPPOO_INTERFACE_H
#define TPPOO_INTERFACE_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <ios>       //used to get stream size para limpar buffer do cin (O caracter /n)
#include <limits>    //used to get numeric limits para limpar buffer do cin (O caracter /n)

#include "ilha.h"
#include <Windows.h>
#include <unistd.h>

using namespace std;

class engine;

class Interface {

public:
    Interface();
    ~Interface();

// Menu Inicial (Preparacao)
    int comeca(); //função que inicia o programa
    void static menucomandosInicio(); //lista de comandos inicial
    void instrucoes();

// Menu durante o jogo (Jogar)
    void static menucomandosJogo(); //lista de comandos durante o jogo
    int jogada(int linhas, int colunas);
};


#endif //TPPOO_INTERFACE_H
