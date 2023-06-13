#ifndef SET_H
#define SET_H

#include <iostream>
using namespace std;

template<class T>
class Set{
        
    public:
        Set<T>();

        void add(const T& value);
        int getSize() const;
        T* getArray()const;

    private:
        T* array;
        int size;
};


#endif