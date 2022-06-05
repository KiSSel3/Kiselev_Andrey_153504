#ifndef QUEUE_H
#define QUEUE_H


#include <memory>
#include <iostream>

template <typename T>
class Queue{
    struct Node{
        T data;
        std::unique_ptr<Node> next;

        Node(const T &data, std::unique_ptr<Node> next)
            : data(data), next(std::move(next)){}
    };

    std::unique_ptr<Node> head = nullptr;
    Node *tail = nullptr;

public:
    Queue() = default;
    Queue(const Queue &) = delete;
    Queue operator=(const Queue &) = delete;

    void push(const T &data){
        if(!head || !tail){
            head = std::make_unique<Node>(data, nullptr);
            tail = head.get();
        }
        else{
            auto newTail = std::make_unique<Node>(data, nullptr);
            tail->next = std::move(newTail);
            tail = tail->next.get();
        }
    }

    void pop(){
        assert(head && tail);
        if(head.get() == tail){
            head = nullptr;
            tail = nullptr;
        }
        else{
            head = std::move(head->next);
        }
    }

    T top(){
        assert(head && tail);
        return head->data;
    }

    bool empty(){
        return !head && !tail;
    }
};

#endif
