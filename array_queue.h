#ifndef STRUCTURES_ARRAY_QUEUE_H
#define STRUCTURES_ARRAY_QUEUE_H

#include <cstdint> // std::size_t
#include <stdexcept> // C++ Exceptions

namespace structures {

template<typename T>
class ArrayQueue {

private:
    T* contents; // tipo genérico pra guardar filas de qualquer coisa.
    
    std::size_t size_; // tamanho atual da fila.
    
    std::size_t max_size_; // tamanho máximo da fila.
    
    int front_; // variável que carrega o índice do elemento na frente da fila.
    
    int back_; // variável que carrega o índice do elemento no fim da fila.

    const static auto DEFAULT_SIZE = 10u; // tamanho padrão.
    
public:
    ArrayQueue(){ // construtor para quando não é necessário tamanho máximo na fila.
        back_ = -1;
        front_ = 0;
        contents = new T[max_size_];
        size_ = -1;
    }

    ArrayQueue(std::size_t max){ // construtor padrão, no qual você indica um tamanho máximo à fila.
        back_ = -1;
        front_ = 0;
        max_size_ = max;
        contents = new T[max];
        size_ = -1;
    }

    ~ArrayQueue(){}

    void enqueue(const T& data){ // acrescenta um elemento no fim da fila, se estiver cheia, joga uma exceção.
        if(full())
            throw std::out_of_range("Fila está cheia");
        else{
            back_ ++;
            size_ ++;
            contents[back_] = data;
        }
    }

    T dequeue(){ // retira o elemento na frente da fila, se estiver vazia, joga uma exceção.
        if(empty())
            throw std::out_of_range("Fila está vazia");
        else{
            front_ ++;
            size_ --;
        }
        return contents[front_ - 1];
    }

    T& back(){ // método mostra o elemento no fim da fila, se estiver vazia, joga uma exceção.
        if(empty())
            throw std::out_of_range("Fila está vazia");
        else
            return contents[back_];
    }

    void clear(){ // método limpa a fila.
        front_ = 0;
        back_ = -1;
        size_ = -1;
    }

    std::size_t size(){ // método mostra o tamanho atual da fila. OBS- (size_ + 1) pois ele começa em -1.
        return size_ + 1;
    }

    std::size_t max_size(){ // mostra o tamanho máximo da fila.
        return max_size_;
    }

    bool empty(){ // verifica se está vazia a fila.
       return size_ == -1;
    }

    bool full(){ // verifica se está cheia a fila.
        return size_ == max_size_ - 1;
    }
};
}

#endif
