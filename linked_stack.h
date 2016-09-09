#ifndef STRUCTURES_LINKED_STACK_H
#define STRUCTURES_LINKED_STACK_H

#include <cstdint>
#include <stdexcept>

namespace structures {

template<typename T>
class LinkedStack {
public:
    
    LinkedStack(){
        top_ = new Node(0u);
        size_ = 0u;
    }

    ~LinkedStack(){
        clear();
        delete(top_);
    }

    void clear(){ // limpa pilha
        while(!empty()){
            pop();
        }
    } 

    void push(const T& data){ // empilha
        Node *new_ = new Node(data);
        
        if(new_ == NULL)
            throw std::out_of_range("LISTACHEIApush");
        else{
            if(!empty())
                new_->next(top_->next());
            top_->next(new_);
            size_++;
        }
    } 

    T pop(){ // desempilha
    Node *destroy;
    T back;
        if(empty())
            throw std::out_of_range("LISTAVAZIApop");
        else{
            if(size_ > 1){
                destroy = top_->next();
                back = destroy->data();
                top_->next(destroy->next());
                size_--;
                delete(destroy);
            }else{
                back = top_->next()->data();
                size_--;
                delete(top_->next());
            }
        }
        return back;
    } 

    T& top() const{ // dado no topo
        if(empty())
            throw std::out_of_range("LISTAVAZIAtop");
        else
            return top_->next()->data();
    } 

    bool empty() const{ // pilha vazia
        if(size_ == 0)
            return true;
        else
            return false;
    } 

    std::size_t size() const{ // tamanho da pilha
        return size_;
    } 

private:
    
    class Node {
    public:
        
        Node(const T& data):
            data_{data}
        {}
        Node(const T& data, Node* next):
            data_{data},
            next_{next}
        {}

        T& data(){ // getter: info
            return data_;
        } 
        const T& data() const{ // getter-constante: info
            return data_;
        } 
        Node* next(){ // getter: próximo
            return next_;
        } 
        const Node* next() const{ // getter-constante: próximo
            return next_;
        } 
        void next(Node* next){ // setter: próximo
            next_ = next;
        } 
    private:
        T data_;
        Node* next_;
    };

    Node* top_; // nodo-topo
    std::size_t size_; // tamanho
};

}

#endif