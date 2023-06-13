#ifndef STUDENT_H
#define STUDENT_H

#pragma once

#include <iostream>
#include <string.h>
#include "Course.h"
#include <limits>

using namespace std;


class Student{

    public:
        Student();
        Student(const string& name, const string& ID);
        Student(const Student& copy);
        ~Student();

        string getName() const;
        string getID() const;
        int getSize() const;

        void setName(const string& name);
        void setID(const string& ID);

        const Student& operator=(const Student& other);
        friend ostream& operator<<(ostream& os, const Student& stu);
        bool operator==(const Student& other);
        bool operator!=(const Student& other);
        Course& operator[](const int& index) const;
        void addCourse(const Course& other); // Add new course to the dynamic array.
        bool removeCourse(const Course& other); // delete the course from dynamic array if it is exists.


    private:
        string name; // Student Name
        string ID; // Student ID number
        Course* courses; // Course that student takes
        int _size; //Courses Size

};



#endif //STUDENT_H