#ifndef SHAREDPTR_H
#define SHAREDPTR_H

#include "weakptr.h"

template <class T>
class weakPtr;

template<class T>
class sharedPtr
{
private:
    friend class weakPtr<T>;

    T* ptr = nullptr;
    int* count =  nullptr;
    int* countWeak = nullptr;

    template<typename U, typename...Args>
    friend sharedPtr<U> make_shared(Args&&... args);

public:
    friend class weakPtr<T>;
    sharedPtr(T* ptr = nullptr) : ptr(ptr), count(new int(1)), countWeak(new int(0)) {}

    sharedPtr (const sharedPtr<T>& other) : ptr(other.ptr), count(other.count), countWeak(other.countWeak){
        if (ptr == nullptr || !(*countWeak))
            return;

        ++*count;
        ++*countWeak;
    }

    sharedPtr(sharedPtr<T>&& other) : ptr(other.ptr), count(other.count), countWeak(other.countWeak) {
        if (ptr == nullptr)
            return;

        other.ptr = nullptr;
        other.count = nullptr;
        other.countWeak = nullptr;
    }

    sharedPtr (weakPtr<T>& other) : ptr(other.ptr), count(other.count), countWeak(other.countWeak) {
        ++*count;
    }


    void reset(T* ptr = nullptr) noexcept {
        delete this->ptr;
        delete this->count;
        delete this->countWeak;

        count = new int(1);
        countWeak = new int(0);
        this->ptr = ptr;
    }

    T* release() noexcept {
        T* tmp = ptr;
        ptr = nullptr;
        return tmp;
    }

    void swap(sharedPtr& ptr){
        T* tmp = this->ptr;
        this->ptr = ptr.ptr;
        ptr.ptr = tmp;
    }

    int use_count() const noexcept
    {
        return *count;
    }

    int use_count_weak() const noexcept
    {
        return *countWeak;
    }

    T* get() const noexcept
    {
        return ptr;
    }

    T* operator->() const
    {
        return ptr;
    }

    T& operator*() const
    {
        return *ptr;
    }

    operator bool() const noexcept
    {
        return static_cast<bool>(ptr);
    }

    sharedPtr& operator=(sharedPtr<T>& other) noexcept
    {
        ptr = other.ptr;
        count = other.count;

        return *this;
    }

    ~sharedPtr(){
        if(ptr == nullptr || count == nullptr)
            return;

        if (*count>0){
            --*count;
            --*countWeak;
            return;
        }

        delete ptr;
        delete count;
        delete countWeak;
    }
};
#endif // SHAREDPTR_H
