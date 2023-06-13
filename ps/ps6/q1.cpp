#include <iostream>
#include <string>

using namespace std;

class DynamicStringArray{

    public:
        DynamicStringArray();
        DynamicStringArray(const DynamicStringArray& copy);
        ~DynamicStringArray();
        int getSize();
   

        void addEntry(const string& entry);
        bool deleteEntry(const string& entry);
        string getEntry(const int& index);

        const DynamicStringArray& operator=(const DynamicStringArray& other);


    private:
        string* dynamicArray;
        int size; //Hold the number of entries in the array

};

DynamicStringArray::DynamicStringArray(){
    dynamicArray = NULL;
    size = 0;
}

DynamicStringArray::DynamicStringArray(const DynamicStringArray& copy){

 
    this->size = copy.size;
    
    if(size==0){
        this->dynamicArray = NULL;
    }
    else{
        this->dynamicArray = new string[copy.size];
        
        for(int i=0; i<this->size;i++){
            this->dynamicArray[i] = copy.dynamicArray[i];
        }
    }



}

DynamicStringArray::~DynamicStringArray(){
    size = 0;
    delete [] dynamicArray;
    dynamicArray = nullptr;
}

int DynamicStringArray::getSize(){
    return size;
}


void DynamicStringArray::addEntry(const string& entry){

    string* new_dynamicArray = new string[size+1]; // create new dynamic array with incremented size

    for(int i =0; i < size; i++){
        new_dynamicArray[i] = dynamicArray[i];
    }

    new_dynamicArray[size] = entry; //Add the entry to last index;
    size++; //Change the size
    delete [] dynamicArray; //delete old location

    dynamicArray = new_dynamicArray; //change the dynamicArray with new one

}

bool DynamicStringArray::deleteEntry(const string& entry){

    for(int i=0; i< size; i++){
        
        if(dynamicArray[i].compare(entry) == 0){

            string* new_dynamicArray = new string[size-1];

            for(int j =0; j < size;j++){

                if(j == i){
                    continue;
                }
                else if(j > i){
                    new_dynamicArray[j-1] = dynamicArray[j];
                }
                else{
                    new_dynamicArray[j] = dynamicArray[j];
                }
                
            }
            delete [] dynamicArray;
            dynamicArray = new_dynamicArray;
            size--;
            return true;
        }

    }
    return false;

}


string DynamicStringArray::getEntry(const int& index){

    if(index >= size){
        return NULL;
    }

    return dynamicArray[index];

}

const DynamicStringArray& DynamicStringArray::operator=(const DynamicStringArray& other){

    if(dynamicArray == other.dynamicArray){
        return other;
    }

    else{
        delete [] dynamicArray;
        dynamicArray = new string[other.size];
        
        for(int i=0; i<other.size;i++){
            dynamicArray[i] = other.dynamicArray[i];
        }
        size = other.size;
    }
    return other;
}




int main() {
    DynamicStringArray names;
    // List of names
    names.addEntry("Hello");
    names.addEntry("World!");
    names.addEntry("CSE241");
    names.addEntry("Furkan");
    names.addEntry("Ayan");
    // Output list
    cout << "List of names:" << endl;
    for (int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;
      // Add and remove some names
    names.addEntry("210104004270");
    cout << "After adding a name:" << endl; 
    for (int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;

    names.deleteEntry("CSE241");
    cout << "After removing a name:" << endl; 

    for (int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;
    names.deleteEntry("Ay");

    cout << "After removing a name that isn't on the list:" << endl; for (int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;
      names.addEntry("GTU");
    cout << "After adding another name:" << endl; for (int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;
      // Remove all of the names by repeatedly deleting the last one
    while (names.getSize() > 0) { names.deleteEntry(names.getEntry(names.getSize() - 1));
    }
    cout << "After removing all of the names:" << endl; 
    for (int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;
      names.addEntry("Burns");
    cout << "After adding a name:" << endl; for (int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;
    cout << "Testing copy constructor" << endl; DynamicStringArray names2(names);
    // Remove Burns from names names.deleteEntry("Burns");
    cout << "Copied names:" << endl;
    for (int i = 0; i < names2.getSize(); i++)
        cout << names2.getEntry(i) << endl;
    cout << endl;
    cout << "Testing assignment" << endl; DynamicStringArray names3 = names2; // Remove Burns from names2 names2.deleteEntry("Burns");
    cout << "Copied names:" << endl;
    for (int i = 0; i < names3.getSize(); i++)
        cout << names3.getEntry(i) << endl;
    cout << endl;
    cout << "Enter a character to exit." << endl; char wait;
    cin >> wait;
    return 0;
}
