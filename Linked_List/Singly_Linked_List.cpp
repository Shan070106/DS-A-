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

