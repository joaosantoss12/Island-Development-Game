#include "../headers/interface.h"

Interface::Interface(){
}

Interface::~Interface(){
}

// Comandos ao abrir o programa
void Interface::menucomandosInicio(){
    cout << endl << "|================| Menu de comandos iniciais |================|" << endl;
    cout << "->'jogar' Comeca um novo jogo" << endl;
    cout << "->'instrucoes' Ve as instrucoes do jogo" << endl;
    cout << "->'load <nome>' Carregar um jogo previamente guardado" << endl;
    cout << "->'apaga <nome>' Apagar um jogo previamente guardado" << endl;
    cout << "->'sair' Sair do jogo" << endl;
}

// Aba de instrucoes
void Interface::instrucoes(){
    string comandoIns;

    cout << endl << "|================| Instrucoes do jogo |================|" << endl;

    cout << endl << "|================| COMANDOS |================|" << endl;
    cout << "|================| INICIO |================|" << endl;
    cout << "->'jogar' Comeca um novo jogo" << endl <<
         "->'instrucoes' Ve as instrucoes do jogo" << endl <<
         "->'load <nome>' Carregar um jogo previamente guardado" << endl <<
         "->'apaga <nome>' Apagar um jogo previamente guardado" << endl <<
         "->'sair' Sair do jogo" << endl;

    cout << endl << "|================| JOGADAS |================|" << endl;
    cout << "->'exec <nomeFicheiro>' Executa um conjunto de comandos existentes em nomeFicheiro." << endl;
    cout << "->'cons <tipo> <linha> <coluna>' Constroi um edificio de um dado tipo na zona posicionada na linha e coluna." << endl << "Tipo = minaf | minac | central | bat | fund | edx" << endl;
    cout << "->'liga <linha> <coluna>' Liga o edificio (caso exista) que esta construido na zona posicionada na linha e coluna." << endl;
    cout << "->'des <linha> <coluna>' Desliga o edificio (caso exista) que esta construido na zona posicionada na linha e coluna." << endl;
    cout << "->'move <id> <linha> <coluna>' Move o trabalhador com o identificador id para a zona posicionada na linha e coluna." << endl;
    cout << "->'vende <tipo> <quanto>' Vende recursos de um dado tipo e de acordo com quanto se pretende vender" << endl << "Tipo = ferro | aco | carvao | mad | viga | eletr" << endl;
    cout << "->'cont <tipo>' Contrata um trabalhador de um dado tipo e este, tal como dito anteriormente, vai para a zona de pasto a espera de ordens do jogador." << " Tipo = oper | len | miner" << endl;
    cout << "->'list <linha> <coluna>' Obtem a informacao do jogo, globalmente se nao for indicada nenhuma linha.coluna, ou detalhada acerca de uma zona caso a sua posicao linha coluna seja indicada." << endl;
    cout << "->'vende <linha> <coluna>' Vende o edificio existente na zona indicada na linha e coluna especificadas." << endl;
    cout << "->'config <ficheiro>' Le o ficheiro de texto e extrai dele os precos de contratacao dos trabalhadores e de compra dos edificios." << endl;
    cout << "->'next' Termina a fase de recolha de comandos e desencadeia as ações necessárias ao seu processamento." << endl;
    cout << "->'debcash <valor>' Adiciona ou retira uma quantidade de dinheiro." << endl;
    cout << "->'debed <tipo> <linha> <coluna>' Adiciona um edificio a custo zero nessa posicao" << endl;
    cout << "->'debill <id>' Remove o trabalhado com o respetivo id." << endl;
    cout << "->'sair' Sair do jogo atual para o menu inicial" << endl;

    cout << endl << "Digite 'voltar' para voltar ao menu inicial!" << endl;

    while(comandoIns != "voltar") {
        cout << ":";
        getline(cin,comandoIns);
        if (comandoIns == "voltar") {
            comeca();
        }
    }
}

// Comandos disponiveis durante o jogo
void Interface::menucomandosJogo(){
cout << endl << "|================| Menu de comandos de jogada |================|" << endl;
    cout << "->'exec <nomeFicheiro>' Executa um conjunto de comandos existentes em nomeFicheiro." << endl;
    cout << "->'cons <tipo> <linha> <coluna>' Constroi um edificio de um dado tipo na zona posicionada na linha e coluna." << endl << "Tipo = minaf | minac | central | bat | fund | edx" << endl;
    cout << "->'liga <linha> <coluna>' Liga o edificio (caso exista) que esta construido na zona posicionada na linha e coluna." << endl;
    cout << "->'des <linha> <coluna>' Desliga o edificio (caso exista) que esta construido na zona posicionada na linha e coluna." << endl;
    cout << "->'upgrade' <linha> <coluna> Aumenta um nivel do edificio presente na zona posicionada na linha e coluna." << endl;
    cout << "->'move <id> <linha> <coluna>' Move o trabalhador com o identificador id para a zona posicionada na linha e coluna." << endl;
    cout << "->'vende <tipo> <quanto>' Vende recursos de um dado tipo e de acordo com quanto se pretende vender" << endl << "Tipo = ferro | aco | carvao | mad | viga | eletr" << endl;
    cout << "->'cont <tipo>' Contrata um trabalhador de um dado tipo e este, tal como dito anteriormente, vai para a zona de pasto a espera de ordens do jogador." << " Tipo = oper | len | miner" << endl;
    cout << "->'list <linha> <coluna>' Obtem a informacao do jogo, globalmente se nao for indicada nenhuma linha.coluna, ou detalhada acerca de uma zona caso a sua posicao linha coluna seja indicada." << endl;
    cout << "->'vendee <linha> <coluna>' Vende o edificio existente na zona indicada na linha e coluna especificadas." << endl;
    cout << "->'config <ficheiro>' Le o ficheiro de texto e extrai dele os precos de contratacao dos trabalhadores e de compra dos edificios." << endl;
    cout << "->'next' Termina a fase de recolha de comandos e desencadeia as acoes necessarias ao seu processamento." << endl;
    cout << "->'debcash <valor>' Adiciona ou retira uma quantidade de dinheiro." << endl;
    cout << "->'debed <tipo> <linha> <coluna>' Adiciona um edificio a custo zero nessa posicao" << endl;
    cout << "->'debill <id>' Remove o trabalhado com o respetivo id." << endl;
    cout << "->'save <nome>' Grava o estado do jogo em memoria, associando-lhe um nome." << endl;
    cout << "->'load <nome>' Recupera um dado estado do jogo em memoria, identificado ao nome indicado, e carrega-o." << endl;
    cout << "->'apaga <nome>' Apaga um determinado savegame de memoria." << endl;
    cout << "->'sair' Sair do jogo atual para o menu inicial." << endl;
}

// ====================================================================================================================
// ============================================= INICIO FUNCAO COMECA() ===============================================
// ====================================================================================================================
int Interface::comeca(){
    string comandoInicio,nome_ficheiro;
    istringstream iss(comandoInicio);

    menucomandosInicio();

    while(comandoInicio != "sair"){
        cout << endl << "Introduza um comando:";
        getline(cin,comandoInicio);

//  =====================================  COMANDO "JOGAR"  =====================================
        if(comandoInicio == "jogar") {
            int linhas,colunas;

            cout << endl << "Escolha o tamanho da ilha..." << endl;
            cout << "Linhas (min: 3 ; max: 8):";
            cin >> linhas;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            while(linhas < 3 || linhas > 8){
                if(linhas < 3 || linhas > 8){
                    cout << "Numero de linhas invalido. Digite novamente!\n";
                    cout << "Linhas (min: 3 ; max: 8):";
                    cin >> linhas;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            cout << "Colunas (min: 3 ; max: 16):";
            cin >> colunas;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            while(colunas < 3 || colunas > 16){
                if(colunas < 3 || colunas > 16){
                    cout << "Numero de colunas invalido. Digite novamente!\n";
                    cout << "Colunas (min: 3 ; max: 16):";
                    cin >> colunas;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            jogada(linhas,colunas);
            menucomandosInicio();
        }
//  =====================================  COMANDO "INSTRUCOES"  ================================
        if(comandoInicio == "instrucoes"){
            instrucoes();
            menucomandosInicio();
        }
    }
    exit(0);
}
// ====================================================================================================================
// =========================================== FIM FUNCAO COMECA() ====================================================
// ====================================================================================================================


// ====================================================================================================================
// ========================================== INICIO FUNCAO JOGADA() ==================================================
// ====================================================================================================================
int Interface::jogada(int linhas, int colunas) {

    ilha i(linhas,colunas); // Criar ilha com linhas e colunas digitadas pelo utilizador
    engine engine;

    menucomandosJogo(); // Menu que mostra os comandos disponiveis durante um jogo
    cout << endl;

    i.configIlha();
    i.mostrarIlha();

    string comandoJogada, nome_ficheiro, tipo;
    int lin,col;

    engine.amanhecer(i);
    sleep(3);
    engine.meioDia();

    do {
        cout << "Introduza um comando:";
        getline(cin, comandoJogada);

        istringstream iss(comandoJogada);
        iss >> comandoJogada;

//  =====================================  COMANDO "EXEC"  ======================================
        if (comandoJogada == "exec") {

            if(iss >> nome_ficheiro ) {
                engine.processaFicheiro(nome_ficheiro, i, lin, col);
            }
            else
                cout << endl << "Comando incorreto! Use <exec> <nome ficheiro>";
        }

//  =====================================  COMANDO "CONS"  ======================================
        else if (comandoJogada == "cons") {
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
                                        cout << "Construiu uma mina de ferro com sucesso por 20 vigas de madeira!" << endl << "Linha: " << lin << endl << "Coluna: " << col << endl << endl;
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

//  =====================================  COMANDO "MOVE"   ======================================
        else if (comandoJogada == "move") {
            int linha, coluna;
            string id;

            iss >> id;
            iss >> linha;
            iss >> coluna;

            if (linha < linhas+1 && coluna < colunas+1) {
                i.moverTrabalhador(id,linha,coluna-1);
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
            cout << "Total Mineiros contratados: " << i.contadorMineiros << endl;
            cout << "Total Operarios contratados: " << i.contadorOperarios << endl;
            cout << "Total Lenhadores contratados: " << i.contadorLenhadores << endl;
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
            engine.anoitecer(i);
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
            cout << "Total Mineiros contratados: " << i.contadorMineiros << endl;
            cout << "Total Operarios contratados: " << i.contadorOperarios << endl;
            cout << "Total Lenhadores contratados: " << i.contadorLenhadores << endl;
            cout << "----------------------" << endl;
            i.mostrarIlha();
            sleep(5);
            ++i.dia;
            engine.amanhecer(i);
            i.incrementarDiasTrabalhador();
            i.despedirDiasContrato();
            i.incrementarDiasEdificios();
            i.desabarEdificio();
            sleep(3);
            engine.meioDia();
        }

//  =====================================  COMANDO "SAVE"  =======================================
        else if(comandoJogada == "save"){

        }

//  =====================================  COMANDO "LOAD"  =======================================
        else if(comandoJogada == "load"){

        }

//  =====================================  COMANDO "APAGA"  ======================================
        else if(comandoJogada == "apaga"){

        }

//  ===================================  VERIFICA FIM DE JOGO  ===================================
        if(i.verificaFimJogo() == true){
            cout << "FIM DE JOGO!" << endl << "PERDEU TODOS OS RECURSOS!" << endl;
            sleep(3);
            return 0;
        }

    } while (comandoJogada != "sair");

    return 1;
}
// ==================================================================================================================
// ========================================== FIM FUNCAO JOGADA() ===================================================
// ==================================================================================================================