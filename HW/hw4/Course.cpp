#include <iostream>
#include "Course.h"
#include "Student.h"

using namespace std;

Course::Course(){
    //Default constructor
    this->name = "";
    this->code = "";
    this->students = NULL;
    this->_size = 0;
}

Course::Course(const string& name, const string& code){

    this->name = name;
    this->code = code;
    this->_size = 0;
    this->students = NULL;

}

Course::Course(const Course& copy){
    //Copy constructor
    this->name = copy.name;
    this->code = copy.code;

    this->_size = copy._size;
    this->students = new Student[this->_size];

    for(int i = 0; i < _size; i++){
        this->students[i] = copy.students[i];
    }

}

Course::~Course(){
    //Destructor
    _size = 0;
    delete [] students;
    students = nullptr;
}
//GETTERS
string Course::getName() const{
    return name;
}

string Course::getCode() const{
    return code;
}

int Course::getSize() const {
    return _size;
}
//SETTERS
void Course::setName(const string& name){
    this->name = name;
}

void Course::setCode(const string& code){
    this->code = code;
}

const Course& Course::operator=(const Course& other){
    //Assigment operator
    if((name == other.name) && (code == other.code)){
        return other;
    }
    else{
        this->name = other.name;
        this->code = other.code;
        
        delete [] students;
        this->_size = other._size;

        this->students = new Student[this->_size];

        for(int i = 0; i < this->_size; i++){
            this->students[i] = other.students[i];
        }
    }
    return other;

}

ostream& operator<<(ostream& os, const Course& course){
    os << course.code << " " << course.name << endl;
    return os;
}

bool Course::operator==(const Course& other){
    if((name == other.name) && (code == other.code)) return true;
    else return false;
}

bool Course::operator!=(const Course& other){
    if((name == other.name) && (code == other.code)) return false;
    else return true;
}

Student& Course::operator[](const int& index) const{
    if(index >= _size) {
        cout << "OUT OF BOND!"; 
        exit(1);
    }
    return students[index];
  
}


void Course::addStudent(const Student& other){
    //copy the student to the temp delete and create new dynamic array with incremented size.
    //Add back obejects to dynamic array from temp
    //Add the new object to the end
    Course temp(*this);
    
    delete [] this->students;

    this->_size++;
    this->students = new Student[this->_size];

    for(int i = 0; i < temp._size; i++){
        this->students[i] = temp.students[i];
    }
    this->students[_size-1] = other;

    for(int i = 0; i < _size; i++){
        cout << students[i];
    }
}

bool Course::removeStudent(const Student& other){
    // Create temp pointer with decremented size
    // copy the dynamic array to the temp with out given object
    // point the dynamic array to the temp

    for(int i = 0; i < _size; i++){
        if(students[i] == other){

            Student *temp = new Student[_size-1];
            
            for(int j = 0; j < _size; j++){
                if(i==j) continue;
                else if(j > i){
                    temp[j-1] = students[j];
                }
                else{
                    temp[j] = students[j];
                }
            }
            delete [] students;
            students = temp;
            _size--;
            return true;
        }
    }
    return false;
}