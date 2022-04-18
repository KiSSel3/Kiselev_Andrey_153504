#ifndef STACK_H
#define STACK_H

template<typename T>
struct Element {

    T element;
    Element* next;
};

template<typename U>
class Stack {

private:

    Element<U>* top;

public:

    Stack() : top(nullptr) {}
    ~Stack() {

        while (!isEmpty())
            pop();

    }

    void push(U new_element) {

        Element<U>* temp = new Element<U>;

        temp->element = new_element;

        temp->next = top;
        top = temp;
    }

    U pop() {

        if (!isEmpty()) {
            U value = top->element;

            Element<U>* oldtop = top;
            top = oldtop->next;
            delete oldtop;

            return value;
        }
        else {
            return U();
        }
    }

    U Top() {

        return top->element;
    }

    bool isEmpty() {
        return !top;
    }

};

#endif // STACK_H
