#include "../headers/Zona.h"

using namespace std;

string Zona::getTipo(){
    return tipo;
};

void Zona::setNivelEdificio(){
    edificio.nivel += 1;
};

int Zona::getNivelEdificio(){
    return edificio.nivel;
}

int Zona::getArmazenamentoEdificio(){
    return edificio.getArmazenamento();
}

void Zona::addArmazenamentoEdificio(int valor){
    edificio.addArmazenamento(valor);
}

string Zona::getEdificio(){
    return edificio.getTipo();
};

void Zona::setTipoEdificio(string nome) {
    edificio.tipo = nome;
};

void Zona::setPower(int a){
    edificio.ligar = a;
}

int Zona::getPower(){
    return edificio.ligar;
}

void Zona::getTrabalhador(){
    int contador=0;
    if(pointerTrabalhador.size() == 0){
        cout << "    ";
    }
    else{
        for(auto i = pointerTrabalhador.begin(); i != pointerTrabalhador.end(); ++i){
            cout << i->getTipo();
            contador++;
            if(contador == 1){
                cout << "   ";
            }
            else if(contador == 2){
                cout << "  ";
            }
            else if(contador == 3){
                cout << " ";
            }
            else if(contador > 4){
                break;
            }
        }
    }
};

string Zona::getTrabalhadorTipo(){
    string nome;
    for(auto i = pointerTrabalhador.begin(); i != pointerTrabalhador.end(); ++i){
        nome = i->getTipo();
    }
    return nome;
}

string Zona::getTrabalhadorID(int nPosicao){
    string id;
    int contador = 0;
    for(auto i = pointerTrabalhador.begin(); i != pointerTrabalhador.end(); ++i){
        if(contador == nPosicao){
            id = i->getID();
        }
        contador++;
    }
    return id;
}

bool Zona::trabalhadorMineiro() {
    for(auto i = pointerTrabalhador.begin(); i != pointerTrabalhador.end(); ++i){
        if(i->getTipo() == "M"){
            return true;
        }
    }
    return false;
};

bool Zona::trabalhadorOperario(){
    for(auto i = pointerTrabalhador.begin(); i != pointerTrabalhador.end(); ++i){
        if(i->getTipo() == "O"){
            return true;
        }
    }
    return false;
};

bool Zona::trabalhadorLenhador(){
    for(auto i = pointerTrabalhador.begin(); i != pointerTrabalhador.end(); ++i){
        if(i->getTipo() == "L"){
            return true;
        }
    }
    return false;
};

void Zona::construirEdificio(string tipo){
    if(tipo == "minaf"){
        MinaFerro minaF;
        edificio = minaF;
    }
    else if(tipo == "minac"){
        MinaCarvao minaC;
        edificio = minaC;
    }
    else if(tipo == "central"){
        CentralEletrica centralE;
        edificio = centralE;
    }
    else if(tipo == "bat"){
        Bateria bat;
        edificio = bat;
    }
    else if(tipo == "fund"){
        Fundicao fun;
        edificio = fun;
    }
    else if(tipo == "edx"){
        EdificioX edX;
        edificio = edX;
    }
};

void Zona::aumentarDiasEdificios(){
    edificio.aumentarDiasConstrucao();
}

void Zona::desabamentoEdificio(int flag_pantano){
    int probabilidade = 0;

    if(edificio.getTipo() == "mnF"){
        if(flag_pantano == 1 && edificio.getDiasConstrucao() == 10){
            probabilidade = 100;
        }
        else {
            probabilidade = 15;
        }
    }
    else if(edificio.getTipo() == "mnC"){
        if(flag_pantano == 1 && edificio.getDiasConstrucao() == 10){
            probabilidade = 100;
        }
        else {
            probabilidade = 10;
        }
    }
    else if(edificio.getTipo() == "edX"){
        if(flag_pantano == 1 && edificio.getDiasConstrucao() == 10){
            probabilidade = 100;
        }
        else {
            probabilidade = 5;
        }
    }
    else if(edificio.getTipo() == "elec"){
        if(flag_pantano == 1 && edificio.getDiasConstrucao() == 10){
            probabilidade = 100;
        }
    }
    else if(edificio.getTipo() == "bat"){
        if(flag_pantano == 1 && edificio.getDiasConstrucao() == 10){
            probabilidade = 100;
        }
    }
    else if(edificio.getTipo() == "fun"){
        if(flag_pantano == 1 && edificio.getDiasConstrucao() == 10){
            probabilidade = 100;
        }
    }

    if (probabilidades(probabilidade) == true) {
        edificio.setTipo("");
    }
}

void Zona::configTrabalhador(string tipo, Trabalhador trab){
    trab.setTipo(tipo);
    pointerTrabalhador.push_back(trab);
};

int Zona::getNumTrabalhadores() {
    return pointerTrabalhador.size();
};

void Zona::incrementarDiasContrato(){
    for(auto i = pointerTrabalhador.begin(); i != pointerTrabalhador.end(); ++i){
        i->aumentarDiasContrato();
    }
};

void Zona::despedirTrabalhadorDia(string zona){

    int contador = 0;

    for(auto i = pointerTrabalhador.begin(); i != pointerTrabalhador.end(); ++i) {
        while (contador <= pointerTrabalhador.size()) {
            if (i->getTipo() == "M") {
                if (i->getDiasContrato() >= 3) {
                    if(zona == "pas"){
                        i->probabilidade = 0;
                    }
                    else if(zona == "mnt"){
                        i->probabilidade = 15;
                    }
                    else if(zona == "pnt"){
                        i->probabilidade = 100;
                    }
                    else if(zona == "outra"){
                        i->probabilidade = 10;
                    }
                }
                if (probabilidades(i->probabilidade) == true) {
                    removerTrabalhador(contador);
                    cout << endl << "Um ou mais mineiros despediram-se!" << endl;
                    sleep(2);
                }
            }

            else if (i->getTipo() == "O") {
                if (i->getDiasContrato() >= 11) {
                    if(zona == "pas"){
                        i->probabilidade = 0;
                    }
                    else if(zona == "mnt"){
                        i->probabilidade = 10;
                    }
                    else if(zona == "pnt"){
                        i->probabilidade = 100;
                    }
                    else if(zona == "outra"){
                        i->probabilidade = 5;
                    }
                }
                if (probabilidades(i->probabilidade) == true) {
                    removerTrabalhador(contador);
                    cout << endl << "Um ou mais operarios despediram-se!" << endl;
                    sleep(2);
                }
            }

            else if(i->getTipo() == "L"){
                if(zona == "pas"){
                    i->probabilidade = 0;
                }
                else if(zona == "mnt"){
                    i->probabilidade = 5;
                }
                else if(zona == "pnt"){
                    i->probabilidade = 100;
                }
                else if(zona == "outra"){
                    i->probabilidade = 0;
                }
                if (probabilidades(i->probabilidade) == true) {
                    removerTrabalhador(contador);
                    cout << endl << "Um ou mais lenhadores despediram-se" << endl;
                    sleep(2);
                }
            }
            ++contador;
        }
    }
};

void Zona::removerTrabalhador(int posicao){
    pointerTrabalhador.erase(pointerTrabalhador.begin() + posicao);
}

int Zona::produzMontanha(){
    int contador=0;
    for(auto i=pointerTrabalhador.begin(); i != pointerTrabalhador.end(); ++i){
        if(i->getTipo() != ""){
            contador++;
        }
    }
    return contador;
}

int Zona::produzFloresta(){
    int contador=0;
    for(auto i=pointerTrabalhador.begin(); i != pointerTrabalhador.end(); ++i){
        if(i->getTipo() == "L"){
            contador++;
        }
    }
    return contador;
}

void Zona::zZNZ(){
    edificio.setTipo("");
    cout << endl << "| AVISO |" << endl;
    cout << "Um edificio foi destriudo pelo tsunami na zona znZ!" << endl;
    sleep(2);
};