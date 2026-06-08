// #include<bits/stdc++.h>
#include "../Linked_List/Singly_Linked_List.cpp"
using namespace std;

template <typename T>
struct dll_node : ll_node<T>{
    dll_node<T>* prev;

    dll_node() : ll_node<T>(){
        prev = nullptr;
    }

    dll_node(T val) : ll_node<T>(val){
        prev = nullptr;
    }

    dll_node(dll_node* nxt, dll_node* prv) : ll_node<T>(nxt){
        prev = prv;
    }

    dll_node(T val, dll_node* nxt, dll_node* prv) : ll_node<T>(val, nxt){
        prev = prv;
    }
};

template <typename T>
class DoublyLinkedList{
    private:
        dll_node<T>* head;
        dll_node<T>* tail;
        size_t size;  
    
    public:
        DoublyLinkedList(){
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        ~DoublyLinkedList(){
            dll_node<T>* temp = head;
            while(temp != nullptr){
                dll_node<T>* next_node = temp->next;
                delete temp;
                temp = next_node;
            }
        }

        const dll_node<T>* head() const {
            return head;
        }
        
        const dll_node<T>* tail() const {
            return tail;
        }

        size_t size() const {
            return size;
        }

        void print_forward(){
            dll_node<T>* temp = head;
            while(temp != nullptr){
                cout << temp->data << " <-> ";
                temp = temp->next;
            }
            cout << "nullptr" << endl;
        }

        void print_backward(){
            dll_node<T>* temp = tail;
            while(temp != nullptr){
                cout << temp->data << " <-> ";
                temp = temp->prev;
            }
            cout << "nullptr" << endl;
        }

        void insert_head(T val){
            dll_node<T>* new_node = new dll_node<T>(val);
            if(head == nullptr){
                head = new_node;
                tail = new_node;
            }else{
                new_node->next = head;
                head->prev = new_node;
                head = new_node;
            }
            size++;
        }

        void insert_tail(T val){
            dll_node<T>* new_node = new dll_node<T>(val);
            if(tail == nullptr){
                head = new_node;
                tail = new_node;
            }else{
                tail->next = new_node;
                new_node->prev = tail;
                tail = new_node;
            }
            size++;
        }

        void insert_at(T val, int index){
            if(index < 0 || index > size){
                cout << "Index out of bounds" << endl;
                return;
            }
            if(index == 0){
                insert_head(val);
                return;
            }
            if(index == size){
                insert_tail(val);
                return;
            }
            dll_node<T>* new_node = new dll_node<T>(val);
            dll_node<T>* temp = head;
            for(int i = 0; i < index - 1; i++){
                temp = temp->next;
            }
            new_node->next = temp->next;
            new_node->prev = temp;
            temp->next->prev = new_node;
            temp->next = new_node;
            size++;
        }

        void delete_head(){
            if(head == nullptr){
                cout << "List is empty" << endl;
                return;
            }
            dll_node<T>* temp = head;
            head = head->next;
            if(head != nullptr){
                head->prev = nullptr;
            }else{
                tail = nullptr;
            }
            delete temp;
            size--;
        }

        void delete_tail(){
            if(tail == nullptr){
                cout << "List is empty" << endl;
                return;
            }
            dll_node<T>* temp = tail;
            tail = tail->prev;
            if(tail != nullptr){
                tail->next = nullptr;
            }else{
                head = nullptr;
            }
            delete temp;
            size--;
        }

        void delete_at(int index){
            if(index < 0 || index >= size){
                cout << "Index out of bounds" << endl;
                return;
            }
            if(index == 0){
                delete_head();
                return;
            }
            if(index == size - 1){
                delete_tail();
                return;
            }
            dll_node<T>* temp = head;
            for(int i = 0; i < index; i++){
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            size--;
        }

        void clear(){
            dll_node<T>* temp = head;
            while(temp != nullptr){
                dll_node<T>* next_node = temp->next;
                delete temp;
                temp = next_node;
            }
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        dll_node<T>* find(T val){
            dll_node<T>* temp = head;
            while(temp != nullptr){
                if(temp->data == val){
                    return temp;
                }
                temp = temp->next;
            }
            return nullptr;
        }

        void reverse(){
            dll_node<T>* current = head;
            dll_node<T>* temp = nullptr;
            tail = head;
            while(current != nullptr){
                temp = current->prev;
                current->prev = current->next;
                current->next = temp;
                current = current->prev;
            }
            if(temp != nullptr){
                head = temp->prev;
            }
        }
};

