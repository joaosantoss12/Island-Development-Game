#include <iostream>
#include "../headers/ilha.h"

using namespace std;

void ilha::configIlha() {
    srand(time(NULL));

    string tiposZona[6] = {"mnt", "dsr", "pas", "flr", "pnt", "znZ"};
    int contador=0,a,b;
    string configZonaIlha[nlinhas][ncolunas]; // Matriz de strings auxiliar para criar as zonas da ilha

    for(int i=0;i< nlinhas;i++){
        for(int j=0; j<ncolunas;j++){
            configZonaIlha[i][j] = " "; // Resetar todos os espaços da ilha
        }
    }

    for (int i=0;i<nlinhas; i++) {
        for (int j = 0; j < ncolunas; j++) {
            while (true) {                  // Garante que todas as zonas ficam com um tipo de zona
                a = random(nlinhas);
                b = random(ncolunas);

                if (configZonaIlha[a][b] == " ") {
                    configZonaIlha[a][b] = tiposZona[contador]; // Garante que todas as zonas aparecem pelo menos 1 vez
                    break;
                }
            }
            contador++;
            if (contador > 5) {
                contador = 0;
            }
        }
    }

    for(int c=0;c<nlinhas;c++){
        for(int d=0;d<ncolunas;d++){
            Zona novaZ(configZonaIlha[c][d], c, d); // Criar uma nova addZona com informação vinda de trás (configZonaIlha)
            pointerZonas.push_back(novaZ); // Colocar no fim do pointeiro das zonas, o novo tipo de Zona
        }
    }
};

void ilha::mostrarIlha(){
    int contadorZona = 1;
    int contadorEdificio = 1;
    int contadorTrabalhador = 1;
    int contadorNTrabalhador = 1;

    cout << "|";
    for(int i=0;i<ncolunas;i++){
        cout << "----|";
    }
    cout << endl;
    for(int i=0;i<nlinhas;i++){
        cout << "|";
        for(int j=0;j<ncolunas;j++){
            rZona(contadorZona);     // Envia o contador (1,2,3,etc) para rZona para receber a zona nessa posição (do contador)
            cout << "|";
            contadorZona++;
        }
        cout << endl << "|";

        for(int j=0;j<ncolunas;j++){
            rEdificio(contadorEdificio);
            cout << "|";
            contadorEdificio++;
        }
        cout << endl << "|";

        for(int j=0;j<ncolunas;j++){
            rTrabalhadores(contadorTrabalhador);
            cout << "|";
            contadorTrabalhador++;
        }
        cout << endl << "|";

        for(int j=0;j<ncolunas;j++){
            cout << getNumeroTrabalhadores(contadorNTrabalhador) << "   ";
            cout << "|";
            contadorNTrabalhador++;
        }

        cout << endl;
        cout << "|";
        for(int i=0;i<ncolunas;i++){
            cout << "----|";
        }
        cout << endl;
    }
    cout << endl;
};

void ilha::rZona(int a) {
    int contador = 0;
    for (auto i = pointerZonas.begin(); i != pointerZonas.end(); ++i) {
        contador++;
        if (contador == a) {
            cout << i->getTipo() << " ";
        }
    }
};

void ilha::rEdificio(int a){
    int contador=0;
    for(auto i = pointerZonas.begin(); i != pointerZonas.end();++i){
        contador++;
        if(contador == a){
            if(i->getEdificio() == ""){
                cout << "    ";
            }
            else if(i->getEdificio() == "elec"){
                cout << i->getEdificio();
            }
            else {
                cout << i->getEdificio() << " ";
            }
        }
    }
};

void ilha::rTrabalhadores(int a){
    int contador=0;
    for(auto i = pointerZonas.begin(); i != pointerZonas.end();++i){
        contador++;
        if(contador == a){
            i->getTrabalhador();
        }
    }
};


// ================================ EDIFICIOS ================================================

int ilha::configEdificio(string tEdificio, int li, int co) {
    sucessoEdificio = 0;
    int nPosicao;
    int contador = 0;

    nPosicao = ((li-1)*ncolunas) + co;

    for (auto i = pointerZonas.begin(); i != pointerZonas.end(); ++i){
        contador++;
        if(contador == nPosicao){
            if(i->getEdificio() == ""){
                    i->construirEdificio(tEdificio);
                    sucessoEdificio = 1;
                    break;
            }
            else {
                cout << "Esta zona ja tem um edificio construido!" << endl << "Escolha outra posicao!" << endl << endl;
                break;
            }
        }
    }
    return 0;
};

void ilha::incrementarDiasEdificios(){
    for (auto i = pointerZonas.begin(); i != pointerZonas.end(); ++i) {
        if(i->getEdificio() != ""){
            i->aumentarDiasEdificios();
        }
    }
}

void ilha::ligarEdificio(int lin, int col){
    int nPosicao, contador=0;
    nPosicao = ((lin-1)*ncolunas) + col;

    for (auto i = pointerZonas.begin(); i != pointerZonas.end(); ++i) {
        contador++;
        if(contador == nPosicao){
            if(i->getEdificio()==""){
                cout << endl << "Nao existe nenhum edificio nesta zona!" << endl;
                break;
            }
            else {
                i->setPower(1);
            }
        }
    }
};

void ilha::desligarEdificio(int lin, int col){
    int nPosicao, contador=0;
    nPosicao = ((lin-1)*ncolunas) + col;

    for (auto i = pointerZonas.begin(); i != pointerZonas.end(); ++i) {
        contador++;
        if(contador == nPosicao){
            if(i->getEdificio()==""){
                cout << endl << "Nao existe nenhum edificio nesta zona!" << endl;
                break;
            }
            else{
                i->setPower(0);
            }
        }
    }
};

void ilha::upgradeEdificio(int lin, int col){
    int nPosicao, contador=0;
    nPosicao = ((lin-1)*ncolunas) + col;

    for (auto i = pointerZonas.begin(); i != pointerZonas.end(); ++i){
        contador++;
        if(contador == nPosicao){
            if(i->getEdificio() == ""){
                cout << "Nao existe nenhum edificio construido nesta posicao!" << endl;
            }
            else if(i->getEdificio() == "mnF"){
                if(dinheiro >= 15 && vigasMadeira >= 1) {
                    if(i->getNivelEdificio() < 5) {
                        i->setNivelEdificio();
                        dinheiro -= 15;
                        vigasMadeira -= 1;
                    }
                }
                else
                    cout << "Recursos insuficientes! Para dar upgrade numa mina de ferro precisa de 15 euros e 1 viga de madeira!" << endl << endl;
            }

            else if(i->getEdificio() == "mnC"){
                if(dinheiro >= 15 && vigasMadeira >= 1) {
                    if(i->getNivelEdificio() < 5) {
                        i->setNivelEdificio();
                        dinheiro -= 10;
                        vigasMadeira -= 1;
                    }
                }
                else
                    cout << "Recursos insuficientes! Para dar upgrade numa mina de carvao precisa de 10 euros e 1 viga de madeira!" << endl << endl;
            }

            else if(i->getEdificio() == "elec"){
                cout << "Impossivel melhorar um edificio do tipo \"central eletrica\"!" << endl << endl;
            }

            else if(i->getEdificio() == "bat"){
                if(dinheiro >= 5){
                    if(i->getNivelEdificio() < 5){
                        i->setNivelEdificio();
                        dinheiro -= 5;
                    }
                }
                else
                    cout << "Dinheiro insuficiente! Para dar upgrade numa bateria precisa de 5 euros!" << endl << endl;
            }

            else if(i->getEdificio() == "fun"){
                cout << "Impossivel melhorar um edificio do tipo \"fundicao\"!" << endl << endl;
            }

            else if(i->getEdificio() == "edX"){
                if(dinheiro >= 10){
                    if(i->getNivelEdificio() < 5){
                        i->setNivelEdificio();
                        dinheiro -= 10;
                    }
                }
                else
                    cout << "Dinheiro insuficiente! Para dar upgrade num edificio-X de 10 euros!" << endl << endl;
            }
        }
    }
};

void ilha::vendeEdificio(int linha, int coluna){
    int nPosicao = ((linha-1)*ncolunas) + coluna;
    int contador=0;

    for(auto i=pointerZonas.begin(); i!=pointerZonas.end(); ++i){
        contador++;
        if(contador == nPosicao){
            if(i->getTipo() == "mnt") {             // CUSTO DO EDIFICIO (X2)
                if (i->getEdificio() == "mnF") {
                    dinheiro += 2 * i->getArmazenamentoEdificio();
                    dinheiro += 200;
                    i->setTipoEdificio("");
                    cout << "Vendeu uma mina de ferro por 200 euros!" << endl;
                }
                else if(i->getEdificio() == "mnC"){
                    dinheiro += 2 * i->getArmazenamentoEdificio();
                    dinheiro += 200;
                    i->setTipoEdificio("");
                    cout << "Vendeu uma mina de carvao por 200 euros!" << endl;
                }
                else if(i->getEdificio() == "elec"){
                    dinheiro += 2 * i->getArmazenamentoEdificio();
                    dinheiro += 30;
                    i->setTipoEdificio("");
                    cout << "Vendeu uma central eletrica por 30 euros!" << endl;
                }
                else if(i->getEdificio() == "bat"){
                    dinheiro += 1.5 * i->getArmazenamentoEdificio();
                    dinheiro += 20;
                    vigasMadeira += 20;
                    i->setTipoEdificio("");
                    cout << "Vendeu uma bateria por 20 vigas e 20 euros!" << endl;
                }
                else if(i->getEdificio() == "fun"){
                    dinheiro += 20;
                    i->setTipoEdificio("");
                    cout << "Vendeu uma fundicao por 20 euros!" << endl;
                }
                else if(i->getEdificio() == "edX"){
                    dinheiro += 20;
                    i->setTipoEdificio("");
                    cout << "Vendeu um edificio-X por 20 euros!" << endl;
                }
                else
                    cout << "Nao existe nenhum edificio nesta zona!" << endl;
            }
            else                                    // NÃO É UMA ZONA MONTANHA
                if (i->getEdificio() == "mnF") {
                    dinheiro += 2 * i->getArmazenamentoEdificio();
                    dinheiro += 100;
                    i->setTipoEdificio("");
                    cout << "Vendeu uma mina de ferro por 100 euros!" << endl;
                }
                else if(i->getEdificio() == "mnC"){
                    dinheiro += 2 * i->getArmazenamentoEdificio();
                    dinheiro += 100;
                    i->setTipoEdificio("");
                    cout << "Vendeu uma mina de carvao por 100 euros!" << endl;
                }
                else if(i->getEdificio() == "elec"){
                    dinheiro += 2 * i->getArmazenamentoEdificio();
                    dinheiro += 15;
                    i->setTipoEdificio("");
                    cout << "Vendeu uma central por 15 euros!" << endl;
                }
                else if(i->getEdificio() == "bat"){
                    dinheiro += 1.5 * i->getArmazenamentoEdificio();
                    dinheiro += 10;
                    vigasMadeira += 10;
                    i->setTipoEdificio("");
                    cout << "Vendeu uma bateria por 10 vigas e 10 euros!" << endl;
                }
                else if(i->getEdificio() == "fun"){
                    dinheiro += 10;
                    i->setTipoEdificio("");
                    cout << "Vendeu uma fundicao por 10 euros!" << endl;
                }
                else if(i->getEdificio() == "edX"){
                    dinheiro += 10;
                    i->setTipoEdificio("");
                    cout << "Vendeu um edificio-X por 10 euros!" << endl;
                }
                else
                    cout << "Nao existe nenhum edificio nesta zona!" << endl;
        }
    }
};

void ilha::desabarEdificio(){
    for(auto i=pointerZonas.begin(); i!=pointerZonas.end(); ++i){
        if(i->getTipo() == "pnt"){
            i->desabamentoEdificio(1);
        }
        i->desabamentoEdificio(0);
    }
};

// ====================================== RECOLHA DE RECURSOS ======================================
void ilha::producaoMinaF(){
    for (auto i = pointerZonas.begin(); i != pointerZonas.end(); ++i) {
        if(i->getEdificio() == "mnF") {
            if(i->getTipo() == "dsr") {
                if (i->trabalhadorMineiro() == true && i->getPower() == 1) {
                    if (i->getArmazenamentoEdificio() < (90 + (10 * i->getNivelEdificio()))) {      // Armazenamento de ferro
                        addFerro((1 + i->getNivelEdificio()) * 0.5);
                        i->addArmazenamentoEdificio(1 + i->getNivelEdificio());
                    }
                }
            }
            else if(i->getTipo() == "mnt" || i->getTipo() == "znZ"){
                if (i->trabalhadorMineiro() == true && i->getPower() == 1) {
                    if (i->getArmazenamentoEdificio() < (90 + (10 * i->getNivelEdificio()))) {      // Armazenamento de ferro
                        addFerro((1 + i->getNivelEdificio()) * 2);
                        i->addArmazenamentoEdificio(1 + i->getNivelEdificio());
                    }
                }
            }
            else{
                if (i->trabalhadorMineiro() == true && i->getPower() == 1) {
                    if (i->getArmazenamentoEdificio() < (90 + (10 * i->getNivelEdificio()))) {      // Armazenamento de ferro
                        addFerro(1 + i->getNivelEdificio());
                        i->addArmazenamentoEdificio(1 + i->getNivelEdificio());
                    }
                }
            }
        }
    }
};

void ilha::addFerro(float quantidade){
    ferro += quantidade;
};

void ilha::producaoMinaC(){
    for (auto i = pointerZonas.begin(); i != pointerZonas.end(); ++i) {
        if(i->getEdificio() == "mnC") {
            if(i->getTipo() == "dsr") {
                if (i->trabalhadorMineiro() == true && i->getPower() == 1) {
                    if (i->getArmazenamentoEdificio() < (90 + (10 * i->getNivelEdificio()))) {      // Armazenamento de carvao
                        addCarvao(1 + i->getNivelEdificio());
                        i->addArmazenamentoEdificio(1 + i->getNivelEdificio());
                    }
                }
            }
            else if(i->getTipo() == "mnt" || i->getTipo() == "znZ"){
                if (i->trabalhadorMineiro() == true && i->getPower() == 1) {
                    if (i->getArmazenamentoEdificio() < (90 + (10 * i->getNivelEdificio()))) {      // Armazenamento de ferro
                        addFerro((1 + i->getNivelEdificio()) * 2);
                        i->addArmazenamentoEdificio(1 + i->getNivelEdificio());
                    }
                }
            }
            else{
                if (i->trabalhadorMineiro() == true && i->getPower() == 1) {
                    if (i->getArmazenamentoEdificio() < (90 + (10*i->getNivelEdificio()))) {            // Armazenamento de carvao
                        addCarvao(1 + i->getNivelEdificio());
                        i->addArmazenamentoEdificio(1 + i->getNivelEdificio());
                    }
                }
            }
        }

    }
};

void ilha::addCarvao(float quantidade){
    carvao += quantidade;
}


void ilha::producaoCentralE(){
    for (auto i = pointerZonas.begin(); i != pointerZonas.end(); ++i) {
        if(i->getEdificio() == "elec") {
            if(i->getTipo() == "znZ"){
                if (i->trabalhadorOperario() == true && i->getPower() == 1) {
                    if (madeira >= 1) {
                        if (i->getArmazenamentoEdificio() < 90 + (10 * i->getNivelEdificio())) {      // Armazenamento de carvao
                            addCarvao(2);
                            i->addArmazenamentoEdificio(1);
                        }
                        madeira -= 1;
                        addEletricidade(1);
                    }
                }
            }
            else{
                if (i->trabalhadorOperario() == true && i->getPower() == 1) {
                    if (madeira >= 1) {
                        if (i->getArmazenamentoEdificio() < 90 + (10 * i->getNivelEdificio())) {      // Armazenamento de carvao
                            addCarvao(1);
                            i->addArmazenamentoEdificio(1);
                        }
                        madeira -= 1;
                        addEletricidade(1);
                    }
                }
            }
        }
    }
}

void ilha::addEletricidade(int quantidade) {
    eletricidade += quantidade;
}

void ilha::armazentamentoBateria(){
    for (auto i = pointerZonas.begin(); i != pointerZonas.end(); ++i) {
        if(i->getEdificio() == "bat") {
            if(i->getPower() == 1) {
                if (i->getArmazenamentoEdificio() < 90 + (10 * i->getArmazenamentoEdificio())) {
                    i->addArmazenamentoEdificio(1);
                }
            }
        }
    }
}


void ilha::producaoFundicao(){
    for (auto i = pointerZonas.begin(); i != pointerZonas.end(); ++i) {
        if(i->getTipo() == "znZ"){
            if (i->getEdificio() == "fun") {
                if (i->trabalhadorOperario() == true && i->getPower() == 1) {
                    addAco(2);
                    ferro -= 1.5;
                    carvao -= 0.5;
                }
            }
        }
        else{
            if (i->getEdificio() == "fun") {
                if (i->trabalhadorOperario() == true && i->getPower() == 1) {
                    addAco(1);
                    ferro -= 1.5;
                    carvao -= 0.5;
                }
            }
        }
    }
}

void ilha::addAco(int quantidade){
    barrasAco += quantidade;
}

void ilha::producaoEdX(){
    for (auto i = pointerZonas.begin(); i != pointerZonas.end(); ++i) {
        if(i->getEdificio() == "edX") {
            if(i->trabalhadorLenhador() == true && i->getPower() == 1) {
                addVigas(0 + i->getNivelEdificio());
                madeira -= 2;
            }
        }
    }
}

void ilha::addVigas(int quantidade){
    vigasMadeira += quantidade;
}

void ilha::producaoMontanha() {
    for (auto i = pointerZonas.begin(); i != pointerZonas.end(); ++i) {
        if (i->getTipo() == "mnt") {
            if(i->produzMontanha() != 0) {
                ferro += 0.1f * i->produzMontanha();
            }
        }
    }
};

void ilha::producaoFloresta(){
    for(auto i = pointerZonas.begin(); i != pointerZonas.end();++i){
        if(i->getTipo() == "flr"){
            if(i->produzFloresta() != 0){
                madeira += 1*i->produzFloresta();
            }
        }
    }
};

void ilha::zonaZNZ(){
    int probTsunami = 65;
    for(auto i = pointerZonas.begin(); i != pointerZonas.end(); ++i){
        if(i->getTipo() == "znZ" && i->getEdificio() != ""){
            if(probabilidades(probTsunami) == true){
                i->zZNZ();
            }
        }
    }
}

bool ilha::verificaFimJogo(){
    if(dinheiro == 0 && vigasMadeira == 0 && madeira == 0 && ferro == 0 && barrasAco == 0 && carvao == 0 && eletricidade == 0){
        return true;
    }
    return false;
};


// ====================================== TRABALHADOR ============================================

void ilha::contratarTrabalhador(string tipo) {

    if (tipo == "miner") {
        Mineiro miner("",0);
        miner.setID(++nTrabalhadores, dia);
        srand(time(NULL));

        while (true) {      // Correr infinitamente até ao break
            int contador = 0;
            int rndZona = random(nlinhas * ncolunas);
            int flag_pasto = 0;

            for (auto i = pointerZonas.begin(); i != pointerZonas.end(); ++i) {
                contador++;
                if (i->getTipo() == "pas" && contador == rndZona) {
                    i->configTrabalhador("M", miner);
                    contadorMineiros++;
                    flag_pasto = 1;
                    break;
                }
            }
            if(flag_pasto == 1){
                break;
            }
        }
    }

    else if (tipo == "oper"){
        Operario oper("",0);
        oper.setID(++nTrabalhadores, dia);
        srand(time(NULL));

        while (true) {      // Correr infinitamente até ao break
            int contador = 0;
            int rndZona = random(nlinhas * ncolunas);
            int flag_pasto = 0;

            for (auto i = pointerZonas.begin(); i != pointerZonas.end(); ++i) {
                contador++;
                if (i->getTipo() == "pas" && contador == rndZona) {
                    i->configTrabalhador("O", oper);
                    contadorOperarios++;
                    flag_pasto = 1;
                    break;
                }
            }
            if(flag_pasto == 1){
                break;
            }
        }
    }

    else if(tipo == "len"){
        Lenhador len("",0);
        len.setID(++nTrabalhadores, dia);
        srand(time(NULL));

        while (true) {      // Correr infinitamente até ao break
            int contador = 0;
            int rndZona = random(nlinhas * ncolunas);
            int flag_pasto = 0;

            for (auto i = pointerZonas.begin(); i != pointerZonas.end(); ++i) {
                contador++;
                if (i->getTipo() == "pas" && contador == rndZona) {
                    i->configTrabalhador("L", len);
                    contadorLenhadores++;
                    flag_pasto = 1;
                    break;
                }
            }
            if(flag_pasto == 1){
                break;
            }
        }
    }
};

int ilha::getNumeroTrabalhadores(int a) {
    int contador=0;
    int nT;
    for (auto i = pointerZonas.begin(); i != pointerZonas.end(); ++i) {
        contador++;
        if(contador == a){
            nT = i->getNumTrabalhadores();
        }
    }
    return nT;
};

void ilha::moverTrabalhador(string id, int lin, int col) {
    int nPosicao;
    Trabalhador copy;
    string tipo;
    nPosicao = ((lin - 1) * ncolunas) + col;

    for (auto i = pointerZonas.begin(); i != pointerZonas.end(); ++i) {
        for (int a = 0; a < i->getNumTrabalhadores(); a++) {
            if (id == i->getTrabalhadorID(a)) {
                tipo = i->getTrabalhadorTipo();
                if(tipo == "M"){
                    Mineiro miner(id,0);
                    copy = miner;
                }
                i->removerTrabalhador(nPosicao);
                pointerZonas[nPosicao].configTrabalhador(tipo, copy);
            }
            else if(id == i->getTrabalhadorID(a)){
                tipo = i->getTrabalhadorTipo();
                if(tipo == "O"){
                    Operario oper(id,0);
                    copy = oper;
                }
                i->removerTrabalhador(nPosicao);
                pointerZonas[nPosicao].configTrabalhador(tipo, copy);
            }
            else if(id == i->getTrabalhadorID(a)) {
                tipo = i->getTrabalhadorTipo();
                if(tipo == "L"){
                    Lenhador len(id,0);
                    copy = len;
                }
                i->removerTrabalhador(nPosicao);
                pointerZonas[nPosicao].configTrabalhador(tipo, copy);
            }
        }
    }
};

void ilha::incrementarDiasTrabalhador(){
    for (auto i = pointerZonas.begin(); i != pointerZonas.end(); ++i) {
        i->incrementarDiasContrato();
    }
}

void ilha::despedirDiasContrato(){
    for (auto i = pointerZonas.begin(); i != pointerZonas.end(); ++i) {
        if(i->getTipo() == "pas") {
            i->despedirTrabalhadorDia("pas");
        }
        else if(i->getTipo() == "mnt") {
            i->despedirTrabalhadorDia("mnt");
        }
        else if(i->getTipo() == "pnt"){
            i->despedirTrabalhadorDia("pnt");
        }
        else
        {
            i->despedirTrabalhadorDia("outra");
        }
    }
};

void ilha::debkillTrabalhador(string id){
    for(auto i = pointerZonas.begin(); i != pointerZonas.end(); ++i){
        for(int a = 0; a < i->getNumTrabalhadores(); a++){
            if(id == i->getTrabalhadorID(a)){
                i->removerTrabalhador(a);
            }
            else
                cout << "Nao existe nenhum trabalhador com o ID: " << id << endl;
        }
    }
}
