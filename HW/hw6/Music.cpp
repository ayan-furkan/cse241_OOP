#include "Music.h"

using namespace std;

Music::Music(vector<string> data){

    if(data.size() != 4){
        throw MissingFieldException("Exception: missing field");
    }

    title = data[0];
    artists = data[1];
    year = data[2];
    genre = data[3];
}

string Music::print()const{
    return "\"" + title + "\" \"" + artists + "\" \"" + year + "\" \"" + genre + "\"\n";
}

bool Music::isSame(const Music& music) const {
    if(music.title == this->title)return true;
    else return false;
}

bool Music::search(const string& searchString, const string& field){

    if(field == "title"){
        if(title.find(searchString)){
            return true;
        }
    }
    else if(field == "artists" ){
        if(artists.find(searchString)){
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
    return false;



}