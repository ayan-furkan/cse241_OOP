#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include <vector>
#include "Exception.h"

using namespace std;

class Movie{
    public:
        Movie(vector<string> data);
        string print()const;  //combine the private members
        bool isSame(const Movie& movie)const;//check the new member already exist
        bool search(const string& searchString, const string& field);//search the string in given field

    private:
        string title;
        string director;
        string year;
        string genre;
        string starring;
};


#endif