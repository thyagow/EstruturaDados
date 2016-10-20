#ifndef STRUCTURES_LINKED_QUEUE_H
#define STRUCTURES_LINKED_QUEUE_H

#include <cstdint>
#include <stdexcept>
#include <iostream>

namespace structures {
//! fila encadeada
/*  implementação de fila através de nodos, não possui
    um tamanho máximo definido
*/

template<typename T>

class LinkedQueue {
 public:
    LinkedQueue() {  //! construtor
        head = NULL;
        tail = NULL;
        size_ = 0u;
    }  // construtor padrão

    ~LinkedQueue() {  //! destrutor
        clear();
        delete head;
    }  // destrutor padrão

    void clear() {  //! limpar
        while (!empty()) {
            remove();
        }
    }  // limpa a fila

    void queue(const T& data) {  //! enfilerar
        Node *run;
        Node *new_ = new Node(data);

        if (new_ == NULL) {
            throw std::out_of_range("LISTACHEIAenqueue");
        } else {
            if (empty()) {
                head = new_;
            } else {
                tail->next(new_);
            }
            tail = new_;
            size_++;
        }
    }  // adiciona um elemento à fila

    void remove() {  //! desenfilerar
        Node *destroy;

        if (empty()) {
            throw std::out_of_range("LISTAVAZIAdequeue");
        } else {
            destroy = head;
            head = destroy->next();
            size_--;
            delete(destroy);
        }
    }  // retira um elemento da fila

    T& front() const {  //! primeiro dado
        if (empty())
            throw std::out_of_range("LISTAVAZIAfront");
        else
            return head->data();
    }  // mostra o primeiro elemento da fila

    T& back() const {  //! último dado
        if (empty())
            throw std::out_of_range("LISTAVAZIAback");
        else
            return tail->data();
    }  // mostra o último elemento da fila

    bool empty() const {  //! fila vazia
        if (size_ == 0)
            return true;
        else
            return false;
    }  // verifica se a fila está vazia

    std::size_t size() const {  //! tamanho
        return size_;
    }  // verifica tamanho atual da fila

 private:
    class Node {
     public:
        Node(const T& data):
            data_{data}
        {}
        Node(const T& data, Node *next):
            data_{data},
            next_{next}
        {}
        T& data() {
            return data_;
        }
        T& data() const {
            return data_;
        }
        Node* next() {
            return next_;
        }
        Node* next() const {
            return next_;
        }
        void next(Node *next) {
            next_ = next;
        }

     private:
        T data_;
        Node *next_{nullptr};
    };
    Node* head;  // nodo-cabeça
    Node* tail;  // nodo-fim
    std::size_t size_;  // tamanho
};
}  // namespace structures
#endif
