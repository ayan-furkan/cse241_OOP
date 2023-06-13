all: clear clean compile run

compile: main.cpp CatalogManager.cpp Book.cpp Music.cpp Movie.cpp Catalog.cpp Exception.cpp
	@echo "Compiling..."
	@g++ -std=c++11 main.cpp CatalogManager.cpp Book.cpp Music.cpp Movie.cpp Catalog.cpp Exception.cpp -o main

run:
	@echo "Running the tests...."
	./main
	@echo
	@echo "Completed tests...."

clean:
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f main
	
clear:
	@clear
