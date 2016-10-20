#include "Cliente.h"
#include "Aleatorio.h"
#include <time.h>

Cliente::Cliente() {
    rd = new Aleatorio();

    tempo_entrada_ = 0;

    tipo_de_fila_ = rd->tipoDeFila();
    // tipo de fila : variavel int 0 ou 1, um pra cada tipo de fila.

    int x = rd->tipoDePagamento();
    if (x <2) {
        tipo_pagamento_ = 0;
    } else {
        tipo_pagamento_ = 1;
    }
    // tipo de pagamento : variavel int 0 a 9, dois numeros para 20% e outros oito para 80%.

    total_compras_ = rd->totalDeCompras();
    // total compras : variavel int 2 a 100, numero de compras

    total_preco_ = defineTotalValue();
}

Cliente::~Cliente() {

}

Cliente::Cliente(int tempo) {
    rd = new Aleatorio();

    tempo_entrada_ = tempo;

    tipo_de_fila_ = rd->tipoDeFila();
    // tipo de fila : variavel int 0 ou 1, um pra cada tipo de fila.

    tipo_pagamento_ = rd->tipoDePagamento();
    // tipo de pagamento : variavel int 0 a 9, dois numeros para 20% e outros 8 para 80%.

    total_compras_ = rd->totalDeCompras();
    // total compras : variavel int 2 a 100, numero de compras

    total_preco_ = defineTotalValue();
}

void Cliente::setTempoSaida(int tempo) {
    tempo_saida_ = tempo;
}
int Cliente::getTempoEntrada() {
    return tempo_entrada_;
}
int Cliente::getTempoSaida() {
    return tempo_saida_;
}
int Cliente::getTotalCompras() {
    return total_compras_;
}
int Cliente::getTotalPreco() {
    return total_preco_;
}
int Cliente::getTipoPagamento() {
    return tipo_pagamento_;
}
int Cliente::getTipoDeFila() {
    return tipo_de_fila_;
}

int Cliente::defineTotalValue() {
    int value = 0;
    for (int i = 0; i < total_compras_; i++) {
        value += rd->precoItem();
        // define o valor total das compras com base no numero de produtos e um preco aleatorio entre R$ 1 e R$ 90.
    }
    return value;
}
