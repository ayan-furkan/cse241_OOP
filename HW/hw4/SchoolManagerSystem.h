#ifndef SCHOOLMANAGERSYSTEM_H
#define SCHOOLMANAGERSYSTEM_H

#pragma once
#include <iostream>
#include <string.h>
#include "Student.h"
#include "Course.h"


class SchoolManagerSystem{

    public:
        SchoolManagerSystem();
        SchoolManagerSystem(const SchoolManagerSystem& copy);
        ~SchoolManagerSystem();

        int getCourseSize() const;
        int getStudentSize() const;

        const SchoolManagerSystem& operator=(const SchoolManagerSystem& other);
        void add_student(const Student& student); //Add Student to Dynamic Array _students
        void add_course(const Course& course); // Add Course to Dynamic Array _courses

        void select_course(const string& name, const string& code);
        bool delete_course(const Course& course); // Delete course  from dynamic array _courses
        void list_students_registered_to_the_selected_course(const Course& course) const; // print the students who take the course

        void select_student(const string& name, const string& ID);
        bool delete_student(const Student& student); // Delete student from dynamic array _students
        void drop_selected_student_from_a_course(Student& student); // Delete the students from a course
        void add_selected_student_to_a_course(Student& student); // Add student to a course

        void list_all_students() const; // print
        void list_all_courses() const; // print
    private:
        Course* _courses;
        Student* _students;
        int courseSize, studentSize;
};





#endif // SCHOOLMANAGERSYSTEM_H