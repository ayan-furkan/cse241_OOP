#include <iostream>
#include <vector>

using namespace std;

void printList(vector<int> v){

    for(int i=0; i<v.size(); i++){
        cout << v[i];
    }

}


int main(){
    int suitorN;
    vector<int> v;

    cout << "How manu suitors: ";
    cin >> suitorN;

    for(int i=1; i<=suitorN; i++){
        v.emplace_back(i);
    }

    int count = 0;
    printList(v);
    cout << " initial list of suitor, starting from" << count+1 << endl;

    while(v.size() != 1){
    
        for(int i =0; i<2; i++){
            if(count == v.size()){
                count = 1;
            }else{
                count++;
            }
        }        
        int erased = v[count];
        v.erase(v.begin() + count);
        printList(v);

        if (count == v.size()){
            count = 0;
        }
        if(v.size() == 1){
            cout << " suitor " << erased << " eliminated, "<< v[0] << " is the lucky winner!" << endl;;
        }else{
            cout << " suitor "<< erased << " eliminated, continue counting from "<< v[count] <<endl;
        }
    }
}   