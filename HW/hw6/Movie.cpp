#include "Movie.h"

using namespace std;



Movie::Movie(vector<string> data){
    if(data.size() != 5){
        throw MissingFieldException("Exception: missing field");
    }

    title = data[0];
    director = data[1];
    year = data[2];
    genre = data[3];
    starring = data[4];

}


string Movie::print()const{

    return  "\"" + title + "\" \"" + director + "\" \"" + year + "\" \"" + genre + "\" \"" + starring + "\"\n";
}

bool Movie::isSame(const Movie& movie)const{

    if(movie.title == this->title) return true;
    else return false;

}


bool Movie::search(const string& searchString, const string& field){

    if(field == "title"){
        if(title.find(searchString)){
        return true;

        }
    }
    else if(field == "director"){
        if(director.find(searchString)){
        return true;

        }
    }
    else if(field == "year"){
        if(year.find(searchString)){
        return true;

        }
    }
    else if(field == "genre"){
        if(genre.find(searchString)){
        return true;

        }
    }
    else if(field == "starring"){
        if(starring.find(searchString)){
        return true;

        }
    }
    return false;
    


}
