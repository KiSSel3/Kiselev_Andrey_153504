#ifndef HASHTABLEFORTASK_H
#define HASHTABLEFORTASK_H
#include "HashTable.h"

class HashTableForTask : HashTable {
public:
    int forTask(Stack<int>* MainStack, size_t Size) {
        mainStack = MainStack;
        size = Size;

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
    }
};

#endif // HASHTABLEFORTASK_H
