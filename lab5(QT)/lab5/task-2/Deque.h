#pragma once

#include <inttypes.h>

template <typename T>
class deque {
private:
    T** arr;
    size_t cup;
    size_t top_index;
    size_t bottom_index;
    size_t sub_top_index;
    size_t sub_bottom_index;

    void addMemory() {
        this->cup *= 3;
        int k = top_index;
        size_t tmp = bottom_index - top_index;
        top_index = cup / 3;
        bottom_index = top_index + tmp;
        T** newArr = new T * [cup];
        for (int i = top_index; i <= bottom_index; i++) {
            new(newArr + i)T* (arr[k]);
            k++;
        }
        delete[] arr;
        arr = newArr;
    }

public:
    deque() {
        this->cup = 11;
        this->arr = new T * [cup];
        this->bottom_index = cup / 2;
        this->top_index = this->bottom_index - 1;
        this->sub_top_index = 9;
        this->sub_bottom_index = 0;
        for (int i = top_index; i <= bottom_index; i++) {
            T* sub_arr = new T[10];
            new(arr + i)T* (sub_arr);
        }
    }

    ~deque() {
        for (int i = top_index; i <= bottom_index; i++) {
            delete[] arr[i];
            arr[i] = nullptr;
        }
        delete[] arr;
        arr = nullptr;
    }

    void push_back(T item) {
        if (sub_bottom_index == 10) {
            if (bottom_index == cup - 2) {
                addMemory();
            }

            bottom_index++;
            T* sub_arr = new T[10];
            T* sub_arr_second = new T[10];
            arr[bottom_index] = sub_arr;
            arr[bottom_index + 1] = sub_arr_second;
            sub_bottom_index = 0;
        }

        arr[bottom_index][sub_bottom_index++] = item;
    }

    void push_front(T item) {
        if (sub_top_index == -1) {
            if (top_index == 1) {
                addMemory();
            }

            top_index--;
            T* sub_arr = new T[10];
            T* sub_arr_second = new T[10];
            arr[top_index] = sub_arr;
            arr[top_index - 1] = sub_arr_second;
            sub_top_index = 9;
        }

        arr[top_index][sub_top_index--] = item;
    }

    template <typename ... Args>
    void emplace_back(Args&& ...args) {
        T element = T(std::forward<Args>(args)...);

        push_back(element);
    }

    template <typename ... Args>
    void emplace_front(Args&& ...args) {
        T element = T(std::forward<Args>(args)...);

        push_front(element);
    }

    void pop_back() {
        if (sub_bottom_index == 0) {
            sub_bottom_index = 9;
            bottom_index--;
        }
        else {
            sub_bottom_index--;
        }
    }

    void pop_front() {
        if (sub_top_index == 9) {
            sub_top_index = 0;
            top_index++;
        }
        else {
            sub_top_index++;
        }
    }

    T& operator[](const int& index) const {
        int i = top_index;
        int j = sub_top_index;
        for (int u = 0; u <= index; u++) {
            if (j == 9) {
                j = 0;
                i++;
                continue;
            }
            j++;
        }

        return arr[i][j];
    }

    T& at(const int& index) {
        int i = top_index;
        int j = sub_top_index;
        for (int u = 0; u <= index; u++) {
            if (j == 9) {
                j = 0;
                i++;
                continue;
            }
            j++;
        }

        return arr[i][j];
    }


    size_t size() const {
        size_t res = 0, tmp = 0;
        tmp = bottom_index - top_index - 1;

        if (tmp) {
            res += (tmp * 10);
        }

        res += ((10 - sub_top_index - 1) + sub_bottom_index);

        return res;
    }

    void resize(size_t count, T value = T()) {
        if (size() < count) {
            size_t dif = count - size();
            for (size_t i = 0; i < dif; i++) {
                push_back(value);
            }
        } else if (size() > count) {
            size_t dif = size() - count;
            for (size_t i = 0; i < dif; i++) {
                pop_back();
            }
        }
    }

    void clear() {
        while (size()) {
            pop_front();
        }
    }

    size_t max_size() const {
        return this->cup * 10;
    }

    bool empty() const {
        return !size();
    }

    class Iterator {
    private:
        T** cur;
        size_t sub_index;

    public:
        Iterator(T** line, size_t index) {
            this->sub_index = index;
            this->cur = line;
        }

        T& operator+=(int n) {
            int l = n / 10;
            int p = n % 10;
            cur += l;

            if (sub_index + p > 9) {
                cur++;
                sub_index = (sub_index + p) % 10;
            }
            else {
                sub_index += p;
            }

            return *(*(cur)+sub_index);
        }

        T& operator-=(int n) {
            int l = n / 10;
            int p = n % 10;
            cur -= l;

            if (sub_index - p < 0) {
                cur--;
                sub_index = 10 + (sub_index - p);
            }
            else {
                sub_index -= p;
            }

            return *(*(cur)+sub_index);
        }

        T& operator++(int) {
            if (sub_index == 9) {
                sub_index = 0;
                cur++;
            }
            else {
                sub_index++;
            }

            return *(*(cur) + sub_index);
        }

        T& operator--(int) {
            if (sub_index == 0) {
                sub_index = 9;
                cur--;
            }
            else {
                sub_index--;
            }

            return *(*(cur)+sub_index);
        }

        bool operator!=(const Iterator& it) { return ((*cur) + sub_index) != (*(it.cur) + it.sub_index); }
        bool operator==(const Iterator& it) { return ((*cur) + sub_index) == (*(it.cur) + it.sub_index); }

        T& operator*() { return *((*cur)+sub_index); }
    };

    Iterator front() const{
        size_t tmp = top_index, tmp_sub = sub_top_index;
        if (tmp_sub == -1) {
            ++tmp_sub;
        }
        else if (tmp_sub == 9) {
            tmp_sub = 0;
            tmp++;
        }
        else {
            tmp_sub++;
        }

        auto adress = (*(arr + tmp) + tmp_sub);

        return Iterator(arr+tmp, tmp_sub);
    }

    Iterator back() {
        size_t tmp = bottom_index, tmp_sub = sub_bottom_index;
        if (tmp_sub == 10) {
            tmp_sub--;
        }
        else if (tmp_sub == 0) {
            tmp_sub = 9;
            tmp--;
        }
        else {
            tmp_sub--;
        }

        return Iterator(arr + tmp, tmp_sub);
    }




};
