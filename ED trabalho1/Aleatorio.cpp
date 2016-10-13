#include "aleatorio.h"
#include <cstdlib>
#include <time.h>

Aleatorio::Aleatorio()
{
}

Aleatorio::~Aleatorio()
{
    //dtor
}
Aleatorio::tipoDeFila() {
    return (int) (rand()/2) % 2;
}

Aleatorio::tipoDePagamento() {
    return (int) (rand()/2) % 10;
}

Aleatorio::totalDeCompras() {
    return 2 + ((int) (rand()/2) % 90);
}

Aleatorio::precoItem() {
    return 2 + ((int) (rand()/2) % 98);
}

Aleatorio::eficNovoCaixa() {
    return 1 + ((int) (rand()/2) % 3);
}
