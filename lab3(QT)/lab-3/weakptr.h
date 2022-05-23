#ifndef WEAKPTR_H
#define WEAKPTR_H
#include "sharedptr.h"

template<class T>
class sharedPtr;

template<class T>
class weakPtr
{
private:
    T* ptr = nullptr;
    int* count =  nullptr;
    int* countWeak = nullptr;

public:
    friend class sharedPtr<T>;

    weakPtr(T* ptr = nullptr) : ptr(ptr), count(new int(0)), countWeak(new int(1)) {}

    weakPtr(const weakPtr<T>& other) : ptr(other.ptr), count(other.count), countWeak(other.countWeak) {
        if (ptr == nullptr)
            return;

        ++*countWeak;
    }

    weakPtr(sharedPtr<T>& other) : ptr(other.ptr), count(other.count), countWeak(other.countWeak) {
        if (ptr == nullptr)
            return;

        ++*countWeak;
    }

    void reset(T* ptr) {
        if (this->ptr == nullptr || this->countWeak == nullptr)
            return;

        delete this->countWeak;
        delete this->ptr;

        this->countWeak = 1;
        this->ptr = ptr;

    }

    bool expired() {
        if (ptr == nullptr || countWeak == nullptr)
            return true;
        else
            return false;
    }

    void swap(weakPtr<T>& ptr) {
        T* tmp = this->ptr;
        this->ptr=  ptr.ptr;
        ptr.ptr = tmp;
    }

    int use_count() const noexcept
    {
        return *count;
    }

    sharedPtr<T> lock() {
        sharedPtr<T>* tmp = new sharedPtr<T>;
        if (*(this->countWeak)){
            tmp->ptr = this->ptr;
            tmp->count = this->count;
            tmp->countWeak = this->countWeak;

            ++(*(tmp->count));
        }

        return *tmp;
    }

    weakPtr& operator=(weakPtr<T>&& other) noexcept
    {
        ptr = other.ptr;
        count = other.count;

        return *this;
    }

    operator bool() const noexcept
    {
        return static_cast<bool>(ptr);
    }

    ~weakPtr() {
        if (ptr == nullptr || countWeak == nullptr)
            return;

        if (*countWeak > 0) {
            --*countWeak;
            return;
        }

        delete ptr;
        delete count;
        delete countWeak;
    }
};

#endif // WEAKPTR_H
