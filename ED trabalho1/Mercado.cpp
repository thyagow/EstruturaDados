#include <deque>
#include "Caixa.h"
#include "Mercado.h"
#include "Cliente.h"
#include "Aleatorio.h"
#include <cstdlib>
#include <iostream>

Mercado::Mercado(int intervalo_cliente, int tam_max_fila, int tempo_exec_max, int salario_minimo) {
	intervalo_cliente_ = intervalo_cliente;
	tam_max_fila_ = tam_max_fila;
	tempo_exec_max_ = tempo_exec_max;
	tempo_ = 0;
	clientes_desistentes_ = 0;
	prejuizo_ = 0;
	salario_minimo_ = salario_minimo;
	al = new Aleatorio();

}
Mercado::~Mercado() {

}
Mercado::passarTempo() {
	if (tempo_ < tempo_exec_max_) {
		if(tempo_%intervalo_cliente_ == 0) {
			int c = clienteEntrou(tempo_);
			if (c == 0) {
				if (caixas.at(menorFila()).getTamanho() > tam_max_fila_) {
					insereNovoCaixa(1, al->eficNovoCaixa());
				}
			} else {
				prejuizo_+= c;
				clientes_desistentes_++;
			}
		}
		for(std::size_t i = 0; i < caixas.size(); i++) {
			caixas.at(i).passarTempo(tempo_);
		}
		tempo_++;
		return 0;
	} else {
		return 1;
	}
}
Mercado::getFaturamentoMedio() {
    long fat = 0;
    for (std::size_t i = 0; i < caixas.size(); i++) {
        fat += caixas.at(i).getFaturamentoTotal();
    }
    if (getClientesAtendidos() != 0) {
	    int r = fat / getClientesAtendidos();
	    return r;
	} else {
		return 0;
	}
}
long Mercado::getFaturamentoBruto() {
	long fat = 0;
	for(std::size_t i = 0; i < caixas.size(); i++) {
		fat += caixas.at(i).getFaturamentoTotal();
	}
	return fat;
}
long Mercado::getFaturamentoLiquido() {
	long fat = 0;
	for(std::size_t i = 0; i < caixas.size(); i++) {
		fat += caixas.at(i).getFaturamentoTotal();
		fat -= caixas.at(i).getSalario();
	}
	return fat;
}
Mercado::getClientesDesistentes() {
	return clientes_desistentes_;
}
Mercado::getPrejuizo() {
	return prejuizo_;
}

Mercado::getIntervaloCliente() {
	return intervalo_cliente_;
}
long Mercado::getCaixasInfo() {
	long sal = 0;
	for(std::size_t i = 0; i < caixas.size(); i++) {
		sal += caixas.at(i).getSalario();
		std::cout << "ID: " << caixas.at(i).getId()
		<< " -- Eficiencia: " << caixas.at(i).getEficiencia()
		<< " -- Tempo Medio de Espera: " << caixas.at(i).getTempoMedioEspera()
		<< " -- Faturamento Medio: " << caixas.at(i).getFaturamentoMedio()
		<< " -- Faturamento Total: " << caixas.at(i).getFaturamentoTotal()
		<< " -- Salario: " << caixas.at(i).getSalario()
		<< " -- Lucro: " << caixas.at(i).getLucro() <<"\n"<< std::endl;
	}
	return sal;
}
Mercado::getTempo() {
	return tempo_;
}
Mercado::getClientesAtendidos() {
	int cli = 0;
	for(std::size_t i = 0; i < caixas.size(); i++) {
		cli += caixas.at(i).getClientesAtendidos();
	}
	return cli;
}
Mercado::clienteEntrou(int tempo) {
	Cliente* cliente = new Cliente(tempo);
	int menor = menorFila();
	int menos_produtos = filaMenosProdutos();
	if (caixas.at(menos_produtos).getTamanho() > 10) {
		menos_produtos = menor;
	}
	if (caixas.at(menor).getTamanho() >= 10) {
		int prejuizo = cliente->getTotalPreco();
		delete(cliente);
		return prejuizo;
	} else {
		if (cliente->getTipoDeFila() == 0) {
			caixas.at(menor).inserirCliente(cliente);
		} else {
			caixas.at(menos_produtos).inserirCliente(cliente);
		}
		delete(cliente);
	}
	return 0;
}

Mercado::menorFila() {
	int menor = 0;
	for(std::size_t i = 0; i < caixas.size(); i++) {
		if (caixas.at(i).getTamanho() < caixas.at(menor).getTamanho()) {
			menor = i;
		}
	}
	return menor;
}

Mercado::filaMenosProdutos() {
	int menos_produtos = 0;
	for(std::size_t i = 0; i < caixas.size(); i++) {
		if (caixas.at(i).getQuantidadeProdutos() < caixas.at(menos_produtos).getQuantidadeProdutos()) {
			menos_produtos = i;
		}
	}
	return menos_produtos;
}
void Mercado::insereNovoCaixa(int extra, int efic) {
	int id = caixas.size()+1;
	int eficiencia = efic;
	Caixa *cx = new Caixa(id, eficiencia, salario_minimo_ + (extra * 2 *salario_minimo_));
	caixas.push_back(*cx);
}
