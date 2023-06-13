#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <math.h>

using namespace std;

/*
    MASTERMIND GAME
*/



int createNumber(int N){

    /* 
    This function takes an integer value as a parameter which is the digit 
    value of a number. And function create an return N digit number.
    */


    //First digit in range [1,9]. 

    int number[N];
    int returnedNumber = 0;
    char cDigit[2];
    int digit;
    bool flag;

    digit = rand() % 9 + 1; // first digit can not be zero
    number[0] = digit;

    for(int i=1; i < N; i++){
        
        do{
            digit = rand() % 10;
            flag = false;

            for(int j=0; j < i; j++){
                if(number[j] == digit){
                    flag = true;
                }
            }
        } while(flag);

        number[i] = digit;
    }
    
    for(int i =0; i < N; i++){

        returnedNumber += number[i] * pow(10, N-i-1);
    }

    return returnedNumber;

}

bool compareNumbers(char secretNum[], char input[], int N){

    int firstCount, secondCount; 
    //First Count: number's position an the value are the same
    //Second Count: only number's value are the same;


    //First Count   
    firstCount = 0;
    for(int i = 0; i < N; i++){
        if(secretNum[i] == input[i]){
            firstCount++;
        }
    }

    //Second Count
    secondCount = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(secretNum[i] == input[j] && i!=j){
                secondCount++;
            }
        }
    }
    cout << firstCount << " " << secondCount << endl;

    if(firstCount == N){
        return true;
    }
    return false;

}




int main(int argc, char* argv[]){

    srand(time(NULL));

    int digit=0;
    char secretNum[9];
    char input[9];


    if(argc <= 2){
        //Print error(missing parameters)
        cerr << "E0" << endl;
        exit(1);
    }

    if (argv[1][0] = '-' && argv[1][1] == 'r'){

        // Create a number with given digit value

        if(int(argv[2][0]) == '0' || int(argv[2][0] == '-')){
            cerr << "E0" << endl;
            exit(1);
        } 

        digit = int(argv[2][0]) - '0';

        int createdNum = createNumber(digit); 
        int k = 0;

        sprintf(secretNum, "%d", createdNum);

    }
    else if(argv[1][0] = '-' && argv[1][1] == 'u'){

        // Use given number as a secret number


        while(int(argv[2][digit]) >= 48 && int(argv[2][digit]) <= 57){
            secretNum[digit] = argv[2][digit];
            digit++;
        }

        for(int i = 0; i < digit; i++){
            //Print an error if in the digit there are repating values
            for(int j = i+1; j < digit; j++){
                if(secretNum[i] == secretNum[j]){
                    cerr << "E0" << endl;
                    exit(1);
                }
            }
        }
        
    } else{
        //Print error (Wrong parameters)
        cerr << "E0" << endl;
        exit(1);
    }

    bool flag; 
    int count = 0;

    for(int i =0; i< digit; i++){
        cout << secretNum[i];
    }
    cout << endl;



    do{
        cin >> input;
        
        int inputSize = strlen(input);

        if(inputSize != digit){
            //Print an error if digit number are not mathced.
            cerr << "E1" << endl;
            exit(1);
        }

        for(int i = 0; i < inputSize; i++){
            // Print an error if there is anything else beside number in input 
            if(int(input[i]) < 48 || int(input[i]) > 57){
                cerr << "E2" << endl;
                exit(1);
            }
        }

        flag = compareNumbers(secretNum, input, digit);
        //If the two numbers are the same then return true
        count++;
    }while(!flag && count<=100);
   
    if(flag){
        cout << "FOUND " << count << endl;
        exit(1);
    } else {
        cout << "FAILED" << endl;
        exit(1);
    }

}