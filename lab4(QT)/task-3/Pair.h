#ifndef Pair_H
#define Pair_H

#include <iostream>
template<class A, class B>
struct Pair
{
    A first;
    B second;

    Pair() : first(), second() { }

    Pair(const A& a, const B& b) : first(a), second(b) { }

    template<class AA, class BB>
    Pair(const Pair<AA, BB>& p) : first(p.first), second(p.second) { }

    Pair& operator =(const Pair& p)
    {
        first = std::move(p.first);
        second = std::move(p.second);
        return *this;
    }

    template<class AA, class BB>
    Pair& operator =(const Pair<AA, BB>& p)
    {
        first = std::move(p.first);
        second = std::move(p.second);
        return *this;
    }

    void swap(Pair& p)
    {
        std::swap(first, p.first);
        std::swap(second, p.second);
    }

    template<class AA, class BB>
    void swap(Pair<AA, BB>& p)
    {
        first = std::move(p.first);
        second = std::move(p.second);
    }

    void make_Pair(A x, B y)
    {
        first = x;
        second = y;
    }
};
#endif // Pair_H

