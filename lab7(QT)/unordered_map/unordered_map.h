#ifndef UNORDERED_MAP_H
#define UNORDERED_MAP_H

#include<iostream>
#include<QApplication>

using namespace std;

template<class T>
class UnorderedMap{
public:
    UnorderedMap();
    ~UnorderedMap();
    void insert(pair<int,T> newData);
    void insert(int newData,T data);
    void remove(int key);
    void swap(int firstKey, int secondKey);
    void clear();
    bool contains(int key);

    T& operator[](int key);

private:
    struct Node{
        Node(){};
        Node(pair<int,T> newData): data(newData){};
        pair<int,T> data;
        Node* next =nullptr;
    };

    void resize();
    void rehash();
    int hash(int key);

    int _count = 0;
    int _arrSize = 20;

    Node* _arr = new Node[20];
};


template<class T>
UnorderedMap<T>::UnorderedMap()
{

}

template<class T>
UnorderedMap<T>::~UnorderedMap()
{
    delete[] _arr;
}

template<class T>
void UnorderedMap<T>::insert(pair<int, T> newData)
{
    Node* record = _arr[hash(newData.first)].next;

    if(record == nullptr){
        _arr[hash(newData.first)].next = new Node(newData);
        ++_count;
        return ;
    }

    while(record->next){
        if(record->data.first == newData.first){
            record->data = newData;
            return;
        }
        record = record->next;
    }

    record->next = new Node(newData);
    ++_count;

    if(_count == _arrSize)
        resize();
}

template<class T>
void UnorderedMap<T>::insert(int key, T newData)
{
    for(int i = 0 ; i < _arrSize; i++){
        if(_arr[i].next != nullptr)
            qDebug() << _arr[i].next->data;
        else
            qDebug() << "nullptr";
    }
    qDebug() << "";
    qDebug() <<_count;
    qDebug() << "";

    Node* record = _arr[hash(key)].next;

    if(record == nullptr){
        _arr[hash(key)].next = new Node(pair<int,T>(key, newData));
        ++_count;
        return ;
    }

    while(record->next){
        if(record->data.first == key){
            record->data.second = newData;
            return;
        }
        record = record->next;
    }

    record->next = new Node(pair<int,T>(key, newData));
    ++_count;

    if(_count >= _arrSize){
        resize();
        qDebug() << "im resize";
    }
}

template<class T>
void UnorderedMap<T>::remove(int key)
{
    qDebug() << key;
    Node firstRecord = _arr[hash(key)];
    Node* tmp;
    Node* record;

    if(firstRecord.next == nullptr){
        return ;
    }
    record = firstRecord.next;

    if(firstRecord.next->data.first == key){
        tmp = firstRecord.next;
        firstRecord.next = firstRecord.next->next;
        delete tmp;
        --_count;
        return ;
    }

    while(record->next){
        if(record->next->data.first == key){
            tmp = record->next;
            record->next = record->next->next;

            delete tmp;
            --_count;

            for(int i = 0 ; i < _arrSize; i++){
                if(_arr[i].next != nullptr)
                    qDebug() << _arr[i].next->data;
                else
                    qDebug() << "nullptr";
            }
            qDebug() << "";
            qDebug() <<_count;
            qDebug() << "";

            return;
        }
        record = record->next;
    }

    qDebug() << "Element not found";
}

template<class T>
void UnorderedMap<T>::swap(int firstKey, int secondKey)
{
    Node* firstRecord = _arr[hash(firstKey)].next;
    Node* secondRecord = _arr[hash(secondKey)].next;

    while(firstRecord->next){
        if(firstRecord->data.first == firstKey){
            break;
        }
        firstRecord = firstRecord->next;
    }

    while(secondRecord->next){
        if(secondRecord->data.first == secondKey){
            break;
        }
        secondRecord = secondRecord->next;
    }

    qSwap(firstRecord->data,secondRecord->data);

}

template<class T>
void UnorderedMap<T>::clear()
{
    delete []_arr;
    _arrSize = 0;
    _count = 0;
    _arr = new Node[20];
}

template<class T>
bool UnorderedMap<T>::contains(int key)
{
    Node* record = _arr[hash(key)].next;

    while(record){
        if(record->data.first == key){
            return true;
        }
        record = record->next;
    }

    return false;
}

template<class T>
void UnorderedMap<T>::resize()
{
    int tmpSize = _arrSize;
    _arrSize *= 2;
    _count = 0;

    Node* arrTmp = _arr;
    _arr = new Node[_arrSize];

    for(int i = 0; i < tmpSize ; i++){
        Node* record = arrTmp[i].next;
        if(record == nullptr){
            continue;
        }
        while(record){
            insert(record->data);
            record = record->next;
        }
    }

    delete arrTmp;
}

template<class T>
T& UnorderedMap<T>::operator[](int key){
    Node* record = _arr[hash(key)].next;

    if (contains(key)) {
        Node* record = _arr[hash(key)].next;

        while(record){
            if(record->data.first == key){
                return record->data.second;
            }
            record = record->next;
        }
    }
    else {
        insert(key, T());
        Node* record = _arr[hash(key)].next;

        while(record){
            if(record->data.first == key){
                return record->data.second;
            }
            record = record->next;
        }
    }
};

template<class T>
int UnorderedMap<T>::hash(int key)
{
    const double V = 0.618033;

    double tmp = abs(key) * V;
    tmp = tmp - int(tmp);
    return int(_arrSize * tmp);
}

#endif // UNORDERED_MAP_H
