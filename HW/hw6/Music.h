#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <vector>
#include <string>
#include "Exception.h"

using namespace std;

class Music{
    public:

        Music();
        Music(vector<string> data);
        string print()const; //combine the private members
        bool isSame(const Music& music)const; //check the new member already exist
        bool search(const string& searchString, const string& field); //search the string in given field

    private:
        string title;
        string artists;
        string year;
        string genre;
};



#endif