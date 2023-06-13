#include "CatalogManager.h"
#include "Book.h"
#include "Movie.h"
#include "Catalog.h"
#include "Music.h"

using namespace std;

int main() {
    CatalogManager catalogmanager;
    catalogmanager.readCatalog("data.txt", "output.txt");

}
