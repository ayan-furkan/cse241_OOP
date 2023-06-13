#include <iostream>
#include "SchoolManagerSystem.h"


using namespace std;

void courseMenu(SchoolManagerSystem& sys){
    int input;
    string name,code;
    char c[256];
    do{
        cout << "0 up" << endl;
        cout << "1 add_course" << endl;
        cout << "2 select_course" << endl;
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
            cout << ">> ";
            cin >> code;
            getline(cin, name);
            Course course(name, code);
            sys.add_course(course);
            break;
            }
        case 2:
            cout << ">> ";
            cin >> code;
            getline(cin, name);
            sys.select_course(name, code);
            break;
        
        default:
            cout << "OUT OF RANGE!" << endl;
            break;
        }
    }while(input != 0);

}


void studentMenu(SchoolManagerSystem& sys){

    int input;
    char c;
    string name, ID;

    do{
        cout << "0 up" << endl;
        cout << "1 add_student" << endl;
        cout << "2 select_student" << endl;
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
            break;
        
        case 1:          
            {
            name.clear();
            ID.clear();
            cout << ">> ";
            cin.ignore();
            cin.get(c);
            while(c != '\n'){
                if((c < '0') || (c > '9')){
                    name.push_back(c);
                }
                else{
                    ID.push_back(c);
                }
                cin.get(c);
            }
            Student stu(name, ID);
            sys.add_student(stu);
            break;
            }
        
        case 2:
            {
            name.clear();
            ID.clear();
            cout << ">> ";

            cin.ignore();
            cin.get(c);
            while(c != '\n'){
                if(c < '0' || c > '9'){
                    name.push_back(c);
                }
                else{
                    ID.push_back(c);
                }
                cin.get(c);
            }
            sys.select_student(name,ID);
            break;
            }
        
        default:
            cout << "OUT OF RANGE!" << endl;
            break;
        }
    }while(input!=0);


}

void mainMenu(SchoolManagerSystem& sys){

    int input;
    cout << "Main_menu" << endl;
    do{       
        
        cout << "0 exit" << endl;
        cout << "1 student" << endl;
        cout << "2 course" << endl;
        cout << "3 list_all_students" << endl;
        cout << "4 list_all_courses" << endl;
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
            break;
        
        case 1:
            studentMenu(sys);
            break;
        
        case 2:
            courseMenu(sys);
            break;
        
        case 3:
            sys.list_all_students();
            break;
        
        case 4:
            sys.list_all_courses();
            break;
        
        default:
            cout << "OUT OF RANGE!" << endl;
            break;
        }   
    } while(input!=0);
}



int main(){

    SchoolManagerSystem sys;

    mainMenu(sys);


}