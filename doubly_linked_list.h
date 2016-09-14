#ifndef STRUCTURES_DOUBLY_LINKED_LIST_H
#define STRUCTURES_DOUBLY_LINKED_LIST_H

#include <cstdint>
#include <stdexcept>

namespace structures {
//! classe lista duplamente encadeada

/* basicamente igual a lista normalmente encadeada, única diferença é que
   possui um ponteiro a mais pra indicar os nodos anteriores
*/

template<typename T>

class DoublyLinkedList {
 public:
        DoublyLinkedList() {  //! construtor
            head = new Node(0u);
            size_ = 0u;
        }  //* básico construtor padrão

        ~DoublyLinkedList() {  //! destrutor
            clear();
            delete(head);
        }  //* destrutor padrão

        void clear() {  //! limpa lista
            while (!empty())
                pop_front();
        }  //* limpa a lista completamente

        void push_back(const T& data) {  //! insere no fim
            return insert(data, size());
        }  //* insere dados no fim da lista

        void push_front(const T& data) {  //! insere no início
            Node *new_ = new Node(data);

            if (new_ == NULL) {
                throw std::out_of_range("LISTACHEIApushfront");

            } else {
                if (!empty()) {
                    new_->next(head->next());
                    head->next()->prev(new_);
                }
                head->next(new_);
                size_++;
            }
        }  //* insere dados no início da lista

        void insert(const T& data, std::size_t index) {  //! insere na posição
            Node *run, *new_;

            if (index == 0) {
                return push_front(data);
            } else {
                if (index > size() || index < 0) {
                    throw std::out_of_range("ERROPOSIÇÃOinsert");
                } else {
                    new_ = new Node(data);

                    if (new_ == NULL) {
                        throw std::out_of_range("LISTACHEIAinsert");
                    }
                    run = head->next();

                    for (auto i = 0; i < index-1; i++) {
                        run = run->next();
                    }
                    if (index != size()) {
                        new_->next(run->next());
                        run->next()->prev(new_);
                    }
                    new_->prev(run);
                    run->next(new_);
                    size_++;
                }
            }
        }  //* insere dados na posição da lista indicada

        void insert_sorted(const T& data) {  //! insere em ordem
            Node *run;

            if (empty()) {
                push_front(data);
            } else {
                auto pos = 0;
                run = head->next();

                while (run->next() != NULL && data > run->data() && pos < size()-1) {
                    run = run->next();
                    pos++;
                }

                if (data > run->data())
                    return push_back(data);
                else
                    return insert(data, pos);
            }
        }  //* insere dados em ordem crescente na lista

        T pop(std::size_t index) {  //! retira da posição
            Node *destroy, *run;
            T back;

            if (index > size()-1 || index < 0) {
                throw std::out_of_range("ERROPOSIÇÃOpop");
            } else {
                if (index == 0) {
                    return pop_front();
                }
                if (index < size()) {
                    run = head->next();
                } else {
                    run = head;
                }
                for (auto i = 0; i < index-1; i++) {
                    run = run->next();
                }
                destroy = run->next();
                back = destroy->data();

                if (index < size()) {
                    run->next(destroy->next());
                }
                if (destroy->next() != NULL) {
                    destroy->next()->prev(run);
                }
                size_--;
                delete(destroy);
            }
            return back;
        }  //* retira dados da posição indicada da lista

        T pop_back() {  //! retira do fim
            Node *run, *destroy;
            T back;

            if (empty()) {
                throw std::out_of_range("LISTAVAZIApopback");
            } else {
                run = head->next();

                for (auto i = 0; i < size()-1; i++) {
                    run = run->next();
                }
                destroy = run;
                back = destroy->data();
                size_--;
                delete(destroy);
            }
            return back;
        }  //* retira dados do fim da lista
        T pop_front() {  //! retira do início
            Node *destroy;
            T back;

            if (empty()) {
                throw std::out_of_range("LISTAVAZIApopfront");
            } else {
                destroy = head->next();
                back = destroy->data();

                if (size() > 1) {
                    head->next(destroy->next());
                }
                size_--;
                delete(destroy);
            }
            return back;
        }  //* retira dados do início da lista

        void remove(const T& data) {  //! retira específico
            Node *run;

            if (empty()) {
                throw std::out_of_range("LISTAVAZIAremove");
            } else {
                run = head->next();
                auto aux = 0;

                while (run->data() != data && aux < size()-1) {
                    run = run->next();
                    aux++;
                }
                pop(aux);
            }
        }  //* remove os dados indicados da lista

        bool empty() const {  //! lista vazia
            if (size() == 0)
                return true;
            else
                return false;
        }  //* verifica se lista está vazia

        bool contains(const T& data) const {  //! contém
            Node *run;
            run = head->next();

            for (auto i = 0; i < size(); i++) {
                if (run->data() == data) {
                    return true;
                }
                run = run->next();
            }
            return false;
        }  //* verifica se a lista contém os dados indicados

        T& at(std::size_t index) {  //! acesso a um elemento (checando limites)
            Node *dado = head->next();

            if (empty()) {
                throw std::out_of_range("LISTAVAZIAat");
            } else {
                if (index > size() || index < 0) {
                    throw std::out_of_range("ERROPOSIÇÃOat");
                } else {
                    for (int i = 0; i < index; i++) {
                        dado = dado->next();
                    }
                    return dado->data();
                }
            }
        }  //* verifica os dados na posição index

        const T& at(std::size_t index) const {  //! acesso a um elemento
            Node *dado = head->next();

            if (empty()) {
                throw std::out_of_range("LISTAVAZIAat");
            } else {
                if (index > size() || index < 0) {
                    throw std::out_of_range("ERROPOSIÇÃOat");
                } else {
                    for (int i = 0; i < index; i++) {
                        dado = dado->next();
                    }
                    return dado->data();
                }
            }
        }  //* verifica os dados na posição index(constante)

        std::size_t find(const T& data) const {  //! posição de um dado
            Node *run = head->next();

            for (auto i = 0; i < size(); i++) {
                if (run->data() == data) {
                    return i;
                }
                run = run->next();
            }
            return size();
        }  //* verifica a posição dos dados indicados na lista

        std::size_t size() const {  //! tamanho
            return size_;
        }  //* verifica o tamanho da lista

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
        Node(const T& data, Node* prev, Node* next):
            data_{data},
            next_{next},
            prev_{prev}
        {}
        T& data() {
            return data_;
        }
        const T& data() const {
            return data_;
        }
        Node* prev() {
            return prev_;
        }
        const Node* prev() const {
            return prev_;
        }
        void prev(Node* node) {
            prev_ = node;
        }
        Node* next() {
            return next_;
        }
        const Node* next() const {
            return next_;
        }
        void next(Node* node) {
            next_ = node;
        }

     private:
        T data_;
        Node* prev_;
        Node* next_;
    };
    Node* head;
    std::size_t size_;
};
}  // namespace structures
#endif
