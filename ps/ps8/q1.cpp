#include <iostream>
#include "Set.h"
#include "Set.cpp"

using namespace std;


int main()
{
    Set<int> s1;
    Set<string> s2;
    int* intArray = NULL;
    string* stringArray = NULL; 
    int i;
    // Add some sample integers to the set
    s1.add(34); 
    s1.add(61);
    s1.add(31);
    s1.add(1);
    intArray = s1.getArray ();
    cout << "Set one has " << s1.getSize () << " items. Here they are: "<< endl;
    for (i=0; i< s1.getSize(); i++) {
    cout << intArray[i] << endl; }
    
    
    if (intArray!=NULL) delete[] intArray;
    // Add some sample strings to the set
    s2.add("apple") ;
    s2.add("orange");
    s2.add("chery") ;
    s2.add("banana") ;
    stringArray = s2.getArray();

    cout << "Set two has " << s2.getSize () << "items. Here they are: " << endl;
    for (i=0; i< s2.getSize(); i++)
    {
    cout << stringArray[i] << endl ;
    }
    if (stringArray!=NULL) delete[] stringArray;
}