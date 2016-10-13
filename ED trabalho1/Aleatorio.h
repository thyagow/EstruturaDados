#ifndef ALEATORIO_H
#define ALEATORIO_H


class Aleatorio {
    public:
        Aleatorio();
        virtual ~Aleatorio();
        int tipoDeFila();
        int tipoDePagamento();
        int totalDeCompras();
        int precoItem();
        int eficNovoCaixa();

    protected:

    private:
        int seed_num_;
};

#endif // ALEATORIO_H
