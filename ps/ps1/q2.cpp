#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int END_OF_GAME = 100;

int rollDice(); // Rolling 6 faces dice;
int humanTurn(int humanTotalScore); // return the player roundScore
int computerTurn(int computerTotalScore); // return the computer roundScore
void endGame(int pscore,int cScore); // print scores at the end

int main(){
    srand(static_cast<int>(time(NULL)));

    int humanTotalScore = 0;
    int computerTotalScore = 0;
    bool gameEnd = false;
    cout << "WELCOME TO THE PIG GAME!!!" << endl << endl;

    while (1)
    {   
        cout << "\nCOMPUTER'S TURN!" << endl;
        cout << "COMPUTER SCORE: " << computerTotalScore << endl << endl;
        computerTotalScore += computerTurn(computerTotalScore);
        if(computerTotalScore >= 100){
            cout << "\nCOMPUTER WINS!" << endl;
            break;
        }   

        cout << "\nPlayer's Turn!" << endl;
        cout << "PLAYER SCORE:" << humanTotalScore << endl << endl;
        humanTotalScore += humanTurn(humanTotalScore);

        if(humanTotalScore >= 100){
            cout << "\nPLAYER WINS!" << endl;
            break;
        }   

    }
    endGame(humanTotalScore , computerTotalScore); // Prints the endGame results.
}

void endGame(int pscore,int cScore){
    cout << "PLAYER SCORE: " << pscore << endl;
    cout << "COMPUTER SCORE: " << cScore << endl;
}

int rollDice(){

    return (rand() % 6) + 1;
}

int humanTurn(int humanTotalScore){

    // Roll the dice and ask the player want the hold the dice or roll again.
    // If player wants to hold the dice return the total score he/she gained.
    // Else roll again until the dice come 1 or player want the hold the dice.

    int currentScore = 0;
    char input;
    int roll;

    roll = rollDice();
    cout << "You Rolled " << roll << endl;
    currentScore += roll; 

    while(roll != 1){

        cout << "ROUND SCORE = " << currentScore << endl;    
        cout << "ROLL('r') OR HOLD('h') = )";
        cin >> input;

        if (input == 'r'){
            roll = rollDice();
            currentScore += roll;
            cout << "You Rolled " << roll << endl;
        }
        else if(input  == 'h'){
            currentScore += roll;
            cout << "You Reached: " << currentScore + humanTotalScore << endl; 
            return currentScore;
        }


    }

    if (roll == 1){
        cout << "You lost the round!" << endl;
        return 0;
    }

    
    
}

int computerTurn(int computerTotalScore){ 

    // computer rolls the dice until rolls 1 or currentSocore reaches the 20 or more.

    int currentScore = 0;

    while(currentScore <= 20){

        int roll = rollDice();
        cout << "Computer rolls " << roll << endl;
        if(roll == 1) {
            cout << "Computer lost the turn!" << endl;
            return 0;
        }

        currentScore += roll;

    }
    cout << "Computer Reached: " << currentScore + computerTotalScore << endl;
    return currentScore;
}   