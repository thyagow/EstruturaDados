#ifndef STRUCTURES_LINKED_LIST_H
#define STRUCTURES_LINKED_LIST_H

#include <cstdint>
#include <stdexcept>



namespace structures {

template<typename T>

//! classe lista encadeada

/*! contém os métodos da lista
* utiliza nodos para representar
* os elementos da lista
*/
class LinkedList { 
    
    public:
        
        LinkedList(){ //! construtor padrão
            head = new Node(0u);
            size_ = 0u;
        }/*! inicia o head e o size da lista
        */
        
        ~LinkedList(){ //! destrutor
            clear();
            delete(head);
        }/*! chama o clear()
        */
        
        void clear(){ //! limpa lista
            while(!empty()){
                pop_back();
            }
        }/* limpa a lista
        */
        
        void push_back(const T& data){ //! inserir no fim
           return insert(data, size());
        }/* insere o elemento no fim da lista
        */
        
        void push_front(const T& data){ //! inserir no início
            Node *new_;
            new_ = new Node(data);
            
            if(new_ == NULL)
                throw std::out_of_range("LISTACHEIApushfront");
            else{
                if(!empty())
                    new_->next(head->next());
                head->next(new_);
                size_++;
            }
           
        }/* insere o elemento no início da lista
        */
        
        void insert(const T& data, std::size_t index){ //! inserir na posição
            Node *new_, *previous_;
            
            if(index > size() || index < 0)
                throw std::out_of_range("ERROPOSIÇÃOinsert");
            else{
                if(index == 0)
                    return push_front(data);
                else{
                    new_ = new Node(data);
                       
                    if(new_ == NULL)
                        throw std::out_of_range("LISTACHEIAinsert");
                    else{
                        previous_ = head->next();
                            
                        for(auto i = 0; i < index-1; i++){
                            previous_ = previous_->next();
                        }
                        new_->next(previous_->next());
                        previous_->next(new_);
                        size_++;
                    }
                }
            }
            
        }/* insere o elemento na posição indicada
        */
        
        void insert_sorted(const T& data){ //! inserir em ordem
            Node *actual;
            int position;
            
            if(empty())
                return push_front(data);
            else{
                actual = head->next();
                position = 0;
                
                while(actual->next() != NULL && data > actual->data()){
                    position++;
                    actual = actual->next();
                }
                if(data > actual->data())
                    return insert(data, position+1);
                else
                    return insert(data, position);
            }
        }/*insere o elemento em ordem crescente
        */
        
        T at(std::size_t index){ //! valor na posição
            Node* run;
            std::size_t aux = 0;
                        
            run = head->next();
            
            if(empty())
                throw std::out_of_range("LISTAVAZIAat");
            else
                if(index < 0 || index > size())
                    throw std::out_of_range("ERROPOSIÇÃOat");
                else{
                    while(aux < index){
                    run = run->next();
                    aux++;
                    }
                }
            return run->data();
        }/* informa o valor do elemento na posição indicada
        */
        
        T pop(std::size_t index){ //! retira na posição
            Node *previous_, *destroy_;
            T back_;
            
            if(index > size()-1 || index < 0)
                throw std::out_of_range("ERROPOSIÇÃOpop");
            else{
                if(index == 0)
                    return pop_front();
                else{
                    if(index == size())
                        previous_ = head;
                    else
                        previous_ = head->next();
                    
                    for(auto i = 0; i < index-1; i++)
                        previous_ = previous_->next();
                        
                    destroy_ = previous_->next();
                    back_ = destroy_->data();
                    previous_->next(destroy_->next());
                    size_--;
                    delete(destroy_);
                }
                return back_;
            }
        }/* retira o elemento na posição indicada
        */
        
        T pop_back(){ //! retira no fim
            if(empty())
                throw std::out_of_range("LISTAVAZIApopback");
            else
                return pop(size()-1);
        }/* retira o último elemento da lista
        */
        
        T pop_front(){ //! retira no início
            Node *left_;
            T back_;
            
            if(empty())
                throw std::out_of_range("LISTAVAZIApopfront");
            else{
                left_ = head->next();
                head->next(left_->next());
                back_ = left_->data();
                size_--;
                delete(left_);
            }
            return back_;
        }/* retira o último elemento da lista
        */
        
        void remove(const T& data){ //! remove elemento
            Node *run, *previous;
            
            if(empty())
                throw std::out_of_range("LISTAVAZIAremove");
            else{
                run = head->next();
                
                for(auto i = 0; i < size(); i++){
                    if(data == run->data()){
                        previous->next(run->next());
                        delete(run);
                        size_--;
                        break;
                    }
                    previous = run;
                    run = run->next();
                }
            }
        }/* retira o elemento indicado
        */
        
        bool empty() const{ //! lista vazia
            if(size_ == 0)
                return true;
            else
                return false;
        }/* verifica se lista está vazia
        */
        
        bool contains(const T& data) const{  //! contém elemento
            Node *run;
            
            run = head->next();
            for(auto i = 0; i < size(); i++){
                if(data == run->data()){
                    return true;
                }
                run = run->next();
            }
            return false;
        }/* verifica se a lista contém o elemento idicado
        */
        
        std::size_t find(const T& data) const{ //! busca elemento
            Node *run;
            
            run = head->next();
            for(auto i = 0; i < size(); i++){
                if(data == run->data()){
                    return i;
                }
                run = run->next();
            }
            return size();
        }/* mostra a posição do elemento indicado
        */
        
        std::size_t size() const{ //! tamanho lista
            return size_;
        }/* mostra o tamanho atual da lista
        */
        
    private:
    
        class Node { //! elemento
        public:
            Node(const T& data):
                data_{data}
            {}
    
            Node(const T& data, Node* next):
                data_{data},
                next_{next}
            {}
    
            T& data() { //! getter : dado
                return data_;
            }/* retorna valor do dado nesse elemento
            */
    
            const T& data() const { //! getter const : dado
                return data_;
            }/* retorna o valor constante do dado nesse elemento
            */
    
            Node* next() { //! getter : próximo
                return next_;
            }/* retorna o próximo elemento em relação ao atual
            */
    
            const Node* next() const { //! getter const : próximo
                return next_;
            }/* retorna o próximo elemento constante em relação ao atual
            */
    
            void next(Node* node) { //! setter : próximo
                next_ = node;
            }/* faz do elemento indicado o próximo em relação ao atual
            */
            
             private:
                T data_;
                Node *next_{nullptr};
            };
    
            Node* end() { //! último nodo da lista
                auto it = head;
                for (auto i = 1u; i < size(); ++i) {
                    it = it->next();
                }
                return it;
            }/* retorna o último elemento(nodo) da lista 
            */
    
            Node* head{nullptr};
            std::size_t size_{0u};
    };

}

#endif
