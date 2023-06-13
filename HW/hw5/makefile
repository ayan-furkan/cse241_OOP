all: clear clean compile run

compile: main.cpp Optimusprime.cpp Robot.cpp Humanic.cpp Bulldozer.cpp Roomba.cpp Robocop.cpp 
	@echo "Compiling..."
	@g++ -std=c++11 main.cpp Optimusprime.cpp Robot.cpp Humanic.cpp Bulldozer.cpp Roomba.cpp Robocop.cpp -o main

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
