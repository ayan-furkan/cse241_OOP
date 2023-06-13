#include "Catalog.h"
#include <algorithm>

using namespace std;

template<class T>
catalog<T>::catalog(){

}


template<class T>
void catalog<T>::printData(const T& entry) const{
    entry.print();
}

template<class T>
void catalog<T>::addData(const T& newData) {
    //Add new data into catalog if it is already exist then throw exception

    for(int i = 0; i < data.size(); i++){
        if(data[i].isSame(newData)){
            throw DuplicateEntryException("Exception: duplicate entry");
        }
    }

    data.push_back(newData);

}



template<class T>
int catalog<T>::getSize()const {
    return data.size();
}

template<class T>
vector<T> catalog<T>::searchCat(const string& searchString, const string& field) {
        //Seacrh every data whether they have the given string in the field
        //Then  return the datas;
        vector<T> vec;

        for(int i = 0; i < data.size(); i++){
            if(data[i].search(searchString, field)){
                vec.push_back(data[i]);
            }
        }
        return vec;

}



template class catalog<Book>;
template class catalog<Music>;
template class catalog<Movie>;



