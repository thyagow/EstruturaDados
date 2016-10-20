#include "Caixa.h"
#include "Cliente.h"
#include "linked_queue.h"


Caixa::Caixa(int id, int eficiencia, int salario) {
	id_ = id;
	eficiencia_ = eficiencia;
	salario_ = salario;
	clientes_atendidos_ = 0;
	faturamento_total_ = 0;
	tempo_total_ = 0;
	tempo_saida_ultimo_ = 0;
	quantidade_produtos_ = 0;
}
Caixa::~Caixa() {
    fila.clear();
}
int Caixa::getTamanho() {
	return fila.size();
}
void Caixa::inserirCliente(Cliente* c) {
	int t = 0;
	t += getTempoCliente(*c);
	if (fila.empty()) {
		t+= c->getTempoEntrada();
	} else {
		t+= tempo_saida_ultimo_;
	}
	tempo_saida_ultimo_ = t;
	c->setTempoSaida(t);
	quantidade_produtos_ += c->getTotalCompras();
	fila.queue(*c);
}
int Caixa::passarTempo(int tempo_atual) {
    Cliente c = fila.front();

    if (c.getTempoSaida() == tempo_atual) {
        fila.remove();
        clientes_atendidos_++;
        faturamento_total_ += c.getTotalPreco();
        tempo_total_ += getTempoCliente(c);
        quantidade_produtos_ -= c.getTotalCompras();
        return 1;
    } else {
        return 0;
    }
    return 0;
}
int Caixa::getLucro() {
	return faturamento_total_ - salario_;
}
long Caixa::getFaturamentoMedio() {
    if(clientes_atendidos_ == 0) {
        return 0;
    } else {
        return (int) faturamento_total_/clientes_atendidos_;
    }
}
int Caixa::getTempoMedioEspera() {
    if(clientes_atendidos_ == 0) {
        return 0;
    } else {
        return (int) tempo_total_/clientes_atendidos_;
    }
}
int Caixa::getId() {
	return id_;
}
int Caixa::getClientesAtendidos() {
	return clientes_atendidos_;
}
long Caixa::getFaturamentoTotal() {
	return faturamento_total_;
}
int Caixa::getTempoTotal() {
	return tempo_total_;
}
int Caixa::getSalario() {
	return salario_;
}
int Caixa::getEficiencia() {
	return eficiencia_;
}

int Caixa::getQuantidadeProdutos() {
	return quantidade_produtos_;
}

int Caixa::getTempoCliente(Cliente c) {
	int t = 0;
	if (eficiencia_ == 1) {
		t += c.getTotalCompras() * 1;
		t += 10 * c.getTipoPagamento();
	} else if(eficiencia_ == 2) {
		t += c.getTotalCompras() * 2;
		t += 25 * c.getTipoPagamento();
	} else {
		t += c.getTotalCompras() * 4;
		t += 60 * c.getTipoPagamento();
	}
	return t;
}
