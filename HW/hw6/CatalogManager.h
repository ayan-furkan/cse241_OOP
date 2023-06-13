#ifndef CATALOGMANAGER_H
#define CATALOGMANAGER_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <sstream>
#include "Catalog.h"
#include "Exception.h"


using namespace std;

class CatalogManager{

    public:
        CatalogManager();
        void readCatalog(const string& filename,const string& ouputfile);
        void executeCommands(const string& filename,const string& catalog);
        
        void readBookCatalog(ifstream& file);
        void readMusicCatalog(ifstream& file);
        void readMovieCatalog(ifstream& file);

        vector<string> split(const string& line);
        vector<string> commandSplit(const string& line);
        
        int entryCounter() const;

    private:
        catalog<Book> bookCatalog;
        catalog<Music> musicCatalog;
        catalog<Movie> movieCatalog;
    
};

#endif