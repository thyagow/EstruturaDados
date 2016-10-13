#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Aleatorio.h"
#include "Cliente.h"
#include "Caixa.h"
#include "Mercado.h"
#include <time.h>
#include <sstream>
#include <fstream>
#include <string>

int a,b,c,d,e;
int main() {
    srand(time(0));
    int entrada;
    void gerarAutomatico();
    void gerarManualmente();
    int infoMercado(Mercado *m);
    int infoCaixas(Mercado *m);
    
    Aleatorio* al = new Aleatorio();
    Mercado *merc;

    std::cout << "0 - Informacoes automaticas;\n"
    << "1 - Colocar manualmente;" << std::endl;
    std::cin >> entrada;

    if (entrada == 0)
        gerarAutomatico();
     else
        gerarManualmente();

    merc = new Mercado(b, a, d, c);

    for (int i = 0; i < e; i++) {
        merc->insereNovoCaixa(0, al->eficNovoCaixa());
    }
    while (merc->passarTempo() == 0){
    }

    std::cout << "ate aqui" <<std::endl;
    infoMercado(merc);
    infoCaixas(merc);

    return 0;
}

int infoMercado(Mercado *merc) {
    std::cout << "\nGERAL: \n" << std::endl;
    std::cout << "Tempo de Execucao (horas): " << (merc->getTempo()/3600) << std::endl;
    std::cout << "Media de entrada dos Clientes (clientes/minuto): " << merc->getIntervaloCliente() << std::endl;
    std::cout << "Faturamento Medio: " << merc->getFaturamentoMedio() << std::endl;
    std::cout << "Faturamento Bruto: " << merc->getFaturamentoBruto() << std::endl;
    std::cout << "Faturamento Liquido: " << merc->getFaturamentoLiquido() << std::endl;
    std::cout << "Numero de Clientes Atendidos: " << merc->getClientesAtendidos() << std::endl;
    std::cout << "Numero de Clientes Desistentes: " << merc->getClientesDesistentes() << std::endl;
    std::cout << "Prejuizo Total: " << merc->getPrejuizo() << std::endl;
    return 0;
}

int infoCaixas(Mercado *merc) {
    std::cout << "\nCAIXAS: \n" << std::endl;
    std::cout << "Salarios Total: " << merc->getCaixasInfo() << std::endl;
    return 0;
}

void gerarAutomatico() {
    std::ifstream ifs;
    int i = 0;
    int vec[4];

    ifs.open("param.txt");
    if (ifs.is_open()) {

        while (!ifs.eof()) {
            char linha[40];
            ifs.getline(linha,40);

            if (linha[0] != '#') {
                vec[i] = atoi(linha);
                i++;
            }
        }
        b = vec[0];
        a = vec[1];
        d = vec[2];
        c = vec[3];
        e = vec[4];
        std::cout << a <<"\n"<< b <<"\n"<< c <<"\n"<< d <<"\n"<< e << std::endl;
    } else {
        std::cout << "Nao foi possivel abrir..." << std::endl;
    }
}

void gerarManualmente() {

        std::cout << "De um valor para:" << std::endl;
        std::cout << "- Tamanho maximo da fila de clientes:" << std::endl;
        std::cin >> a;
        std::cout << "- Intervalo para chegada de clientes:" << std::endl;
        std::cin >> b;
        std::cout << "- Salario Minimo dos caixas:" << std::endl;
        std::cin >> c;
        std::cout << "- Tempo de execucao (horas):" << std::endl;
        std::cin >> d;
        std::cout << "- Quantos caixas vai ter inicialmente;" << std::endl;
        std::cin >> e;
        d = d *3600;
}
