#ifndef Stack_H
#define Stack_H
#include <iostream>

template <class T>
class Stack {
    struct Node {
        Node *prev = nullptr;
        T data;
    };
public:
    Node *TopElem;
    size_t size;

    Stack(): size(0) {TopElem = new Node();}

    ~Stack() { }

    size_t Size() {
        return size;
    }

    const bool Empty() {
        if (size) {
            return false;
        } else {
            return true;
        }
    }

    T Top() {
        if (size) {
            return TopElem->prev->data;
        }
    }

    void Pop() {
        if (size > 1) {
            TopElem = TopElem->prev;
            --size;
        } else if (size == 1) {
            TopElem = new Node();
            --size;
        }
    }

    void Push(T value) {
        TopElem->data = value;
        Node* buff = new Node();
        buff->prev = TopElem;
        TopElem = buff;
        ++size;
    }

    Stack<T>& operator=(Stack<T> &stack) {
        Stack *buff = new Stack();

        while (!stack.Empty()) {
            buff->Push(stack.Top());
            stack.Pop();
        }

        while (!Empty()) {
            Pop();
        }

        while (!buff->Empty()) {
            Push(buff->Top());
            stack.Push(buff->Top());
            buff->Pop();
        }

        return *this;
    }
};

#endif // Stack_H
