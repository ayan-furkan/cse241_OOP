#include <iostream>
#include "Student.h"

using namespace std;


Student::Student(){
    //Default Constructor
    name = "";
    ID = "";
    courses = NULL;
    _size = 0;
}

Student::Student(const string& name, const string& ID){
    
    this->ID = ID;
    this->name = name;

    this->courses = NULL;
    this->_size = 0;
}

Student::Student(const Student& copy){
    //Cpoy Constructor
    if(_size == 0){
        this->courses = NULL;
    }else{

        this->name = copy.name;
        this->ID = copy.ID;

        this->_size = copy._size;
        this->courses = new Course[_size];

        for(int i=0; i < _size; i++){
            this->courses[i] = copy.courses[i];
        }
    }

}

Student::~Student(){
    //Destructor
    _size = 0;

    delete [] courses;
    courses = nullptr;
}

//GETTERS
string Student::getName() const{
    return name;
}
string Student::getID() const{
    return ID;
}

int Student::getSize() const{
    return _size;
}

//SETTERS
void Student::setName(const string& name){
    this->name = name;
}

void Student::setID(const string& ID){
    this->ID = ID;
}

const Student& Student::operator=(const Student& other){
    //assigment operator
    if((name == other.name) && (ID == other.ID)){
        
        return other;
    }
    else{
        this->name = other.name;
        this->ID = other.ID;

        delete [] courses;
        this->_size = other._size;

        this->courses = new Course[this->_size];

        for(int i = 0; i < _size; i++){
            this->courses[i] = other.courses[i];
        }
    }
    return other;

}

ostream& operator<<(ostream& os, const Student& stu){
    cout << stu.name << " " << stu.ID << endl;
    return os;
}

bool Student::operator==(const Student& other){

    if((name == other.name) && (ID == other.ID)) return true;
    else return false;
}

bool Student::operator!=(const Student& other){

    if((name == other.name) && (ID == other.ID)) return false;
    else return true;
}

Course& Student::operator[](const int& index) const{

    if(index >= _size) {
        cout << "OUT OF BOND!"; 
        exit(1);
    }
    return courses[index];
}


void Student::addCourse(const Course& other){
    //copy the course to the temp delete and create new dynamic array with incremented size.
    //Add back obejects to dynamic array from temp
    //Add the new object to the end
    Student temp(*this);
    

    delete [] this->courses;

    this->_size++;
    this->courses = new Course[this->_size];


    for(int i = 0; i < temp._size; i++){
        this->courses[i] = temp.courses[i];
    }
    this->courses[_size-1] = other;
    
}

bool Student::removeCourse(const Course& other){
     // Create temp pointer with decremented size
    // copy the dynamic array to the temp with out given object
    // point the dynamic array to the temp

    for(int i =0; i < _size; i++){

        if(courses[i] == other){

            Course *temp = new Course[_size-1];

            for(int j = 0; j < _size; j++){
                
                if(i==j) continue;
                else if (i < j){
                    temp[j-1] = courses[j];
                }
                else{
                    temp[j] = courses[j];
                }
            }
            delete [] courses;
            courses = temp;
            _size--;
            return true;
        }
    }
    return false;
}
