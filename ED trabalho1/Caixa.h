#ifndef CAIXA_H
#define CAIXA_H 

#include <queue>
#include "Cliente.h"

#define MAX_FILA = 10;

class Caixa {
 public:
	Caixa(int id, int eficiencia, int salario);
 	~Caixa();
 	int getTamanho();
 	void inserirCliente(Cliente* c);
 	int passarTempo(int tempo);
 	int getLucro();
 	long getFaturamentoMedio();
 	int getTempoMedioEspera();
 	int getId();
 	int getClientesAtendidos();
 	long getFaturamentoTotal();
 	int getTempoTotal();
 	int getSalario();
 	int getEficiencia();
 	int getQuantidadeProdutos();

 private:
 	int id_;
	int getTempoCliente(Cliente c);
 	std::queue<Cliente> fila;
 	int eficiencia_;
 	int salario_;
 	int clientes_atendidos_;
 	int faturamento_total_;
 	int tempo_total_;
 	int tempo_saida_ultimo_;
 	int quantidade_produtos_;

};


#endif