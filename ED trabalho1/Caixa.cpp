#include "Caixa.h"
#include "Cliente.h"



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

}
Caixa::getTamanho() {
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
	fila.push(*c);
}
Caixa::passarTempo(int tempo_atual) {
	Cliente c = fila.front();
	if (c.getTempoSaida() == tempo_atual) {
		fila.pop();
		clientes_atendidos_++;
		faturamento_total_ += c.getTotalPreco();
		tempo_total_ += getTempoCliente(c);
		quantidade_produtos_ -= c.getTotalCompras();
		return 1;
	} else {
		return 0;
	}
}
Caixa::getLucro() {
	return faturamento_total_ - salario_;
}
long Caixa::getFaturamentoMedio() {
    if(clientes_atendidos_ == 0) {
        return 0;
    } else {
        return (int) faturamento_total_/clientes_atendidos_;
    }
}
Caixa::getTempoMedioEspera() {
    if(clientes_atendidos_ == 0) {
        return 0;
    } else {
        return (int) tempo_total_/clientes_atendidos_;
    }
}
Caixa::getId() {
	return id_;
}
Caixa::getClientesAtendidos() {
	return clientes_atendidos_;
}
long Caixa::getFaturamentoTotal() {
	return faturamento_total_;
}
Caixa::getTempoTotal() {
	return tempo_total_;
}
Caixa::getSalario() {
	return salario_;
}
Caixa::getEficiencia() {
	return eficiencia_;
}

Caixa::getQuantidadeProdutos() {
	return quantidade_produtos_;
}

Caixa::getTempoCliente(Cliente c) {
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

