#ifndef CATALOG_H
#define CATALOG_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include "Book.h"
#include "Movie.h"
#include "Music.h"

using namespace std;



template<class T>
class catalog
{

public:
    catalog<T>();

    void addData(const T& newdata); 
    void printData(const T& entry)const;
    int getSize()const;

    vector<T> searchCat(const string& searchString, const string& field);

private:
    vector<T> data;
};


#endif