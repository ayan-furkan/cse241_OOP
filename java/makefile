all: clear clean compile run

compile: driver.java
	@echo "Compiling..."
	@javac driver.java

run:
	@echo "Running the tests...."
	java driver
	@echo
	@echo "Completed tests...."

clean:
	@echo "Removing compiled files..."
	@rm -f *.class
	@rm -f pa7/*.class
	
clear:
	@clear
