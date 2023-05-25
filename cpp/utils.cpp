#include "../headers/utils.h"

int random(int max){            // random de 0 a max
    int randomNumber;
    randomNumber = rand() % max;
    return randomNumber;
};

int randomEntreDois(int min, int max){    // random entre min e max
    return rand()%(max-min + 1) + min;
};

bool probabilidades(float prob){
    bool TorF = ((rand() % 100) < prob);
    return TorF;
};