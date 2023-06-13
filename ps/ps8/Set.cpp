#include <iostream>
#include "Set.h"

using namespace std;

template <class T>
Set<T>::Set(){

    array = new T[0];
    size = 0;
}


template <class T>
void Set<T>::add(const T& value){

    T* temp = new T[size];

    for(int i = 0; i < size; i++){
        temp[i] = array[i];
    }
    
    delete [] array;
    array = new T[size+1];

    for(int i = 0; i < size; i++){
        array[i] = temp[i];
    }
    array[size] = value;
    size++;

}


template<class T>
int Set<T>::getSize()const{return size;}

template<class T>
T* Set<T>::getArray()const{return array;}
