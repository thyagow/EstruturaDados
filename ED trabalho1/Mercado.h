#ifndef MERCADO_H
#define MERCADO_H

#include <deque>
#include "Caixa.h"
#include "Aleatorio.h"
#include "Cliente.h"


class Mercado {
 public:
 	Mercado(int intervalo_cliente, int tam_max_fila, int tempo_exec_max_, int salario_minimo_);
 	~Mercado();
 	int passarTempo(); // return 0 continua, return 1 acabou a execucao
 	int getFaturamentoMedio();
 	long getFaturamentoBruto();
 	long getFaturamentoLiquido();
 	int getClientesDesistentes();
 	int getPrejuizo();
 	long getCaixasInfo();
 	int getTempo();
 	int getClientesAtendidos();
 	int getIntervaloCliente();
 	void insereNovoCaixa(int extra); // extra = 0 caixa normal, extra = 1 hora extra
 	void insereNovoCaixa(int extra, int efic);


 private:
 	int menorFila();
 	int filaMenosProdutos();
 	int clienteEntrou(int tempo);
 	int intervalo_cliente_;
 	std::deque<Caixa> caixas;
 	int tam_max_fila_;
 	int tempo_;
 	int clientes_desistentes_;
 	int prejuizo_;
 	int tempo_exec_max_;
 	int salario_minimo_;
 	Aleatorio* al;
};


#endif
