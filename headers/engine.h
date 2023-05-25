#ifndef TPPOO_ENGINE_H
#define TPPOO_ENGINE_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <time.h>

#include "Zona.h"
#include "ilha.h"
#include "Edificio.h"
#include "Zona.h"
#include "utils.h"

using namespace std;

class ilha;

class engine{

public:
    engine(){};
    ~engine(){};

    void amanhecer(ilha &i);
    void meioDia();
    void anoitecer(ilha &il);

    void processaFicheiro(string nome_ficheiro, ilha &i, int linhas, int colunas);
    int processaComandoFicheiro(istringstream &iss, ilha &i, int linhas, int colunas);
};

#endif //TPPOO_ENGINE_H
