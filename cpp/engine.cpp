#include "../headers/engine.h"

void engine::amanhecer(ilha &il) {
    cout << endl << "AMANHECENDO..." << endl << "Os efeitos das zonas estao a ser efetuados..." << endl;
    cout << endl << "----------------------" << endl;
    cout << "Dia: " << il.dia << endl;
    cout << "Dinheiro: " << il.dinheiro << " euros" << endl;
    cout << "----------------------" << endl;
    cout << "Vigas de Madeira: " << il.vigasMadeira << endl;
    cout << "Madeira: " << il.madeira << endl;
    cout << "Ferro: " << il.ferro << endl;
    cout << "Barras de Aco: " << il.barrasAco << endl;
    cout << "Carvao: " << il.carvao << endl;
    cout << "Eletricidade: " << il.eletricidade << endl;
    cout << "----------------------" << endl;
    cout << "Total Mineiros contratados: " << il.contadorMineiros << endl;
    cout << "Total Operarios contratados: " << il.contadorOperarios << endl;
    cout << "Total Lenhadores contratados: " << il.contadorLenhadores << endl;
    cout << "----------------------" << endl << endl;
    il.mostrarIlha();
};

void engine::meioDia(){
    cout << endl << "MEIO DIA..." << endl;
};

void engine::anoitecer(ilha &il){   // enviar ilha
    cout << endl << "ANOITECENDO..." << endl << "Os recursos obtidos estao a ser recolhidos..." << endl;
    il.producaoMinaF();
    il.producaoMinaC();
    il.producaoCentralE();
    il.armazentamentoBateria();
    il.producaoFundicao();
    il.producaoEdX();
    il.producaoMontanha();
    il.producaoFloresta();
    il.zonaZNZ();
};

void engine::processaFicheiro(string nome_ficheiro, ilha &i, int linhas, int colunas) {
    engine engine;
    //abrir o ficheiro
    ifstream ficheiro;
    ficheiro.open(nome_ficheiro);

    cout << "A abrir o ficheiro " << nome_ficheiro << "..." << endl;

    if (ficheiro.is_open()) {
        //abriu com sucesso
        cout << "A processar o ficheiro..." << endl;
        cout << endl;
        string comando_ficheiro;

        while (getline(ficheiro, comando_ficheiro)) {
            istringstream iss(comando_ficheiro);
            processaComandoFicheiro(iss, i, linhas, colunas);
        }
        ficheiro.close();
    } else {
        //não foi possível abrir o ficheiro
        cout << "Erro ao abrir o ficheiro " << nome_ficheiro << endl;
        cout << endl;
    }
}

int engine::processaComandoFicheiro(istringstream &iss, ilha &i, int linhas, int colunas) {

    string comandoJogada, tipo;
    int lin,col;
    engine engine;
    getline(iss, comandoJogada);
    stringstream ss(comandoJogada);
    ss >> comandoJogada;

//  =====================================  COMANDO "CONS"  ======================================
    if (comandoJogada == "cons") {
        iss >> tipo;
        iss >> lin;
        iss >> col;

// ======================= MINA FERRO ===========================================================
        if (tipo == "minaf") {
            float contador = -1;
            int done = 0;

            for(auto a = i.pointerZonas.begin() ; a != i.pointerZonas.end() ; ++a){
                if(a->getTipo() == "mnt"){
                    if (i.vigasMadeira >= 20) {
                        if (lin > 0 && lin < linhas + 1) {
                            if (col > 0 && col < colunas + 1) {
                                i.configEdificio(tipo, lin, col);
                                if(i.sucessoEdificio == 1){
                                    cout << "Construiu uma mina de ferro com sucesso por 10 vigas de madeira!" << endl << "Linha: " << lin << endl << "Coluna: " << col << endl << endl;
                                }
                            }
                            else {
                                cout << endl << "Numero de colunas invalido!" << endl;
                            }
                        }
                        else {
                            cout << endl << "Numero de linhas invalido!" << endl;
                        }
                        i.vigasMadeira -= 20;
                        done = 1;
                    }
                    else if (i.vigasMadeira < 20) {
                        for (int xd = i.vigasMadeira; xd <= 20; xd++) {
                            contador++;
                        }
                        if (i.dinheiro >= (contador * 20)) {
                            if (lin > 0 && lin < linhas + 1) {
                                if (col > 0 && col < colunas + 1) {
                                    i.configEdificio(tipo, lin, col);
                                    if(i.sucessoEdificio == 1) {
                                        cout << "Construiu uma mina de ferro com sucesso por 20 vigas de madeira!" << endl << endl;
                                    }
                                }
                                else {
                                    cout << endl << "Numero de colunas invalido!" << endl;
                                }
                            }
                            else {
                                cout << endl << "Numero de linhas invalido!" << endl;
                            }
                            i.dinheiro -= (contador * 20);
                            i.vigasMadeira = 0;
                            done = 1;
                        }
                    }
                    if (done == 0) {
                        cout << endl << "Recursos insuficientes!" << endl;
                        cout << "Uma mina de ferro custa 20 vigas de madeira (ou 10 euros por cada em falta)!" << endl << endl;
                    }
                }
                else{
                    if (i.vigasMadeira >= 10) {
                        if (lin > 0 && lin < linhas + 1) {
                            if (col > 0 && col < colunas + 1) {
                                i.configEdificio(tipo, lin, col);
                                if(i.sucessoEdificio == 1){
                                    cout << "Construiu uma mina de ferro com sucesso por 10 vigas de madeira!" << endl << "Linha: " << lin << endl << "Coluna: " << col << endl << endl;
                                }
                            }
                            else {
                                cout << endl << "Numero de colunas invalido!" << endl;
                            }
                        }
                        else {
                            cout << endl << "Numero de linhas invalido!" << endl;
                        }
                        i.vigasMadeira -= 10;
                        done = 1;
                    }
                    else if (i.vigasMadeira < 10) {
                        for (int xd = i.vigasMadeira; xd <= 10; xd++) {
                            contador++;
                        }
                        if (i.dinheiro >= (contador * 10)) {
                            if (lin > 0 && lin < linhas + 1) {
                                if (col > 0 && col < colunas + 1) {
                                    i.configEdificio(tipo, lin, col);
                                    if(i.sucessoEdificio == 1) {
                                        cout << "Construiu uma mina de ferro com sucesso por 10 vigas de madeira!" << endl << endl;
                                    }
                                }
                                else {
                                    cout << endl << "Numero de colunas invalido!" << endl;
                                }
                            }
                            else {
                                cout << endl << "Numero de linhas invalido!" << endl;
                            }
                            i.dinheiro -= (contador * 10);
                            i.vigasMadeira = 0;
                            done = 1;
                        }
                    }

                    if (done == 0) {
                        cout << endl << "Recursos insuficientes!" << endl;
                        cout << "Uma mina de ferro custa 10 vigas de madeira (ou 10 euros por cada em falta)!" << endl << endl;
                    }
                }
                if(done == 1){
                    break;
                }
            }
        }

// ===================== MINA CARVAO ===============================================================
        else if (tipo == "minac") {
            float contador = -1;
            int done = 0;

            for(auto a = i.pointerZonas.begin() ; a != i.pointerZonas.end() ; ++a){
                if(a->getTipo() == "mnt"){
                    if (i.vigasMadeira >= 10*2) {
                        if (lin > 0 && lin < linhas + 1) {
                            if (col > 0 && col < colunas + 1) {
                                i.configEdificio(tipo, lin, col);
                                if(i.sucessoEdificio == 1){
                                    cout << "Construiu uma mina de carvao com sucesso por 20 vigas de madeira!" << endl << "Linha: " << lin << endl << "Coluna: " << col << endl << endl;
                                }
                            }
                            else {
                                cout << endl << "Numero de colunas invalido!" << endl;
                            }
                        }
                        else {
                            cout << endl << "Numero de linhas invalido!" << endl;
                        }
                        i.vigasMadeira -= 10*2;
                        done = 1;
                    }
                    else if (i.vigasMadeira < 10*2) {
                        for (int xd = i.vigasMadeira; xd <= 10*2; xd++) {
                            contador++;
                        }
                        if (i.dinheiro >= (contador * 20)) {
                            if (lin > 0 && lin < linhas + 1) {
                                if (col > 0 && col < colunas + 1) {
                                    i.configEdificio(tipo, lin, col);
                                    if(i.sucessoEdificio == 1) {
                                        cout << "Construiu uma mina de carvao com sucesso por 20 vigas de madeira!" << endl << endl;
                                    }
                                }
                                else {
                                    cout << endl << "Numero de colunas invalido!" << endl;
                                }
                            }
                            else {
                                cout << endl << "Numero de linhas invalido!" << endl;
                            }
                            i.dinheiro -= (contador * 20);
                            i.vigasMadeira = 0;
                            done = 1;
                        }
                    }
                    if (done == 0) {
                        cout << endl << "Recursos insuficientes!" << endl;
                        cout << "Uma mina de carvao custa 20 vigas de madeira (ou 10 euros por cada em falta)!" << endl << endl;
                    }
                }
                else{
                    if (i.vigasMadeira >= 10) {
                        if (lin > 0 && lin < linhas + 1) {
                            if (col > 0 && col < colunas + 1) {
                                i.configEdificio(tipo, lin, col);
                                if(i.sucessoEdificio == 1){
                                    cout << "Construiu uma mina de carvao com sucesso por 10 vigas de madeira!" << endl << "Linha: " << lin << endl << "Coluna: " << col << endl << endl;
                                }
                            }
                            else {
                                cout << endl << "Numero de colunas invalido!" << endl;
                            }
                        }
                        else {
                            cout << endl << "Numero de linhas invalido!" << endl;
                        }
                        i.vigasMadeira -= 10;
                        done = 1;
                    }
                    else if (i.vigasMadeira < 10) {
                        for (int xd = i.vigasMadeira; xd <= 10; xd++) {
                            contador++;
                        }
                        if (i.dinheiro >= (contador * 10)) {
                            if (lin > 0 && lin < linhas + 1) {
                                if (col > 0 && col < colunas + 1) {
                                    i.configEdificio(tipo, lin, col);
                                    if(i.sucessoEdificio == 1) {
                                        cout << "Construiu uma mina de carvao com sucesso por 10 vigas de madeira!" << endl << endl;
                                    }
                                }
                                else {
                                    cout << endl << "Numero de colunas invalido!" << endl;
                                }
                            }
                            else {
                                cout << endl << "Numero de linhas invalido!" << endl;
                            }
                            i.dinheiro -= (contador * 10);
                            i.vigasMadeira = 0;
                            done = 1;
                        }
                    }

                    if (done == 0) {
                        cout << endl << "Recursos insuficientes!" << endl;
                        cout << "Uma mina de carvao custa 10 vigas de madeira (ou 10 euros por cada em falta)!" << endl << endl;
                    }
                }
                if(done == 1){
                    break;
                }
            }
        }

// ===================== CENTRAL ELETRICA ========================
        else if(tipo == "central"){
            int done = 0;

            for(auto a = i.pointerZonas.begin() ; a != i.pointerZonas.end() ; ++a){
                if(a->getTipo() == "mnt"){
                    if (i.dinheiro >= 30) {
                        if (lin > 0 && lin < linhas + 1) {
                            if (col > 0 && col < colunas + 1) {
                                i.configEdificio(tipo, lin, col);
                                if(i.sucessoEdificio == 1){
                                    cout << "Construiu uma central eletrica com sucesso por 30 euros!" << endl << "Linha: " << lin << endl << "Coluna: " << col << endl << endl;
                                }
                            }
                            else {
                                cout << endl << "Numero de colunas invalido!" << endl;
                            }
                        }
                        else {
                            cout << endl << "Numero de linhas invalido!" << endl;
                        }
                        i.dinheiro -= 30;
                        done = 1;
                    }
                    if (done == 0) {
                        cout << endl << "Dinheiro insuficiente!" << endl;
                        cout << "Uma central eletrica custa 30 euros numa zona de montanha!" << endl << endl;
                    }
                }
                else{
                    if (i.dinheiro >= 15) {
                        if (lin > 0 && lin < linhas + 1) {
                            if (col > 0 && col < colunas + 1) {
                                i.configEdificio(tipo, lin, col);
                                if(i.sucessoEdificio == 1){
                                    cout << "Construiu uma central eletrica com sucesso por 15 euros!" << endl << "Linha: " << lin << endl << "Coluna: " << col << endl << endl;
                                }
                            }
                            else {
                                cout << endl << "Numero de colunas invalido!" << endl;
                            }
                        }
                        else {
                            cout << endl << "Numero de linhas invalido!" << endl;
                        }
                        i.dinheiro -= 15;
                        done = 1;
                    }
                    if (done == 0) {
                        cout << endl << "Dinheiro insuficiente!" << endl;
                        cout << "Uma central eletrica custa 15 euros!" << endl << endl;
                    }
                }
                if(done == 1){
                    break;
                }
            }
        }

// ===================== BATERIA ========================
        else if(tipo == "bat"){
            int done = 0;

            for(auto a = i.pointerZonas.begin() ; a != i.pointerZonas.end() ; ++a){
                if(a->getTipo() == "mnt"){
                    if (i.vigasMadeira >= 10*2 && i.dinheiro >= 10*2) {
                        if (lin > 0 && lin < linhas + 1) {
                            if (col > 0 && col < colunas + 1) {
                                i.configEdificio(tipo, lin, col);
                                if(i.sucessoEdificio == 1){
                                    cout << "Construiu uma bateria com sucesso por 20 vigas de madeira e 20 euros!" << endl << "Linha: " << lin << endl << "Coluna: " << col << endl << endl;
                                }
                            }
                            else {
                                cout << endl << "Numero de colunas invalido!" << endl;
                            }
                        }
                        else {
                            cout << endl << "Numero de linhas invalido!" << endl;
                        }
                        i.vigasMadeira -= 20;
                        i.dinheiro -= 20;
                        done = 1;
                    }
                    if (done == 0) {
                        cout << endl << "Recursos insuficientes!" << endl;
                        cout << "Uma bateria custa 20 vigas de madeira e 20 euros numa zona de montanha!" << endl << endl;
                    }
                }
                else{
                    if (i.vigasMadeira >= 10 && i.dinheiro >= 10) {
                        if (lin > 0 && lin < linhas + 1) {
                            if (col > 0 && col < colunas + 1) {
                                i.configEdificio(tipo, lin, col);
                                if(i.sucessoEdificio == 1){
                                    cout << "Construiu uma bateria com sucesso por 10 vigas de madeira e 10 euros!" << endl << "Linha: " << lin << endl << "Coluna: " << col << endl << endl;
                                }
                            }
                            else {
                                cout << endl << "Numero de colunas invalido!" << endl;
                            }
                        }
                        else {
                            cout << endl << "Numero de linhas invalido!" << endl;
                        }
                        i.vigasMadeira -= 10;
                        i.dinheiro -= 10;
                        done = 1;
                    }
                    if (done == 0) {
                        cout << endl << "Recursos insuficientes!" << endl;
                        cout << "Uma bateria custa 10 vigas de madeira e 10 euros!" << endl << endl;
                    }
                }
                if(done == 1){
                    break;
                }
            }
        }

// ===================== FUNDIÇÃO ========================
        else if(tipo == "fund"){
            int done = 0;

            for(auto a = i.pointerZonas.begin() ; a != i.pointerZonas.end() ; ++a){
                if(a->getTipo() == "mnt"){
                    if (i.dinheiro >= 20) {
                        if (lin > 0 && lin < linhas + 1) {
                            if (col > 0 && col < colunas + 1) {
                                i.configEdificio(tipo, lin, col);
                                if(i.sucessoEdificio == 1){
                                    cout << "Construiu uma fundicao com sucesso por 20 euros!" << endl << "Linha: " << lin << endl << "Coluna: " << col << endl << endl;
                                }
                            }
                            else {
                                cout << endl << "Numero de colunas invalido!" << endl;
                            }
                        }
                        else {
                            cout << endl << "Numero de linhas invalido!" << endl;
                        }
                        i.dinheiro -= 20;
                        done = 1;
                    }
                    if (done == 0) {
                        cout << endl << "Dinheiro insuficiente!" << endl;
                        cout << "Uma fundicao custa 20 euros numa zona de montanha!" << endl << endl;
                    }
                }
                else{
                    if (i.dinheiro >= 10) {
                        if (lin > 0 && lin < linhas + 1) {
                            if (col > 0 && col < colunas + 1) {
                                i.configEdificio(tipo, lin, col);
                                if(i.sucessoEdificio == 1){
                                    cout << "Construiu uma fundicao com sucesso por 10 euros!" << endl << "Linha: " << lin << endl << "Coluna: " << col << endl << endl;
                                }
                            }
                            else {
                                cout << endl << "Numero de colunas invalido!" << endl;
                            }
                        }
                        else {
                            cout << endl << "Numero de linhas invalido!" << endl;
                        }
                        i.dinheiro -= 10;
                        done = 1;
                    }
                    if (done == 0) {
                        cout << endl << "Dinheiro insuficiente!" << endl;
                        cout << "Uma fundicao custa 10 euros!" << endl << endl;
                    }
                }
                if(done == 1){
                    break;
                }
            }
        }

// ===================== EDIFICIO-X ========================
        else if(tipo == "edx"){
            int done = 0;

            for(auto a = i.pointerZonas.begin() ; a != i.pointerZonas.end() ; ++a){
                if(a->getTipo() == "mnt"){
                    if (i.dinheiro >= 10*2) {
                        if (lin > 0 && lin < linhas + 1) {
                            if (col > 0 && col < colunas + 1) {
                                i.configEdificio(tipo, lin, col);
                                if(i.sucessoEdificio == 1){
                                    cout << "Construiu um edificio-X com sucesso por 20 euros!" << endl << "Linha: " << lin << endl << "Coluna: " << col << endl << endl;
                                }
                            }
                            else {
                                cout << endl << "Numero de colunas invalido!" << endl;
                            }
                        }
                        else {
                            cout << endl << "Numero de linhas invalido!" << endl;
                        }
                        i.dinheiro -= 10*2;
                        done = 1;
                    }
                    if (done == 0) {
                        cout << endl << "Dinheiro insuficiente!" << endl;
                        cout << "Um edificio-X custa 20 euros numa zona de montanha!" << endl << endl;
                    }
                }
                else{
                    if (i.dinheiro >= 10) {
                        if (lin > 0 && lin < linhas + 1) {
                            if (col > 0 && col < colunas + 1) {
                                i.configEdificio(tipo, lin, col);
                                if(i.sucessoEdificio == 1){
                                    cout << "Construiu um edificio-X com sucesso por 10 euros!" << endl << "Linha: " << lin << endl << "Coluna: " << col << endl << endl;
                                }
                            }
                            else {
                                cout << endl << "Numero de colunas invalido!" << endl;
                            }
                        }
                        else {
                            cout << endl << "Numero de linhas invalido!" << endl;
                        }
                        i.dinheiro -= 10;
                        done = 1;
                    }
                    if (done == 0) {
                        cout << endl << "Dinheiro insuficiente!" << endl;
                        cout << "Um edificio-X custa 10 euros!" << endl << endl;
                    }
                }
                if(done == 1){
                    break;
                }
            }
        }

        else {
            cout << endl << "Tipo de edificio invalido!" << endl;
        }
    }

//  =====================================  COMANDO "LIGA"  ======================================
    else if (comandoJogada == "liga") {
        int linha, coluna;

        iss >> linha;
        iss >> coluna;

        if (linha < linhas+1 && coluna < colunas+1) {
            i.ligarEdificio(linha,coluna);
        } else
            cout << "Comando usando incorretamente!" << " \"" << comandoJogada << " " << linha << " " << coluna << "\"" << endl << "Use liga <linha> <coluna>" << endl;
    }

//  =====================================  COMANDO "DES"  ======================================
    else if (comandoJogada == "des") {
        int linha, coluna;

        iss >> linha;
        iss >> coluna;

        if (linha < linhas+1 && coluna < colunas+1) {
            i.desligarEdificio(linha,coluna);
        } else
            cout << "Comando usando incorretamente!" << " \"" << comandoJogada << " " << linha << " " << coluna << "\"" << endl << "Use des <linha> <coluna>" << endl;
    }

//  =====================================  COMANDO "UPGRADE"  ======================================
    else if(comandoJogada == "upgrade"){
        int linha, coluna;
        iss >> linha ; iss >> coluna;

        if(linha < linhas+1 && coluna < colunas+1){
            i.upgradeEdificio(linha,coluna);
        }
        else
            cout << "Comando usado incorretamente!" << " \"" << comandoJogada << " " << linha << " " << coluna << "\"" << endl << "Use upgrade <linha> <coluna>" << endl;
    }
//  ================================================================================================

//  =====================================  COMANDO "MOVE"  ======================================
    else if (comandoJogada == "move") {
        int linha, coluna;
        string id;

        iss >> id;
        iss >> linha;
        iss >> coluna;

        if (linha < linhas+1 && coluna < colunas+1) {
            i.moverTrabalhador(id,linha,coluna);
        } else
            cout << "Comando usando incorretamente!" << " \"" << comandoJogada << " " << id << " " << linha << " " << coluna << "\"" << endl << "Use move <linha> <coluna>" << endl;
    }

// COMANDO PARA VENDER RECURSOS
//  =====================================  COMANDO "VENDE"  ======================================
    else if (comandoJogada == "vende"){
        string tipo;
        int quantidade;

        iss >> tipo;
        iss >> quantidade;

        if(tipo == "viga"){
            if(quantidade > i.vigasMadeira){
                cout << endl << "Nao possui vigas de madeira suficientes!" << endl;
            }
            else if(quantidade == i.vigasMadeira){
                i.dinheiro += (quantidade * 2);
                i.vigasMadeira = 0;
                cout << "Vendeu " << quantidade << " vigas por " << quantidade*2 << " euros!" << endl << endl;
            }
            else if(quantidade < i.vigasMadeira){
                i.dinheiro += (quantidade *2);
                i.vigasMadeira -= quantidade;
                cout << "Vendeu " << quantidade << " vigas por " << quantidade*2 << " euros!" << endl << endl;
            }
        }

        else if(tipo == "mad"){
            if(quantidade > i.madeira){
                cout << endl << "Nao possui madeira suficiente!" << endl;
            }
            else if(quantidade == i.madeira){
                i.dinheiro += (quantidade * 1);
                i.madeira = 0;
                cout << "Vendeu " << quantidade << " vigas por " << quantidade*1 << " euros!" << endl << endl;
            }
            else if(quantidade < i.madeira){
                i.dinheiro += (quantidade * 1);
                i.madeira -= quantidade;
                cout << "Vendeu " << quantidade << " unidades de madeira por " << quantidade*1 << " euros!" << endl << endl;
            }
        }

        else if(tipo == "ferro"){
            if(quantidade > i.ferro){
                cout << endl << "Nao possui madeira suficiente!" << endl;
            }
            else if(quantidade == i.ferro){
                i.dinheiro += (quantidade * 1);
                i.ferro = 0;
                cout << "Vendeu " << quantidade << " unidades de ferro por " << quantidade*2 << " euros!" << endl << endl;
            }
            else if(quantidade < i.ferro){
                i.dinheiro += (quantidade * 1);
                i.ferro -= quantidade;
                cout << "Vendeu " << quantidade << " unidades de ferro por " << quantidade*2 << " euros!" << endl << endl;
            }
        }

        else if(tipo == "aco"){
            if(quantidade > i.barrasAco){
                cout << endl << "Nao possui barras de aco suficientes!" << endl;
            }
            else if(quantidade == i.barrasAco){
                i.dinheiro += (quantidade * 2);
                i.barrasAco = 0;
                cout << "Vendeu " << quantidade << " barras de aco por " << quantidade*2 << " euros!" << endl << endl;
            }
            else if(quantidade < i.barrasAco){
                i.dinheiro += (quantidade *2);
                i.barrasAco -= quantidade;
                cout << "Vendeu " << quantidade << " barras de aco por " << quantidade*2 << " euros!" << endl << endl;
            }
        }

        else if(tipo == "carvao"){
            if(quantidade > i.carvao){
                cout << endl << "Nao possui carvao suficiente!" << endl;
            }
            else if(quantidade == i.carvao){
                i.dinheiro += (quantidade * 1);
                i.carvao = 0;
                cout << "Vendeu " << quantidade << " unidades de carvao por " << quantidade*2 << " euros!" << endl << endl;
            }
            else if(quantidade < i.carvao){
                i.dinheiro += (quantidade * 1);
                i.carvao -= quantidade;
                cout << "Vendeu " << quantidade << " unidades de carvao por " << quantidade*2 << " euros!" << endl << endl;
            }
        }

        else if(tipo == "eletr"){
            if(quantidade > i.eletricidade){
                cout << endl << "Nao possui carvao suficiente!" << endl;
            }
            else if(quantidade == i.eletricidade){
                i.dinheiro += (quantidade * 1.5);
                i.eletricidade = 0;
                cout << "Vendeu " << quantidade << " KWh de eletricidade por " << quantidade*2 << " euros!" << endl << endl;
            }
            else if(quantidade < i.eletricidade){
                i.dinheiro += (quantidade * 1.5);
                i.eletricidade -= quantidade;
                cout << "Vendeu " << quantidade << " KWh de eletricidade por " << quantidade*2 << " euros!" << endl << endl;
            }
        }
    }

//  =====================================  COMANDO "CONT"  ======================================
    else if (comandoJogada == "cont"){
        string tipo;

        iss >> tipo;

        if(tipo == "miner"){
            if(i.dinheiro >= 10) {
                i.contratarTrabalhador(tipo);
                i.dinheiro -= 10;
            }
            else
                cout << endl << "Dinheiro insuficiente! Um mineiro custa 10 euros!" << endl;
        }
        else if(tipo == "oper"){
            if(i.dinheiro >= 15){
                i.contratarTrabalhador(tipo);
                i.dinheiro -= 15;
            }
            else
                cout << endl << "Dinheiro insuficiente! Um operario custa 15 euros!" << endl;
        }
        else if(tipo == "len"){
            if(i.dinheiro >= 20){
                i.contratarTrabalhador(tipo);
                i.dinheiro -=20;
            }
            else
                cout << endl << "Dinheiro insuficiente! Um lenhador custa 20 euros!" << endl;
        }
        else
            cout << "Comando usando incorretamente!" << endl << "Use cont <tipo>" << endl;
    }

//  =====================================  COMANDO "LIST"  ======================================
    else if (comandoJogada == "list"){

        cout << endl << "----------------------" << endl;
        cout << "Dia: " << i.dia << endl;
        cout << "Dinheiro: " << i.dinheiro << " euros" << endl;
        cout << "----------------------" << endl;
        cout << "Vigas de Madeira: " << i.vigasMadeira << endl;
        cout << "Madeira: " << i.madeira << endl;
        cout << "Ferro: " << i.ferro << endl;
        cout << "Barras de Aco: " << i.barrasAco << endl;
        cout << "Carvao: " << i.carvao << endl;
        cout << "Eletricidade: " << i.eletricidade << endl;
        cout << "----------------------" << endl;
        cout << "Mineiros: " << i.contadorMineiros << endl;
        cout << "Operarios: " << i.contadorOperarios << endl;
        cout << "Lenhadores: " << i.contadorLenhadores << endl;
        cout << "----------------------" << endl << endl;
        i.mostrarIlha();
    }


// COMANDO PARA VENDER EDIFICIOS
//  =====================================  COMANDO "VENDEE"  ======================================
    else if (comandoJogada == "vendee") {
        int linha, coluna;
        iss >> lin;
        iss >> col;

        if (lin < linhas + 1) {
            if (col < colunas + 1) {
                i.vendeEdificio(lin, col);
            }
            else
                cout << "Numero de colunas invalido!" << endl;
        }
        else
            cout << "Numero de linhas invalido!" << endl;
    }

//  =====================================  COMANDO "CONFIG"  ======================================
    else if (comandoJogada == "config"){
        string nome_ficheiro;
        char ch;

        iss >> nome_ficheiro;
        ifstream ficheiro;
        ficheiro.open(nome_ficheiro);

        if (ficheiro.is_open()) {
            while(ficheiro>>noskipws>>ch)
                cout<<ch;
        }
        ficheiro.close();
    }

//  =====================================  COMANDO "DEBCASH"  ======================================
    else if(comandoJogada == "debcash"){
        int valor;
        char opcao;
        iss >> valor;

        cout << "Pretende adicionar ou remover o valor introduzido?" << endl;
        cout << "Adicionar (digite A) ; Remover (digite R): ";
        cin >> opcao;
        cout << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if(opcao == 'A' || opcao == 'a'){
            i.dinheiro += valor;
            cout << "Dinheiro adicionado: " << valor << " euros!" << endl << endl;
        }
        if(opcao == 'R' || opcao == 'r'){
            i.dinheiro -= valor;
            cout << "Dinheiro retirado: " << valor << " euros!" << endl << endl;
        }

    }

//  =====================================  COMANDO "DEBED"  ======================================
    else if(comandoJogada == "debed"){
        int lin,col;
        string tipo;

        iss >> tipo; iss >> lin ; iss >> col;

        if (lin > 0 && lin < linhas + 1) {
            if (col > 0 && col < colunas + 1) {
                i.configEdificio(tipo, lin, col);
            } else {
                cout << endl << "Numero de colunas invalido!" << endl;
            }
        } else {
            cout << endl << "Numero de linhas invalido!" << endl;
        }
    }

//  =====================================  COMANDO "DEBKILL"  ===================================
    else if(comandoJogada == "debkill"){
        string id;
        iss >> id;

        i.debkillTrabalhador(id);
    }

//  =====================================  COMANDO "NEXT"  ======================================
    else if(comandoJogada == "next"){
        anoitecer(i);
        sleep(3);
        cout << endl << "----------------------" << endl;
        cout << "Fim do dia: " << i.dia << endl;
        cout << "Dinheiro: " << i.dinheiro << " euros" << endl;
        cout << "----------------------" << endl;
        cout << "Vigas de Madeira: " << i.vigasMadeira << endl;
        cout << "Madeira: " << i.madeira << endl;
        cout << "Ferro: " << i.ferro << endl;
        cout << "Barras de Aco: " << i.barrasAco << endl;
        cout << "Carvao: " << i.carvao << endl;
        cout << "Eletricidade: " << i.eletricidade << endl;
        cout << "----------------------" << endl;
        cout << "Mineiros: " << i.contadorMineiros << endl;
        cout << "Operarios: " << i.contadorOperarios << endl;
        cout << "Lenhadores: " << i.contadorLenhadores << endl;
        cout << "----------------------" << endl;
        i.mostrarIlha();
        sleep(5);
        ++i.dia;
        i.incrementarDiasTrabalhador();
        i.despedirDiasContrato();
        i.incrementarDiasEdificios();
        i.desabarEdificio();
        amanhecer(i);
        sleep(3);
        meioDia();
    }

//  ===================================  VERIFICA FIM DE JOGO  ===================================
    if(i.verificaFimJogo() == true){
        cout << "FIM DE JOGO!" << endl << "PERDEU TODOS OS RECURSOS!" << endl;
        sleep(3);
        return 0;
    }
    return 1;
}