#ifndef UNIQUEPTR_H
#define UNIQUEPTR_H

template<class T>
class uniquePtr;

template<class T>
class uniquePtr
{
private:
    T* ptr;

    template<typename U, typename ...Args>
    friend uniquePtr<U> make_shared(Args&& ... args);

public:
    uniquePtr(T* ptr = nullptr) : ptr(ptr) {}
    uniquePtr (uniquePtr&& other) : ptr(other.release()) {}

    void reset(T* ptr = nullptr) noexcept {
        delete this->ptr;
        this->ptr = ptr;
    }

    T* release() noexcept {
        T* tmp = ptr;
        ptr = nullptr;
        return tmp;
    }

    void swap(uniquePtr& ptr){
        T* tmp = this->ptr;
        this->ptr = ptr.ptr;
        ptr.ptr = tmp;
    }

    T* get() const {
        return ptr;
    }

    T* operator->() const {
        return ptr;
    }

    T& operator*() const {
        return *ptr;
    }

    uniquePtr& operator=(uniquePtr&& other) noexcept {
        reset(other.release());
        return* this;
    }

    operator bool() const noexcept {
        return static_cast<bool>(ptr);
    }

    ~uniquePtr() {
       delete ptr;
    }
};

#endif // UNIQUEPTR_H
