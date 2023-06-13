#include <iostream>
#include "SchoolManagerSystem.h"
#include "Student.h"

SchoolManagerSystem::SchoolManagerSystem(){
    //Default constructor
    this->courseSize = 0;
    this->studentSize = 0;

    this->_courses = NULL;
    this->_students = NULL;
}

SchoolManagerSystem::SchoolManagerSystem(const SchoolManagerSystem& copy){
    //Copy Constructor
    this->courseSize = copy.courseSize;
    this->studentSize = copy.studentSize;

    this->_courses = new Course[this->courseSize];
    this->_students = new Student[this->studentSize]; 

    for(int i = 0; i < this->courseSize; i++){
        this->_courses[i] = copy._courses[i];
    }   
    for(int i = 0; i < this->studentSize; i++){
        this->_students[i] = copy._students[i];
    }
}

SchoolManagerSystem::~SchoolManagerSystem(){
    //Destructor
    this->courseSize = 0;
    this->studentSize = 0;

    delete [] this->_courses;
    this->_courses = nullptr;

    delete [] this->_students;
    this->_students = nullptr;
}

//GETTERS
int SchoolManagerSystem::getCourseSize() const{
    return courseSize;
}

int SchoolManagerSystem::getStudentSize() const{
    return studentSize;
}


const SchoolManagerSystem& SchoolManagerSystem::operator=(const SchoolManagerSystem& other){
    //Assingment Operator
    if((this->_courses == other._courses) && (this->_students == other._students)){
        return other;
    }
    else{
        this->courseSize = other.courseSize;
        this->studentSize = other.studentSize;

        delete [] this->_courses;
        delete [] this->_students;

        this->_courses = new Course[this->courseSize];
        this->_students = new Student[this->studentSize];

        for(int i = 0; i < this->courseSize; i++){
            this->_courses[i] = other._courses[i];
        }

        for(int i = 0; i < this->studentSize; i++){
            this->_students[i] = other._students[i];
        }
    }

    return other;
}

void SchoolManagerSystem::add_student(const Student& student){
    // If students exists do not add
    for(int i = 0; i < studentSize; i++){
        if(_students[i] == student){
            cout << "Student EXISTS!" << endl;
            return;
        }
    }
    //Copy the dynamic array to the temp
    //delete and create the dynamic array with incremented size
    //Add back to dynamic array from temp
    //Add new object to the back of the dynamic array

    SchoolManagerSystem temp(*this);
    studentSize++;
    delete [] _students;
    _students = new Student[studentSize];
    for(int i = 0; i < temp.studentSize; i++){
        
        _students[i] = temp._students[i];
    }

    _students[studentSize-1] = student;

}

void SchoolManagerSystem::add_course(const Course& course){
    // If course exists do not add
    for(int i = 0; i < courseSize; i++){
        if(_courses[i] == course){
            cout << "Course EXISTS!" << endl;
            return;
        }
    }

    //Copy the dynamic array to the temp
    //delete and create the dynamic array with incremented size
    //Add back to dynamic array from temp
    //Add new object to the back of the dynamic array
    SchoolManagerSystem temp(*this);
    courseSize++;
    delete [] _courses;
    _courses = new Course[courseSize];

    for(int i = 0; i < temp.courseSize; i++){
        _courses[i] = temp._courses[i];
    }
    _courses[courseSize-1] = course;
    
}

bool SchoolManagerSystem::delete_student(const Student& student){
    // Create temp pointer with decremented size
    // copy the dynamic array to the temp with out given object
    // point the dynamic array to the temp

    //DO NOT FORGET THE DROP THE STUDENT FROM EVERY COURSE
    for(int i = 0; i < studentSize; i++){

        if(_students[i] == student){
            
            //Drop student from every course
            for(int j = 0; j < courseSize; j++){
                _courses[j].removeStudent(_students[i]);
            }
            
            Student *temp = new Student[studentSize-1];

            for(int j = 0; j < studentSize; j++){
                if(j==i) continue;
                else if(j > i){
                    temp[j-1] = _students[j];
                }
                else{
                    temp[j] = _students[j];
                }
                
            }
            delete [] _students;
            _students = temp;
            studentSize--;
            return true;
        }
    }
    return false;
}

bool SchoolManagerSystem::delete_course(const Course& course){
    // Create temp pointer with decremented size
    // copy the dynamic array to the temp with out given object
    // point the dynamic array to the temp

    //DO NOT FORGET TO DROP STUDENTS WHO ARE TAKING THE COURSE
    for(int i = 0; i < courseSize; i++){

        if(_courses[i] == course){
            
            //Drop every student who take this course
            for(int j = 0; j < studentSize; j++){
                _students[j].removeCourse(_courses[i]);
            }
            
            Course *temp = new Course[courseSize-1];

            for(int j = 0; j < courseSize; j++){
                if(j==i) continue;
                else if(j > i){
                    temp[j-1] = _courses[j];
                }
                else{
                    temp[j] = _courses[j];
                }
                
            }
            delete [] _courses;
            _courses = temp;
            courseSize--;
            return true;
        }
    }
    return false;
}

void SchoolManagerSystem::drop_selected_student_from_a_course(Student& student){

    Student temp;
    int count = 0;
    int input;
    //Create a temp student object and add the courses that students take

    for(int i = 0; i < studentSize; i++){
        if(_students[i] == student){
            cout << "0 UP" << endl;
            for(int j = 0; j < courseSize; j++){
                for(int k = 0; k < _students[i].getSize(); k++){
                    if(_courses[j] == _students[i][k]){
                        cout << ++count << " " << _students[i][k];
                        temp.addCourse(_students[i][k]);
                    }
                }
            }


            cout << ">> ";
            cin >> input;

            while (cin.fail())
            {
                cout << "ERROR -- Enter integer" << endl;
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << ">> ";
                cin >> input;
            }

            if(input == 0) return;
            else if(input <= count) {
                //Remove the entered course from student and drop the student entered course
                _students[i].removeCourse(temp[input-1]);
                for(int j =0; j < courseSize; j++){
                    if(_courses[j] == temp[input-1]){
                        _courses[j].removeStudent(_students[i]);
                    }
                }
                return;
            }
            else{
                cout << "OUT OF RANGE!";
                exit(1);
            }
        }
    }


    
}

void SchoolManagerSystem::add_selected_student_to_a_course(Student& student){
    Student temp;
    int count = 0;
    int input;

    bool flag = false;

    //Create a temp student object and add the the courses that student doesn't take
    for(int i = 0; i < studentSize; i++){
        if(_students[i] == student) {
            cout << "0 UP" << endl;
            if(_students[i].getSize() == 0){
                for(int j = 0; j < courseSize; j++){                
                    cout << ++count << " " << _courses[j];
                    temp.addCourse(_courses[j]);
                } 
            }
            else{

                for(int j = 0; j < courseSize; j++){
                    
                    for(int k = 0; k < _students[i].getSize(); k++){
                        flag = false;
                        if(_courses[j] == _students[i][k]){
                            flag = true;
                            break;
                        }     
                    }
                    if (flag == false){
                        cout << ++count << " " << _courses[j];
                        temp.addCourse(_courses[j]);
                    }
                }
            }
    

        
            cout << ">> ";
            cin >> input;

             while (cin.fail())
            {
                cout << "ERROR -- Enter integer" << endl;
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << ">> ";
                cin >> input;
            }


            if(input == 0) return;
            else if(input <= count) {
                //
                _students[i].addCourse(temp[input-1]);

                for(int j = 0; j < courseSize; j++){
                    if(_courses[j] == temp[input-1]){
                        _courses[j].addStudent(_students[i]);
                    }
                }

            return;
            }
            else{
                cout << "OUT OF RANGE!";
                exit(1);
            }
        }
    }


    
}

void SchoolManagerSystem::select_student(const string& name, const string& ID){

    //SELECT STUDENT MENU
    int input;
    Student stu(name, ID);
    bool flag = false;

    for(int i = 0; i < studentSize; i++){
        if(_students[i] == stu){
            flag = true;
            //FLAG for existense of the student
        }  
    } 

    if(flag == false){
        cout << "There isn't such a student!" << endl;
        return;
    }

    do{
        cout << "0 up" << endl;
        cout << "1 delete_student" << endl;
        cout << "2 add_selected_student_to_a_course" << endl;
        cout << "3 drop_selected_student_from_a_course" << endl;
        cout << ">> ";
        cin >> input;

        while (cin.fail())
        { 
            cout << "ERROR -- Enter integer" << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ">> ";
            cin >> input;
        }


        switch (input)
        {
        case 0:
            //UP
            break;
    
        case 1:
            delete_student(stu);
            //After delete go upper menu
            break;
    
        case 2:
            add_selected_student_to_a_course(stu);
            break;
    
        case 3:
            drop_selected_student_from_a_course(stu);
            break;
    
        default:
            cout << "OUT OF RANGE!" << endl;
            break;
        }

    }while((input!=0) && (input != 1));


    return;
}


void SchoolManagerSystem::list_all_students() const{
    cout << "**************" << endl;
    for(int i = 0; i < studentSize; i++){
        cout << i+1 << " " << _students[i];
    }
    cout << "**************" << endl;
}

void SchoolManagerSystem::list_all_courses() const{
    cout << "**************" << endl;
    for(int i = 0; i < courseSize; i++){
        cout << i+1 << " " << _courses[i];
    }
    cout << "**************" << endl;
}

void SchoolManagerSystem::select_course(const string& name, const string& code){
    //SELECT COURSE MENU
    int input;
    Course course(name, code);
    bool flag = false;

    for(int i = 0; i < courseSize; i++){
        if(_courses[i] == course){
            flag = true;
            //FLAG for existince of a course
        }  
    } 

    if(flag == false){
        cout << "There isn't such a course!" << endl;
        return;
    }



    for(int i=0; i < courseSize; i++){

        if(_courses[i] == course){

            do{
                cout << "0 up" << endl;
                cout << "1 delete_course" << endl;
                cout << "2 list_students_registered_to_the_selected_course" << endl;
                cout << ">> ";
                cin >> input;

                while (cin.fail())
                {
                    cout << "ERROR -- Enter integer" << endl;
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << ">> ";
                    cin >> input;
                }


                switch (input)
                {
                case 0:
                    //UP
                    break;
                
                case 1:
                    {
                    delete_course(course);
                    //After delete, go to upper menu(course menu)
                    break;
                    }
                case 2:
                    list_students_registered_to_the_selected_course(course);
                    break;
                
                default:
                    cout << "OUT OF RANGE!";
                    break;
                }


            }while((input != 0) && input != 1);

        }

    }

}

void SchoolManagerSystem::list_students_registered_to_the_selected_course(const Course& course) const{

    for(int i = 0; i < courseSize; i++){
        if(_courses[i] == course){
            cout << "**************" << endl;
            for(int j = 0; j < _courses[i].getSize(); j++){
                cout << (j+1) << "- " << _courses[i][j];
            }
            cout << "**************" << endl;
            return;
        }
        
    }
    cout << "THERE ISN'T SUCH A COURSE" << endl;

}