#pragma once
#include <iostream>

template<typename T>
class QueuePriority {
public:
    struct Node {
        int pr;
        T data;
        Node *next;

        Node(T data = T(), int pr = 0, Node *n = nullptr) : data(data), pr(pr), next(n) {}
    };
private:
    Node *head;
    int size;
public:

    QueuePriority() : head(nullptr), size(0) {}

    void push(T data, int pr) {
        head = new Node(data, pr, head);
        size++;
    }

    T get() {
        if (size <= 0) {
            std::cout << "Queue is empty";
            return 0;
        }
        T res;
        if (size == 1) {
            Node *tmp = head;
            head = head->next;
            res = tmp->data;
            delete tmp;
            size--;

        } else {

            Node *tmp = head, *result = head, *preResult = nullptr;

            for (int i = 0; i < size-1; ++i) {
                Node *t = tmp;
                tmp = tmp->next;
                if(result->pr <= tmp->pr) {
                    preResult = t;
                    result = tmp;
                }
            }
            res = result->data;
            if(preResult == nullptr) head = result->next;
            else preResult->next = result->next;
            size--;
            delete result;

        }
        return res;
    }

    int getSize(){
        return size;
    }

};



