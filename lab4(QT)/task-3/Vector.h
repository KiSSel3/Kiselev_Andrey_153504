#ifndef Vector_H
#define Vector_H

#include <limits>
#include<iostream>
template <class T>
class MyVector
{
public:
    explicit MyVector();
    MyVector(int size, const T &defaultElement);
    MyVector(int size);
    MyVector(const MyVector &copyMyVector);
    MyVector(MyVector &&moveMyVector);
    MyVector(const std::initializer_list<T> &Iterator);
    ~MyVector();
    void assign(const int& newSize, const T& element);
    T &at(int index);
    T &back();
    int capacity() const noexcept;
    void clear();
    T* data();
    void emplace(const int& insertPosition,T &&insertElement);
    void emplace_back(T &&element);
    bool empty();
    void erase(const int& erasePosition);
    T& front();
    void insert(const int& insertPosition,const T& insertElement);
    int max_size();
    void pop_back();
    void print();
    void push_back(const T &addElement);
    void reserve(const int &capacity);
    void resize(const int& newSize);
    int size() const noexcept;
    void swap(MyVector &rhs);
    void swap(MyVector &&rhs);

    T& operator[](const int& index);
    T& operator[](const int& index)const;

    class Iterator{
    public:
        Iterator(T *ptr): _ptr(ptr){};
        ~Iterator(){};
        bool operator == (const Iterator& rhs) const
        {
            return _ptr == rhs._ptr;
        };

        bool operator != (const Iterator& rhs) const
        {
            return !(*this == rhs);
        };

        Iterator& operator = (const Iterator &rhs)
        {
            _ptr = rhs._ptr;
        };

        T& operator*() const
        {
            return *_ptr;
        };

        T* operator->()
        {
            return _ptr;
        };

        T* operator&()
        {
            return _ptr;
        };

        Iterator& operator++()
        {
            _ptr++;
            return *this;
        }

        Iterator& operator--()
        {
            _ptr++;
            return *this;
        }

    private:
        T *_ptr = nullptr;
    };

    Iterator const cbegin() const noexcept;
    Iterator const cend() noexcept;
    Iterator const crbegin() const noexcept;
    Iterator const crend() const noexcept;
    Iterator begin() noexcept;
    Iterator end();
    Iterator rbegin();
    Iterator rend();

private:
    void checkMemory();
    T *_MyVector;
    int _size;
    int _capacity;
};

template<class T>
MyVector<T>::MyVector() : _size(0),  _capacity(1)
{
    _MyVector = new T[_capacity];
}

template<class T>
MyVector<T>::MyVector(int size, const T &defaultElement): _size(size),  _capacity(_size + 1)
{
    _MyVector = new T[_capacity];

    for(int i = 0 ; i< _size ; i++){
        _MyVector[i] = defaultElement;
    }
}

 template<class T>
MyVector<T>::MyVector(int size): _size(size),  _capacity(_size + 1)
{
    _MyVector = new T[_capacity];

    for(int i = 0 ; i< _size ; i++){
        _MyVector[i] = 0;
    }
}

template<class T>
MyVector<T>::MyVector(const MyVector &copyMyVector) : _size(copyMyVector._size),_capacity(copyMyVector._capacity)
{
    _MyVector = new T[_capacity];

    for(int i = 0; i < _size;i++){
        _MyVector = copyMyVector._MyVector[i];
    }
}

template<class T>
MyVector<T>::MyVector(MyVector &&moveMyVector) : _size(moveMyVector._size),_capacity(moveMyVector._capacity)
{
    _MyVector = new T[_capacity];

    for(int i = 0; i < _size; i++){
        _MyVector = moveMyVector._MyVector[i];
    }
}

template<class T>
MyVector<T>::MyVector(const std::initializer_list<T> &Iterator): _size(Iterator.size()),_capacity(_size + 1)
{
    _MyVector = new T[_capacity];
    int index = 0;

    for(auto i = Iterator.begin(); i < Iterator.end();i++){
        _MyVector[index++] = *i;
    }
}

template<class T>
MyVector<T>::~MyVector()
{
    delete _MyVector;
}


template<class T>
void MyVector<T>::assign(const int& newSize, const T& element)
{
    delete _MyVector;

    _size = newSize;
    _capacity = _size + 1;
    _MyVector = new T[_capacity];

    for(int i = 0 ; i < _size; i++){
        _MyVector[i] = element;
    }
}

template<class T>
T &MyVector<T>::at(int index)
{
    return _MyVector[index];
}

template<class T>
T &MyVector<T>::back()
{
    return _MyVector[_size - 1];
}

template<class T>
class MyVector<T>::Iterator MyVector<T>::begin()noexcept
{
    return &_MyVector[0];
}

template<class T>
int MyVector<T>::capacity() const noexcept
{
    return _capacity;
}


template<class T>
class MyVector<T>::Iterator const MyVector<T>::cbegin() const noexcept
{
    if(_size == 0)
        return nullptr;
    return Iterator(_MyVector[0]);
}

template<class T>
class MyVector<T>::Iterator const MyVector<T>::cend() noexcept
{
    if(_size == 0)
        return nullptr;
    return Iterator(_MyVector[_size]);
}

template<class T>
void MyVector<T>::clear()
{
    _size = 0;
    _capacity = 1;

    delete _MyVector;

    _MyVector = new T[_capacity];
}

template<class T>
T* MyVector<T>::data()
{
    if(_size == 0)
        return nullptr;
    return _MyVector[0];
}

template<class T>
void MyVector<T>::emplace(const int& insertPosition,T &&insertElement)
{
    if(insertPosition < _size - 1){
        if(_size >= _capacity - 1){
            _capacity *= 3.0/2;
        }

        T* tmp = _MyVector;
        _MyVector = new T[_capacity];
        int currentIndex = 0;

        for(int i = 0; i < _size; i++){
            if(i == insertPosition){
                _MyVector[currentIndex++] = std::move(insertElement);
            }
            _MyVector[currentIndex++] = std::move(tmp[i]);
        }

        _size++;
        delete[] tmp;
    }
}

template<class T>
void MyVector<T>::emplace_back(T &&insertElement)
{
    checkMemory();
    _MyVector[_size++] = std::move(insertElement);
}

template<class T>
bool MyVector<T>::empty()
{
    return !_size;
}

template<class T>
class MyVector<T>::Iterator MyVector<T>::end()
{
    if(_size == 0)
        return nullptr;
    return &_MyVector[_size];
}

template<class T>
void MyVector<T>::erase(const int& erasePosition)
{
    if(erasePosition <= _size - 1){
        T* tmp = _MyVector;

        _MyVector = new T[_capacity];
        int currentIndex = 0;

        for(int i = 0; i < _size; i++){
            if(i == erasePosition)
                continue;
            _MyVector[currentIndex++] = tmp[i];
        }

        _size--;
        delete[] tmp;
    }
}

template<class T>
T &MyVector<T>::front()
{
    return _MyVector[0];
}

template<class T>
void MyVector<T>::insert(const int& insertPosition,const T& insertElement)
{
    if(insertPosition < _size - 1){
        if(_size >= _capacity - 1){
            _capacity *= 3.0/2;
        }

        T* tmp = _MyVector;
        _MyVector = new T[_capacity];
        int currentIndex = 0;

        for(int i = 0; i < _size; i++){
            if(i == insertPosition){
                _MyVector[currentIndex++] = insertElement;
            }
            _MyVector[currentIndex++] = tmp[i];
        }

        _size++;
        delete[] tmp;
    }

}

template<class T>
void MyVector<T>::pop_back()
{
    if(_size == 0 )
        return;
    --_size;
}

template<class T>
void MyVector<T>::print()
{
    for(int i = 0; i < _size; i++){
    }


    for(int i = _size; i < _capacity; i++){
    }
}

template<class T>
void MyVector<T>::push_back(const T &addElement)
{
    checkMemory();
    _MyVector[_size++] = addElement;
}

template<class T>
class MyVector<T>::Iterator MyVector<T>::rbegin()
{
    if(_size == 0)
        return nullptr;
    return _MyVector[_size];
}

template<class T>
class MyVector<T>::Iterator MyVector<T>::rend()
{
    if(_size == 0)
        return nullptr;
    return _MyVector[0];
}

template<class T>
void MyVector<T>::reserve(const int &capacity)
{
    T* tmp = _MyVector;

    _capacity = capacity;
    _size = _capacity - 1;
    _MyVector = new T[_capacity];

    for(int i = 0; i < _size; i++){
        _MyVector[i] = tmp[i];
    }

    delete[] tmp;

}

template<class T>
void MyVector<T>::resize(const int &newSize)
{
    if(newSize == _size){
        return;
    }
    else if(newSize < _size){
        for(int i = _size - 1;i > newSize - 1; i--){
            _MyVector[i] = 0;
        }
    }
    else{
        T* tmp = _MyVector;

        _capacity = newSize;
        _MyVector = new T[_capacity];

        for(int i = 0; i < _size; i++){
            _MyVector[i] = tmp[i];
        }

        delete[] tmp;
        for(int i = newSize - 1;i > _size; i--){
            _MyVector[i] = 0;
        }
    }
    _size = newSize;
}

template<class T>
int MyVector<T>::size() const noexcept
{
    return _size;
}
template<class T>
int MyVector<T>::max_size()
{
    return std::numeric_limits<T>::max();
}

template<class T>
void MyVector<T>::swap(MyVector &rhs)
{
    qSwap(_MyVector,rhs._MyVector);
    qSwap(_size,rhs._size);
    qSwap(_capacity,rhs._capacity);
}

template<class T>
void MyVector<T>::swap(MyVector &&rhs)
{
    qSwap(_MyVector,rhs._MyVector);
    qSwap(_size,rhs._size);
    qSwap(_capacity,rhs._capacity);
}

template<class T>
T &MyVector<T>::operator[](const int &index)
{
    return _MyVector[index];
}
template<class T>
T &MyVector<T>::operator[](const int &index) const
{
    return _MyVector[index];
}


template<class T>
void MyVector<T>::checkMemory()
{
    if(_size >= _capacity - 1){
        T* tmp = _MyVector;

        _capacity *= 2;
        _MyVector = new T[_capacity];
        for(int i = 0; i < _size; i++){
            _MyVector[i] = tmp[i];
        }

        delete[] tmp;
    }
}

#endif // Vector_H
