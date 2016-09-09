#ifndef STRUCTURES_ARRAY_STACK_H
#define STRUCTURES_ARRAY_STACK_H

#include <cstdint> // std::size_t
#include <stdexcept> // C++ exceptions

namespace structures {

template<typename T>  
class ArrayStack {

private:
    T* contents; //Tipo genérico pra guardar pilhas de qualquer coisa.
    
    int top_; //Usada para indicar qual índice do atual topo da pilha de "coisas".
    
    std::size_t max_size_; //Número máximo de elementos que cabem nessa pilha.

    const static auto DEFAULT_SIZE = 10u; //Tamanho padrão.

public:

    ArrayStack(){ //Construtor usado quando não é necessário indicar um tamanho máximo.
        contents = new T[max_size_];
        top_ = -1;
    }

    ArrayStack(std::size_t max){ //Construtor padrão, onde você define tamanho máximo.
       max_size_ = max;
       contents = new T[max];
       top_ = -1;
    }
    
    ~ArrayStack(){}
    
    bool empty(){ // verifica se está vazia a pilha.
        return top_ == -1;
    } 

    bool full(){ // verifica se está cheia a pilha.
        return top_ == max_size_ - 1;
    }

    void push(const T& data){ // empilha, se estiver cheia, joga uma exceção.
        if(full())
            throw std::out_of_range("Pilha já está cheia");
        else{
            top_ ++;
            contents[top_] = data;
        }
    } 
    
    T pop(){ // desempilha, se estiver vazia, joga uma exceção.
        if(empty())
            throw std::out_of_range("Pilha já está vazia");
        else{
            top_ --;
        }
        return contents[top_ + 1];
    }
    
    T& top(){ // pega o elemento no topo, se estiver vazia, joga uma exceção.
        if(empty())
           throw std::out_of_range("Pilha está vazia");
        else
            return contents[top_];
    }

    void clear(){ // limpa.
        top_ = -1;
    }
    
    std::size_t size(){ // tamanho.
        return top_ + 1;
    }
    
    std::size_t max_size(){ // tamanho máximo.
        return max_size_;
    }
   
};
};
#endif
