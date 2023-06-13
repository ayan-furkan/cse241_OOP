#ifndef COURSE_H
#define COURSE_H

#pragma once

#include <iostream>
#include <string.h>

class Student;

using namespace std;


class Course{
    public: 

        Course();
        Course(const string& name, const string& code);
        Course(const Course& copy);
        ~Course();

        string getName() const;
        string getCode() const;
        int getSize() const;

        void setName(const string& name);
        void setCode(const string& code);

        const Course& operator=(const Course& other);
        bool operator==(const Course& other);
        bool operator!=(const Course& other);
        friend ostream& operator<<(ostream& os, const Course& course);
        Student& operator[](const int& index) const;
        void addStudent(const Student& other); // Add new student to the dynamic array.
        bool removeStudent(const Student& other); // Remove the student from dynamic array if it is exist.
        
    
    private:
        string name; // Course Name
        string code; // Course Code
        Student* students; // Student who takes the course
        int _size; // Student size

};



#endif // COURSE_H