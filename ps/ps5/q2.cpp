#include <iostream>
#include <string>

using namespace std;

class Student{

    public:
    Student(){
        name = "";
        numClasses = 0;
        classList = NULL;
    }
    ~Student(){
        res();
    }

    void resetClasses(){
        res();
        numClasses = 0;
    }

    void inputData(){
        resetClasses();
        cout << "Enter user name." << endl;
        cin >> name;
        cout << "Enter number of classes." << endl;
        cin >> numClasses;
        cin.ignore(2, '\n');
        if(numClasses>0){
            classList = new string[numClasses];

            for(int i=0; i< numClasses; i++){
                cout << "Enter the name of the class " << i+1 <<endl;
                cin >> classList[i];
            }
        }
        cout << endl;
    }

    void outputData(){

        cout << "Name: " << name << endl;
        cout << "Number of classes: " << numClasses << endl;
        for(int i=0; i < numClasses;i++){
            cout << "Class " << i+1 << ":" << classList[i] << endl;
        }
        cout << endl;
    }

    Student& operator=(const Student&other ){

        if(this->classList == other.classList){
            return *this;
        }

        resetClasses();
        name = other.name;
        numClasses = other.numClasses;
        
        if(numClasses>0){

            classList = new string[numClasses];

            for(int i=0; i < numClasses; i++){
                classList[i] = other.classList[i];
            }
        }

        return *this;

    }


    private:
        string name;
        int numClasses;
        string* classList;
        void res(){
            if(classList != NULL){
                delete [] classList;
                classList = NULL;
            }
        }
};


int main(){
    Student s1, s2;
s1.inputData(); // Input data for student 1 
cout << "Student 1's data:" << endl; s1.outputData(); // Output data for student 1
cout << endl;
s2 = s1;
cout << "Student 2's data after assignment from student 1:" << endl; s2.outputData(); // Should output same data as for student 1
s1.resetClasses();
cout << "Student 1's data after reset:" << endl; s1.outputData(); // Should have no classes
cout << "Student 2's data, should still have original classes:" << endl; s2.outputData(); // Should still have original classes
cout << endl;

}