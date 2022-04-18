#ifndef DOUBLIST_H
#define DOUBLIST_H

template<typename T, typename K>
struct Node {
    T data = T();
    Node* next = nullptr, * prev = nullptr;

    K key = K();

    Node() = default;
    Node(T value) : data(value) {}
    Node(T value, K key_) : data(value), key(key_) {}
};

template<typename T, typename K>
class DoubList {

    int Size;

    Node<T, K>* head;
    Node<T, K>* tail;

public:

    DoubList() : Size(0), head(nullptr), tail(nullptr) {}

    ~DoubList() {
        while (!isEmpty()) {
            tail = head->next;
            delete head;
            head = tail;
        }
    }

    void push_back(const T value, const K key_ = K()) {
        Node<T, K>* new_element = new Node<T, K>;
        new_element->next = nullptr;
        new_element->data = value;
        new_element->key = key_;

        if (isEmpty()) {
            new_element->prev = nullptr;
            head = tail = new_element;
        }
        else {
            new_element->prev = tail;
            tail->next = new_element;
            tail = new_element;
        }
        ++Size;
    }

    void push_front(const T value = T(), const K key_ = K()) {

        if (isEmpty()) return push_back(value, key_);

        Node<T, K>* new_element = new Node<T, K>;

        new_element->data = value;
        new_element->prev = nullptr;
        new_element->key = key_;


        head->prev = new_element;
        new_element->next = head;
        head = new_element;

        ++Size;
    }


    K pop_back() {
        if (isEmpty())
            return K();

        K key = tail->key;

        Node<T, K>* cur = tail;

        tail = tail->prev;

        tail->next = nullptr;

        delete cur;

        --Size;

        return key;
    }

    K pop_front() {

        if (!head)
            return K();

        K key = head->key;

        Node<T, K>* temp = head;

        head = head->next;

        if (head)
            head->prev = nullptr;

        delete temp;

        --Size;

        return key;
    }

    const void clear() {
        while (!isEmpty()) {
            tail = head->next;
            delete head;
            head = tail;
        }
    }

    inline bool isEmpty() const {
        return !head;
    }

    inline short size() const {
        return Size;
    }

    T& operator[](const short index) {

        Node<T, K>* cur;

        if (index > Size / 2) {

            short cur_index = Size - 1;

            for (cur = tail; cur_index != index; cur = cur->prev)
                --cur_index;
        }
        else {
            short cur_index = 0;

            for (cur = head; cur_index != index; cur = cur->next)
                ++cur_index;
        }
        return cur->data;
    }
};
#endif // DOUBLIST_H
