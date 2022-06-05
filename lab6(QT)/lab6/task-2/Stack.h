#ifndef STACK_H
#define STACK_H
#include <iostream>

template <class T>
class Stack {
private:
    T* stack = nullptr;
    size_t size;
    size_t capacity;
    
public:
    Stack(size_t capacity = 20) {
        this->capacity = capacity;
        size = 0;
        
        stack = new T[capacity];
    }
    
    Stack(Stack<T>& other){
        if(stack){
            delete[] stack;
        }

        stack = new T[other.capacity];
        for(size_t i = 0;i<other.capacity;++i){
            stack[i] = other.stack[i];
        }

        size = other.size;
        capacity = other.capacity;
    }
    
    Stack<T>& operator=(Stack<T>& other){
        if(stack){
            delete[] stack;
        }

        stack = new T[other.capacity];
        for(size_t i = 0;i<other.capacity;++i){
            stack[i] = other.stack[i];
        }

        size = other.size;
        capacity = other.capacity;

        return *this;
    }

    ~Stack(){
        if(stack){
            delete[] stack;
        }
    }

    size_t Size(){
        return size;
    }

    bool Empty(){
        if(size){
            return false;
        }
        else{
            return true;
        }
    }

    T& Top(){
        if(!Empty()){
            return stack[size - 1];
        }
        else{
            return stack[0];
        }
    }

    void Pop() {
        if(size){
            --size;
        }
        else {
            return;
        }
    }

    void Push(T& value){
        if(size == capacity){
            T* newStack = new T[capacity*2];
            for(size_t i = 0; i < capacity; ++i){
                newStack[i] = stack[i];
            }
            newStack[capacity] = value;

            capacity *= 2;
            size += 1;

            delete[] stack;
            stack = newStack;
        }
        else{
            stack[size++] = value;
        }
    }
};
#endif // STACK_H
