#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct ll_node{
    T data;
    ll_node* next;

    ll_node(){
        next = nullptr;
    }

    ll_node(T val){
        data = val;
        next = nullptr;
    }

    ll_node(ll_node* nxt){
        next = nxt;
    }

    ll_node(T val,ll_node* nxt){
        data = val;
        next = nxt;
    }
};

template <typename T>
class LinkedList{
    private:
        ll_node<T>* head;
        ll_node<T>* tail;
        int size;   
    public:
        LinkedList(){
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        ~LinkedList(){
            ll_node<T>* temp = head;
            while(temp != nullptr){
                ll_node<T>* next_node = temp->next;
                delete temp;
                temp = next_node;
            }
        }

        void insert_head(T val){
            ll_node<T>* new_node = new ll_node<T>(val);
            if(head == nullptr){
                head = new_node;
                tail = new_node;
            }else{
                new_node->next = head;
                head = new_node;
            }
            size++;
        }

        void insert_tail(T val){
            ll_node<T>* new_node = new ll_node<T>(val);
            if(tail == nullptr){
                head = new_node;
                tail = new_node;
            }else{
                tail->next = new_node;
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
            ll_node<T>* new_node = new ll_node<T>(val);
            ll_node<T>* temp = head;
            for(int i = 0; i < index - 1; i++){
                temp = temp->next;
            }
            new_node->next = temp->next;
            temp->next = new_node;
            size++;
        }

        void delete_head(){
            if(head == nullptr){
                cout << "List is empty" << endl;
                return;
            }
            ll_node<T>* temp = head;
            head = head->next;
            delete temp;
            size--;
            if(size == 0){
                tail = nullptr;
            }
        }

        void delete_tail(){
            if(tail == nullptr){
                cout << "List is empty" << endl;
                return;
            }
            if(size == 1){
                delete head;
                head = nullptr;
                tail = nullptr;
                size--;
                return;
            }
            ll_node<T>* temp = head;
            while(temp->next != tail){
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
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
            ll_node<T>* temp = head;
            for(int i = 0; i < index - 1; i++){
                temp = temp->next;
            }
            ll_node<T>* node_to_delete = temp->next;
            temp->next = node_to_delete->next;
            delete node_to_delete;
            size--;
        }

        void clear(){
            ll_node<T>* temp = head;
            while(temp != nullptr){
                ll_node<T>* next_node = temp->next;
                delete temp;
                temp = next_node;
            }
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        ll_node<T>* find(T val){
            ll_node<T>* temp = head;
            while(temp != nullptr){
                if(temp->data == val){
                    return temp;
                }
                temp = temp->next;
            }
            return nullptr;
        }

        void reverse(){
            ll_node<T>* prev = nullptr;
            ll_node<T>* current = head;
            tail = head;
            while(current != nullptr){
                ll_node<T>* next_node = current->next;
                current->next = prev;
                prev = current;
                current = next_node;
            }
            head = prev;
        }

        void print(){
            ll_node<T>* temp = head;
            while(temp != nullptr){
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "nullptr" << endl;
        }
        int size(){
            return size;
        }
};