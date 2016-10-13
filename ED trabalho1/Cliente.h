#ifndef CLIENTE_H
#define CLIENTE_H

#include "Aleatorio.h"

class Cliente {
public:
	Cliente();
    Cliente(int tempo_entrada);
    ~Cliente();
    void setTempoSaida(int tempo);
    int getTempoEntrada();
    int getTempoSaida();
    int getTotalCompras();
    int getTotalPreco();
    int getTipoPagamento();
    int getTipoDeFila();

private:
    int defineTotalValue();
    int tempo_entrada_;
    int tempo_saida_;
    int tipo_de_fila_;
    int tipo_pagamento_;
    int total_compras_;
    int total_preco_;
    Aleatorio* rd;
};

#endif // CLIENTE_H_INCLUDED
