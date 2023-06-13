#include <iostream>

using namespace std;

int main(){

    // Find prime numbers between 3 and 100.

    int i,j;
    bool isPrime; // To check the number either is prime number or not.


    for(i = 3; i <= 100; i++){
        
        isPrime = true;

        // If any 2 to the n-1 number diveds the n so it is not prime.
        for(j = 2; j<=i-1; j++){
            
            if(i % j == 0) {
                isPrime = false;
            }

        }

        if (isPrime == true){

            cout << i << ", ";
        }
    
    }
    cout << endl;
}