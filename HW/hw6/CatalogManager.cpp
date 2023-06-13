#include "CatalogManager.h"
#include "Exception.h"
#include <algorithm>

using namespace std;



CatalogManager::CatalogManager(){

}



void CatalogManager::readMusicCatalog(ifstream& file){
        
    string line;
    ofstream output("output.txt");

    output << "Catalog Read: Music" << endl;
            
    
    while (getline(file, line)) {
        //get every line
        if (line.empty()) {
            continue;
        }
        
        //parse the given line into vector string 
        //make the music object
        // if there are no exception add to the catalog
        try{
            vector<string> parsedMusic = split(line);
            Music music(parsedMusic);
            musicCatalog.addData(music);
        }catch(DuplicateEntryException e){
            output << e.getMessage() << endl;
            output << line << endl;
        }
        
        catch(MissingFieldException e){
            output << e.getMessage() << endl;
            output << line << endl;
        }
        
        
    }
    output << entryCounter()  << " unique entries" << endl;

}




void CatalogManager::readBookCatalog(ifstream& file){
        
    string line;
            
    ofstream output("output.txt");

    output << "Catalog Read: Book" << endl;

    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        //parse the given line into vector string 
        //make the book object
        // if there are no exception add to the catalog

        try{
            vector<string> parsedBook = split(line);
            Book book(parsedBook);
            bookCatalog.addData(book);
        }catch(DuplicateEntryException e){
            output << e.getMessage() << endl;
            output << line << endl;
        }
        
        catch(MissingFieldException e){
            output << e.getMessage() << endl;
            output << line << endl;
        }       
        
        
    }
    output << entryCounter() << " unique entries" << endl;

}

void CatalogManager::readMovieCatalog(ifstream& file){
        
    string line;
    ofstream output("output.txt");

    output << "Catalog Read: Movie" << endl;
            
    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        //parse the given line into vector string 
        //make the movie object
        // if there are no exception add to the catalog
        try{
            vector<string> parsedMovie = split(line);
            Movie movie(parsedMovie);
            movieCatalog.addData(movie);
        }catch(DuplicateEntryException e){
            output << e.getMessage() << endl;
            output << line << endl;
        }
        
        catch(MissingFieldException e){
            output << e.getMessage() << endl;
            output << line << endl;
        }
        
    }

    output << entryCounter() << " unique entries" << endl;


}

void CatalogManager::readCatalog(const string& filename, const string& outputfile) {
    ifstream file(filename);
    ofstream output(outputfile);

    if (!file.is_open()) {
        cout << "Failed to open catalog file.";
        exit(1);
    }
    if (!output.is_open()) {
        cout << "Failed to open catalog file.";
        exit(1);
    }

    string line;
    getline(file, line); // Read the first line to determine the catalog type


    //check the first line in the file
    //depend on the line continue reading the file then execute the commands
    

    if (line == "book") {
        readBookCatalog(file);
        executeCommands("command.txt",line);
    } else if (line == "music") {
        readMusicCatalog(file);
        executeCommands("command.txt",line);
    } else if(line == "movie") {
        readMovieCatalog(file);
        executeCommands("command.txt",line);
    }



}

int CatalogManager::entryCounter() const{
    return bookCatalog.getSize() + musicCatalog.getSize() + movieCatalog.getSize();
}


void CatalogManager::executeCommands(const string& filename,const string& catalog){

    ifstream file("command.txt");
    ofstream output("output.txt", ios_base::app);
    if(!file.is_open()){
        cout << "Error opening the file" << endl;
        exit(1);
    }

    string line;

    if(!output.is_open()){
        cout << "Error opening the file" << endl;
        exit(1);
    }

    vector<string> command;


    while(getline(file,line)){
        command = commandSplit(line);

        if(command.size() >= 2){
            if (command[0] == "search"){
                if(command.size() >= 4){
                    //search
                    string field = split(command[3])[0];
                    string searchString = split(command[1])[0];
                    
                    //search the field with string 
                    //get the vector write to the output.txt file if no exception
                    if(catalog == "book"){
                        vector<Book> bookvec = bookCatalog.searchCat(searchString, field);
                        
                        try{  
                            if(bookvec.size() == 0){
                                throw WrongCommandException("Exception: command is wrong");
                            }
                            
                        }catch(WrongCommandException e){
                            output << e.getMessage() << endl;
                        }
                        output << line << endl;
                        
                        for(int i = 0; i < bookvec.size(); i++){
                            output << bookvec[i].print();
                        }
                        

                    } 
                    if (catalog == "music"){
                        
                        
                        vector<Music> musicvec = musicCatalog.searchCat(searchString,field);
                        try{
                            if(musicvec.size() == 0){
                                throw WrongCommandException("Exception: command is wrong");
                            }   
                        }catch(WrongCommandException e){
                            output << e.getMessage() << endl;
                        }

                        output << line << endl;
                        
                        for(int i = 0; i < musicvec.size(); i++){
                            output << musicvec[i].print();
                        }
                        

                    }
                    if(catalog == "movie"){


                    
                        
                            vector<Movie> movievec = movieCatalog.searchCat(searchString,field);
                            try{
                                if(movievec.size() == 0){
                                    throw WrongCommandException("Excpetion: command is wrong");
                                }
                            }
                            catch(WrongCommandException e){
                                    output << e.getMessage() << endl;
                                }
                            output << line << endl;
                        
                            for(int i = 0; i < movievec.size(); i++){
                                output << movievec[i].print();
                            }

                        

                    }
                }
                else{
                    try{
                        throw WrongCommandException("Excpetion: command is wrong");
                    }catch(WrongCommandException e){
                        output << e.getMessage() << endl;
                    }
                }

            }
            else{
                try{
                    throw WrongCommandException("Excpetion: command is wrong");
                }catch(WrongCommandException e){
                    output << e.getMessage() << endl;
                }
                
            }
        }
        else{
            try{
                throw WrongCommandException("Exception Wrong Command");
            }catch(WrongCommandException e){
                output << e.getMessage() << endl;
            }
        }
    }


}

vector<string> CatalogManager::split(const string& line) {
        //split the line to the vector
        
        vector<string> fields;
        string field;
        stringstream ss(line);
        
        ss.ignore();

        while (getline(ss, field, '\"')) {
            ss.ignore();
            if (!field.empty()) {
                fields.push_back(field);
                ss.ignore(1);
            }else{
                fields.push_back(" ");
            }
            
        }

        return fields;
}
vector<string> CatalogManager::commandSplit(const string& line) {
        //split the command into vector
        vector<string> fields;
        string field;
        stringstream ss(line);


        while (getline(ss, field,' ')) {
            if (!field.empty()) {
                fields.push_back(field);
            }
        }

        return fields;
}