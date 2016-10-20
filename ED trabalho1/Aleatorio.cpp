#include "Aleatorio.h"
#include <cstdlib>
#include <time.h>

Aleatorio::Aleatorio()
{
}

Aleatorio::~Aleatorio()
{
    //dtor
}
int Aleatorio::tipoDeFila() {
    return (int) (rand()/2) % 2;
}

int Aleatorio::tipoDePagamento() {
    return (int) (rand()/2) % 10;
}

int Aleatorio::totalDeCompras() {
    return 2 + ((int) (rand()/2) % 90);
}

int Aleatorio::precoItem() {
    return 2 + ((int) (rand()/2) % 98);
}

int Aleatorio::eficNovoCaixa() {
    return 1 + ((int) (rand()/2) % 3);
}
