#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Stack.h"

#include <iostream>
#include <QString>

class HashTable {
protected:
    Stack<int>* mainStack;
    size_t size;

public:
    /*void resize(size_t Size){
        size_t oldSize = size;
        size = Size;
        Stack<int>* newMainStack = new Stack<int>[size];

        for(size_t index = 0; index < oldSize;++index){
            Stack<int> indexStack = mainStack[index];
            Stack<int> newIndexStack;

            for(size_t i = 0; i < mainStack[index].Size();++i){
                newIndexStack.Push(indexStack.Top());
                indexStack.Pop();
            }
            for(size_t i = 0; i < mainStack[index].Size();++i){
                newMainStack[]Push(newIndexStack.Top());
                newIndexStack.Pop();
            }
        }


    }*/

    HashTable(size_t Size = 20){
        size = Size;
        mainStack = new Stack<int>[size];
    }

    ~HashTable(){
        delete[] mainStack;
    }

    int hashFunction(int Key){
        return (Key>0) ? Key % size: -Key % size;
    }

    void insertData(int Data){
        int index = hashFunction(Data);

        if(newValue(Data, index)){
            mainStack[index].Push(Data);
        }

    }

    bool newValue(int Data, int index){
        Stack<int> indexStack = mainStack[index];

        for(size_t i = 0;i<mainStack[index].Size();++i){
            if(Data == indexStack.Top()){
                return false;
            }
            else {
                indexStack.Pop();
            }
        }

        return true;
    }

    bool newValue(int Data){
        int index = hashFunction(Data);
        Stack<int> indexStack = mainStack[index];

        for(size_t i = 0;i<mainStack[index].Size();++i){
            if(Data == indexStack.Top()){
                return false;
            }
            else {
                indexStack.Pop();
            }
        }

        return true;
    }
    void deleteData(int Data){
        int index = hashFunction(Data);
        if(!newValue(Data,index)){
            Stack<int> indexStack = mainStack[index];
            Stack<int> newIndexStack;

            for(size_t i = 0; i<mainStack[index].Size(); ++i){
                if(Data != indexStack.Top()){
                    newIndexStack.Push(indexStack.Top());
                    indexStack.Pop();
                }
                else {
                    indexStack.Pop();
                }
            }

            for (size_t i = 0; i<mainStack[index].Size() - 1; ++i){
                indexStack.Push(newIndexStack.Top());
                newIndexStack.Pop();
            }

            mainStack[index] = indexStack;
        }
    }

    QString showHashTable(){
        QString hashTable = "";

        for(size_t index = 0; index<size;++index){
            Stack<int> indexStack = mainStack[index];
            Stack<int> newIndexStack;

            hashTable+=QString::number(index+1)+ ".  ";

            for(size_t i = 0; i < mainStack[index].Size();++i){
                newIndexStack.Push(indexStack.Top());
                indexStack.Pop();
            }
            for(size_t i = 0; i < mainStack[index].Size();++i){
                hashTable += QString::number(newIndexStack.Top()) + " ";
                newIndexStack.Pop();
            }

            hashTable+="\n";
        }

        return hashTable;
    }

    QString showDataInHashTable(int Data){
        QString dataInHashTable = "";
        int index = hashFunction(Data);

        if(!newValue(Data,index)){
            Stack<int> indexStack = mainStack[index];

            for(size_t i = 0;i<mainStack[index].Size();++i){
                if(Data == indexStack.Top()){
                    dataInHashTable += QString::number(index+1) +".  "+ QString::number(Data);
                    break;
                }
                else {
                    indexStack.Pop();
                }
            }
        }

        return dataInHashTable;
    }

    bool empty(){
        for(size_t i = 0; i<size;++i){
            if(!mainStack[i].Empty()){
                return false;
            }
        }

        return true;
    }

    /*int forTask(){
        int key = 0;
        int amoundOfElement = 0;
        int amound = 0;

        for(size_t index = 0; index < size;++index){
            Stack<int> indexStack = mainStack[index];

            amoundOfElement+=indexStack.Size();

            for(size_t i = 0;i<mainStack[index].Size();++i) {
                key+=hashFunction(indexStack.Top());
                indexStack.Pop();
            }
        }

        if(amoundOfElement){
            int keyMean = key / amoundOfElement;

            for(size_t index = 0; index < size;++index){
                Stack<int> indexStack = mainStack[index];

                for(size_t i = 0;i<mainStack[index].Size();++i) {
                    if(keyMean < hashFunction(indexStack.Top())){
                        ++amound;
                    }

                    indexStack.Pop();
                }
            }
        }

        return amound;
    }*/

    Stack<int>* getMainStack(){
        return mainStack;
    }
    size_t getSize(){
        return size;
    }
};

#endif // HASHTABLE_H
