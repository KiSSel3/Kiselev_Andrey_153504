#ifndef BitSet_H
#define BitSet_H

#include <iostream>

template<size_t N>
class BitSet
{
private:
    unsigned char arr[(N + 7) / 8];

public:
    class reference{
        friend class bitset;
        unsigned char &value;
        size_t pos;

        reference(unsigned char &value, size_t pos) : value(value), pos(pos){}

    public:
        reference &operator=(bool x){
            x ? value |= (1 << pos) : value &= ~(1 << pos);
            return *this;
        }

        operator bool(){
            return (value & (1 << pos)) != 0;
        }
    };

    BitSet(){
        for(int i = 0 ; i < (N+7) / 8 ; i++){
            arr[i] = 0 ;
        }
    };

    bool operator[](size_t pos) const {
        return (arr[pos/8] & ( 1 << (pos%8))) != 0;
    }

    reference operator[](size_t pos){
        return reference(arr[N / 8], pos % 8);
    }

    bool All() const{
        for(int i = 0; i < N; ++i){
            if((arr[i / 8] & (1 << (i % 8))) == 0){
                return false;
            }
        }
        return true;
    }

    bool Any() const{
        for(int i = 0; i < N; ++i){
            if((arr[i / 8] & (1u << (i % 8))) != 0){
                return true;
            }
        }
        return false;
    }

    bool None() const{
        for(int i = 0; i < N; ++i){
            if((arr[i / 8] & (1u << (i % 8))) != 0){
                return false;
            }
        }
        return true;
    }

    size_t Count() const{
        size_t res = 0;
        for(int i = 0; i < N; ++i){
            if((arr[i / 8] & (1u << (i % 8))) != 0){
                ++res;
            }
        }
        return res;
    }

    BitSet &Set(){
        for(int i = 0; i < N; ++i){
            arr[i / 8] |= (1u << (i % 8));
        }

        return *this;
    }
    BitSet &Set(size_t pos){
        arr[pos / 8] |= (1u << (pos % 8));
        return *this;
    }

    BitSet &Reset(){
        for(int i = 0; i < N; ++i){
            arr[i / 8] &= ~(1 << (i % 8));
        }

        return *this;
    }

    BitSet &Reset(size_t pos){
        arr[pos / 8] &= ~(1u << (pos % 8));
        return *this;
    }

    BitSet &Flip(){
        for(int i = 0; i < N; ++i){
            arr[i / 8] ^= (1u << (i % 8));
        }
        return *this;
    }

    BitSet &Flip(size_t pos){
        arr[pos / 8] ^= (1u << (pos % 8));
        return *this;
    }

    bool Test(size_t pos) const{
        return (arr[pos / 8] & (1u << (pos % 8))) != 0;
    }


    std::string To_String() const {
        std::string res;
        for(int i = 0; i < N; ++i) {
            res += Test(N - i - 1) ? "1" : "0";
        }
        return res;
    }

    unsigned long long To_Ullong() const{
        unsigned long long res = 0;

        for(int i = 0; i < (N + 7) / 8; ++i){
            res |= arr[i];
        }

        return res;
    }

    unsigned long To_Ulong() const{
        unsigned long res = 0;

        for(int i = 0; i < (N + 7) / 8; ++i){
            res |= arr[i];
        }

        return res;
    }

    size_t Size() const{
        return N;
    }

    friend BitSet operator~(const BitSet &bts){
        BitSet res;
        for(int i = 0; i < (N + 7) / 8; ++i){
            res.arr[i] = ~bts.arr[i];
        }
        return res;
    }

    friend BitSet operator&(const BitSet &lBts, const BitSet &rBts){
        BitSet res;
        for(int i = 0; i < (N + 7) / 8; ++i){
            res.arr[i] = lBts.arr[i] & rBts.arr[i];
        }
        return res;
    }

    friend BitSet operator|(const BitSet &lBts, const BitSet &rBts){
        BitSet res;
        for(int i = 0; i < (N + 7) / 8; ++i){
            res.arr[i] = lBts.arr[i] | rBts.arr[i];
        }
        return res;
    }
};

#endif // BitSet_H
