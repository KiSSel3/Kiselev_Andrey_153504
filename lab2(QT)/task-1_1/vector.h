#ifndef VECTOR_H
#define VECTOR_H

#include <QDebug>

template<typename T>
class Vector {

private:
    const short default_capacity = 10;
    short size, capacity, i;
    T* arr;

public:
    Vector() :size(0), capacity(default_capacity), arr(new T[capacity])
    {}
    Vector(short amount, T value = T()) :size(amount), capacity(default_capacity), arr(new T[capacity]) {
        if (amount <= 0) throw;
        for (i = 0; i < size; ++i)
            arr[i] = value;
    }

    ~Vector() {
        for (i = 0; i < capacity; ++i)
            (arr + i)->~T();
    }

    class iterator {

    private: T* cur;
    public:
        iterator() :cur(nullptr) {}

        iterator(T* value) :cur(value) {}

        T& operator+ (short n) { return *(cur + n); }
        T& operator- (short n) { return *(cur - n); }
        T& operator++ () { return *(++cur); }
        T& operator-- () { return *(--cur); }
        T& operator++ (int) { return *(cur++); }
        T& operator-- (int) { return *(cur--); }
        bool operator!= (const iterator& rhs) { return cur != rhs.cur; }
        bool operator== (const iterator& rhs) { return cur == rhs.cur; }
        T& operator* () { return *cur; }
    };

    class const_iterator {
    private: T* cur;
    public:
        const_iterator() {}
        const_iterator(T* value) :cur(value) {}

        T& operator+ (short n) { return *(cur + n); }
        T& operator- (short n) { return *(cur - n); }
        T& operator++ () { return *(++cur); }
        T& operator-- () { return *(--cur); }
        bool operator!= (const const_iterator& rhs) { return cur != rhs.cur; }
        bool operator== (const const_iterator& rhs) { return cur == rhs.cur; }
        const T& operator* () { return *cur; }
    };

    class reverse_iterator {
    private: T* cur;
    public:
        reverse_iterator() {}
        reverse_iterator(T* value) :cur(value) {}
        T& operator+ (short n) { return *(cur - n); }
        T& operator- (short n) { return *(cur + n); }
        T& operator++ () { return *(--cur); }
        T& operator-- () { return *(++cur); }
        bool operator!= (const reverse_iterator& rhs) { return cur != rhs.cur; }
        bool operator== (const reverse_iterator& rhs) { return cur == rhs.cur; }
        T& operator* () { return *cur; }
    };

    void reserve(short newCapacity) {

        if (newCapacity <= capacity) return;

       T *newarr = new T[newCapacity];

        for (i = 0; i < size; ++i)
            new(newarr + i) T(arr[i]);

        try {
            for (i = 0; i < size; ++i)
                new(newarr + i) T(arr[i]);
        }
        catch (...) {
            for (short j = 1; j < i; ++j)
                (newarr + j)->~T();
            delete[] newarr;
            throw;
        }

        for (i = 0; i < size; ++i)
            (arr + i)->~T();

        //delete[] arr;

        arr = newarr;
        capacity = newCapacity;
    }

    void resize(short newSize, T value) {
        if (newSize >= capacity) reserve(newSize * 2);

        for (i = size; i < newSize; ++i)
            new(arr + i) T(value);
        size = newSize;
    }

    void resize(short newSize) {
        if (newSize > size) return resize(newSize, T());
        size = newSize;
    }

    void assign(iterator First, iterator Last) {

        short newSize = 0, position_to_start = 0;

        for (; arr[position_to_start] != *First; ++position_to_start);

        for (iterator it = First; it != Last; ++it, ++newSize);

        if (newSize == 0) return clear();

        T* newarr = reinterpret_cast<T*>(new __int8[capacity * sizeof(T)]);

        try {
            for (short j = 0, i = position_to_start; j < newSize; ++i, ++j)
                new(newarr + j) T(arr[i]);
        }
        catch (...) {
            for (short j = 0; j < i; ++j)
                (newarr + j)->~T();
            delete[] reinterpret_cast<__int8*>(newarr);
            throw;
        }

        for (i = 0; i < size; ++i)
            (arr + i)->~T();
        delete[] reinterpret_cast<__int8*>(arr);

        arr = newarr;
        size = newSize;

    }

    void push_back(const T value = T()) {
        if (capacity == size) reserve(2 * size);

        new(arr + size) T(value);
        ++size;
    }

    void erase(short position) {

        if (size == 0 || position >= size || position < 0)
            return;

        if (position == size - 1) return pop_back();

        T *newarr = new T[capacity-1];

        short j = 0;

         for (i = 0; i < size; ++i)
             if (i != position) {
                 new(newarr + j) T(arr[i]);
                 ++j;
             }

         for (i = 0; i < size; ++i)
             (arr + i)->~T();

         arr = newarr;

        --size;
    }

    void erase(short position, short amount) {
        if (size == 0 || amount > size || amount < 0
            || position < 0 || position >= size)
            return;

        if (!amount) return;
        if (amount == 1) return erase(position);



        T* newarr = reinterpret_cast<T*>(new __int8[capacity * sizeof(T) - amount]);
        short j = 0;
        try {
            for (i = 0; i < size; ++i) {
                if (i == position) i += amount;
                new(newarr + j) T(arr[i]);
                ++j;
            }
        }
        catch (...) {
            for (short k = 0; k < j; ++k)
                (newarr + k)->~T();
            delete[] reinterpret_cast<__int8*>(newarr);
            throw;
        }
        for (i = 0; i < size; ++i)
            (arr + i)->~T();
        delete[] reinterpret_cast<__int8*>(arr);
        arr = newarr;
        size -= amount;
    }

    iterator emplace_back(const T value = T()) {
        if (size == capacity) reserve(2 * size);
        return iterator(new(arr + size++)T(value));
    }

    inline void pop_back() {

        if (size == 0)
            return;
        --size;
        (arr + size)->~T();
    }

    inline void clear() {
        for (i = 0; i < size; ++i)
            (arr + i)->~T();
        size = 0;
    }

    inline void shrink_to_fit() {
        if (capacity == size) return;
        for (i = size; i < capacity; ++i)
            (arr + i)->~T();
        capacity = size;
    }

    void insert(const short position, const T value = T()) {
        if (position < 0 || position > size)
            return;

        if (position == size) return push_back(value);
        if (size == capacity) reserve(size * 2);

        for (i = size; i >= position; --i)
            arr[i] = arr[i - 1];

        arr[position] = value;
        ++size;
    }

    void insert(iterator position, const T value = T()) {
        short int_position = 0;
        for (Vector<T>::iterator it = begin(); it != position; ++it)
            ++int_position;
        insert(position, value);
    }

   /* iterator emplace(const short position, const T value = T()) {
        if (position < 0 || position > size)
            return;

        if (position == size) return emplace_back(value);
        if (size == capacity) reserve(size * 2);

        for (i = size; i >= position; --i)
            arr[i] = arr[i - 1];

        ++size;

        return new(arr + position)T(value);
    }

    iterator emplace(iterator position, const T value = T()) {
        short int_position = 0;
        for (Vector<T>::iterator it = begin(); it != position; ++it)
            ++int_position;
        return emplace(int_position, value);
    }

    void insert(short position, short amount, const T value = T()) {
        if (position < 0 || position > size || amount < 0)
            return;

        for (amount; amount > 0; --amount, ++position)
            insert(position, value);
    }

    void insert(iterator position, short amount, const T value = T()) {
        short int_position = 0;
        for (Vector<T>::iterator it = begin(); it != position; ++it)
            ++int_position;
        if (int_position < 0 || int_position > size || amount < 0)
            return;

        for (amount; amount > 0; --amount, ++int_position)
            insert(int_position, value);
    }

    iterator emplace(short position, short amount, const T value = T()) {
        if (position < 0 || position > size || amount < 0)
            return;

        for (amount; amount > 0; --amount, ++position)
            emplace(position, value);
        return arr + position;
    }

    iterator emplace(iterator position, short amount, const T value = T()) {
        short int_position = 0;
        for (Vector<T>::iterator it = begin(); it != position; ++it)
            ++int_position;
        if (int_position < 0 || int_position > size || amount < 0)
            return;

        for (amount; amount > 0; --amount, ++int_position)
            emplace(int_position, value);
        return arr + int_position;
    }*/

    T& operator= (const Vector& rhs) {
        T* newarr = reinterpret_cast<T*>(new __int8[rhs.Capacity() * sizeof(T)]);
        try {
            for (i = 0; i < rhs.Size(); ++i) {
                new(newarr + i) T(rhs.arr[i]);
            }
        }
        catch (...) {
            for (short j = 0; j < i; ++j)
                (newarr + j)->~T();
            delete[] reinterpret_cast<__int8*>(newarr);
            throw;
        }
        for (i = 0; i < size; ++i)
            (arr + i)->~T();
        delete[] reinterpret_cast<__int8*>(arr);
        arr = newarr;
        size = rhs.Size();
    }

    void swap(Vector& rhs) {

        Vector<T> lhs;
        for (i = 0; i < size; ++i)
            lhs.push_back(arr[i]);

        Vector<T> temp;
        for (i = 0; i < rhs.Size(); ++i)
            temp.push_back(rhs.arr[i]);

        rhs = lhs;
        lhs = temp;

        T* newarr = reinterpret_cast<T*>(new __int8[lhs.Capacity() * sizeof(T)]);
        try {
            for (i = 0; i < lhs.Size(); ++i) {
                new(newarr + i) T(lhs[i]);
            }
        }
        catch (...) {
            for (short j = 0; j < i; ++j)
                (newarr + j)->~T();
            delete[] reinterpret_cast<__int8*>(newarr);
            throw;
        }
        for (i = 0; i < size; ++i)
            (arr + i)->~T();
        delete[] reinterpret_cast<__int8*>(arr);
        arr = newarr;
        size = lhs.Size();
    }

    void sort() {
        int j, step;
        T tmp;
        for (step = size / 2; step > 0; step /= 2)
            for (i = step; i < size; i++) {
                tmp = arr[i];
                for (j = i; j >= step; j -= step)
                    if (tmp < arr[j - step]) arr[j] = arr[j - step];
                    else break;

                arr[j] = tmp;
            }
    }

    bool operator == (const Vector& rhs) const {
        if (size != rhs.size) return false;
        for (int j = 0; j < size; ++j)
            if (arr[j] != rhs[j]) return false;
        return true;
    }

    bool operator != (const Vector& rhs) const {
        return !(*this == rhs);
    }

    inline bool empty() {
        return !size; //return size == 0
    }

    inline const unsigned long long& max_size() const {
        return pow(2, 64) / sizeof(T) - 1;
    }

    inline const short& Size() const {
        return size;
    }

    inline const short& Capacity() const {
        return capacity;
    }

    inline T& front() {
        if (size == 0)
            return T();
        return arr[0];
    }

    inline T& back() {
        if (size == 0)
            return T();
        return arr[size - 1];
    }

    inline T& operator[] (short index) {

        return arr[index];
    }

    inline T& at(short index) {

        if (index >= size || index < 0) {

            T value = T();
            return value;
        }
        return arr[index];
    }

    inline iterator begin() {
        return iterator(arr);
    }

    inline const const_iterator begin() const {
        return const_iterator(arr);
    }

    inline const const_iterator cbegin() const {
        return const_iterator(arr);
    }

    inline const reverse_iterator crbegin() const {
        return reverse_iterator(arr + size - 1);
    }

    inline iterator end() {
        return iterator(arr + size);
    }

    inline const const_iterator end() const {
        return const_iterator(arr + size);
    }

    inline const const_iterator cend() const {
        return const_iterator(arr + size);
    }

    inline const reverse_iterator crend() const {
        return reverse_iterator(arr);
    }

    bool isEmpty() const {
        return !size;
    }

    const unsigned Size() {
        return size;
    }

};

#endif // VECTOR_H




