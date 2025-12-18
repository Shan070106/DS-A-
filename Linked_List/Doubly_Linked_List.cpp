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