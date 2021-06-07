#pragma once
#include <iostream>

template<typename T>
class Stack{
    struct Node{
        T data;
        Node *next;
    };
    int size;
    Node *head;
public:
    Stack() : size(0), head(nullptr) {}
    bool push(T val){
        try {
            Node *tmp = new Node();
            tmp->data = val;
            tmp->next = head;
            head = tmp;
            size++;
            return true;
        } catch (std::bad_alloc& err) {
            std::cerr << err.what() << std::endl;
            std::cout << "Stack overflow";
            return false;
        }
    }

    T pop(){
        if (size <= 0){
            std::cout << "Stack is empty" << std::endl;
            return 0;
        }
        Node *tmp = head;
        T result = head->data;
        head = head->next;
        delete tmp;
        size--;
        return result;
    }

    int getSize(){
        return size;
    }

};