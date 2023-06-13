#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <vector>
#include "Exception.h"

using namespace std;


class Book{
    public:

        Book(vector<string> data);
        string print()const; //combine the private members
        bool isSame(const Book& book)const; //check the new member already exist
        bool search(const string& searchString, const string& field); //search the string in given field

        
    private:
        string title;
        string authors;
        string year;
        string tags;
};




#endif