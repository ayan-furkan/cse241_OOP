#include "book.h"
using namespace std;


Book::Book(vector<string> data){
    
    if(data.size() != 4){
        throw MissingFieldException("Exception: missing field");
    }

    title = data[0];
    authors = data[1];
    year = data[2];
    tags = data[3];
}

string Book::print()const{

    return ("\"" + title + "\" \"" + authors + "\" \"" + year + "\" \"" + tags + "\"\n");
}


bool Book::isSame(const Book& book) const{
    if(book.title == this->title) return true;
    else return false;
}

bool Book::search(const string& searchString, const string& field){

    if(field == "title"){
        if(title.find(searchString)){
            return true;
        }
    }
    if(field == "authors"){
        if(authors.find(searchString)){
            return true;
        }
    }
    if(field == "year"){
        if(year.find(searchString)){
            return true;
        }
    }
    if(field == "tags"){
        if(tags.find(searchString)){
            cout << tags << "   " << tags.find(searchString);
            return true;
        }
    }
    return false;


}
