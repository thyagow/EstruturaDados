#ifndef STRUCTURES_ARRAY_LIST_H
#define STRUCTURES_ARRAY_LIST_H

#include <cstdint>
#include <stdexcept>

namespace structures {

template<typename T>
class ArrayList {
    
private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;

    const static auto DEFAULT_SIZE = 10u;
    
public:
    
    //!CONTRUTOR DA LISTA
    ArrayList(){
        contents = new T[max_size_];
        size_ = -1;
    }//*É USADO QUANDO PRECISA-SE CHAMAR UMA NOVA LISTA, MAS NÃO É
    //* NECESSÁRIO TER UM PARÂMETRO PARA ELA.

   
    //!CONSTRUTOR DA LISTA
    ArrayList(std::size_t max_size){
        max_size_ = max_size;
        contents = new T[max_size];
        size_ = -1;
    }//*CONSTRUTOR PADRÃO DA LISTA.

    ~ArrayList(){}

    //!MÉTODO LISTA VAZIA
    bool empty(){
        if(size_ == -1)
            return true;
        else
            return false;
    }//*VERIFICA SE A LISTA ESTÁ VAZIA.
    
   
    //!MÉTODO LISTA CHEIA
    bool full(){
        if(size_ == max_size_-1)
            return true;
        else
            return false;
    }//*VERIFICA SE A LISTA ESTÁ CHEIA.

    
    //!MÉTODO LISTA CONTÉM
    bool contains(const T& data){
       for(auto i = 0; i <= size_; i++){
           if(contents[i] == data)
                return true;
       }
       return false;
    }//*VERIFICA SE NA LISTA CONTÉM O ELEMENTO NO PARÂMETRO.

    
    //!MÉTODO BUSCA
    std::size_t find(const T& data){
        std::size_t aux = 0;
        
        while(data != contents[aux] && aux < size_+1){
            aux++;
        }
        return aux;
    }//*RETORNA A POSIÇÃO DO ELEMENTO CITADO NO PARÂMETRO.
    
    
    //!MÉTODO TAMANHO ATUAL
    std::size_t size(){
        return size_+1;
    }//*RETORNA O TAMANHO ATUAL DA LISTA (É O ÚLTIMO ELEMENTO DA LISTA TAMBÉM).


    //!MÉTODO TAMANHO MÁXIMO
    std::size_t max_size(){
        return max_size_;
    }//*RETORNA O TAMANHO MÁXIMO AO QUAL A LISTA PODE ALCANÇAR.
    
    
    //!MÉTODO ELEMENTO NA POSIÇÃO
    T at(std::size_t index){
       if(index < 0 || index > size_)
            throw std::out_of_range("Posição inválida!");
       else
            return contents[index];
    }//*RETORNA O ELEMENTO QUE ESTÁ NA POSIÇÃO CITADA NO PARÂMETRO.

    
    //!MÉTODO OPERATOR
    T& operator[](std::size_t index){
       return contents[index];
    }//*RETORNA O ELEMENTO QUE ESTÁ NA POSIÇÃO CITADA NO PARÂMETRO.


    //!MÉTODO ADICIONA NO FIM
    void push_back(T data){
        if(full())
            throw std::out_of_range("Lista está cheia!");
        else{
            size_++;
        }
        contents[size_] = data;
    }//*LITERALMENTE ADICIONA O ELEMENTO NO FIM DA LISTA.


    //!MÉTODO ADICIONA NO INÍCIO
    void push_front(T data){
        std::size_t aux;
        if(full())
            throw std::out_of_range("Lista está cheia!");
        else{
            size_++;
            aux = size_;
           
            while(aux > 0){
                contents[aux] = contents[aux-1];
                aux--;
            }
            contents[0] = data;
        }
    }//*LITERALMENTE ADICIONA O ELEMENTO NO INÍCIO DA LISTA.
    
    
    //!MÉTODO INSERIR
    void insert(T data, std::size_t index){
        std::size_t aux;
        if(index > size_+1 ||index < 0)
            throw std::out_of_range("Posição inválida!");
        else{
            if(full())
                throw std::out_of_range("Lista está cheia!");
            else{ 
                size_++;
                aux = size_;
                
                while(aux > index){
                    contents[aux] = contents[aux-1];
                    aux--;
                }
                contents[index] = data;
           }
        }
    }//*ADICIONA O ELEMENTO NA POSIÇÃO ORDENADA.


    //!MÉTODO INSERIR EM ORDEM
    void insert_sorted(T data){
        if(full())
            throw std::out_of_range("Lista cheia!");
        else{
            std::size_t aux = 0;
            while(aux < size_+1 && (data > contents[aux]))
                    aux++;
            
            insert(data, aux);
        }
    }//*ADICIONA O ELEMENTO EM ORDEM CRESCENTE.
    
    
    //!MÉTODO RETIRA
    T pop(std::size_t index){
        std::size_t aux;
        T elem;
        if(empty())
            throw std::out_of_range("Lista está vazia!");
        else{
            if(index > size_ || index < 0)
               throw std::out_of_range("Posição inválida!");
            else{
                size_--;
                elem = contents[index];
                aux = index;
                
                while(aux <= size_){
                    contents[aux] = contents[aux+1];
                    aux++;
                }
            }
        }
         return elem;
    }//*RETIRA O ELEMENTO DA POSIÇÃO INDICADA.
    
    
    //!MÉTODO RETIRA DO INÍCIO
    T pop_front(){
        std::size_t aux;
        T elem;
        if(empty())
            throw std::out_of_range("Lista está vazia!");
        else{
            size_--;
            elem = contents[0];
            aux = 0;
            while(aux < size_+1){
                contents[aux] = contents[aux+1];
                aux++;
            }
        }
        return elem;
    }//*RETIRA O ELEMENTO NA POSIÇAO 0 DA LISTA(PODE-SE RESUMIR O CÓDIGO À <RETURN POP(0)> ).
    
    
    //!MÉTODO RETIRA DO FIM
    T pop_back(){
        if(empty())
            throw std::out_of_range("Lista está vazia!");
        else{
            size_--;
        }
        return contents[size_+1];
    }//*RETIRA O ÚLTIMO ELEMENTO DA LISTA(PODE-SE RESUMIR O CÓDIGO À <RETURN POP(SIZE_)> ).
    
    
    //! MÉTODO LIMPA LISTA
    void clear(){
        size_ = -1;
    }//*LITERALMENTE LIMPA A LISTA.
    
    
    //!MÉTODO REMOVE
    void remove(T data){
        std::size_t aux;
        if(empty())
            throw std::out_of_range("Lista está vazia!");
        else{
            
            for(auto i = 0; i <= size_; i++){
                if(data == contents[i])
                    aux = i;
            }
            pop(aux);
        }
    }//*RETIRA O ELEMENTO CITADO NO PARÂMETRO DA LISTA.

};
}

#endif
