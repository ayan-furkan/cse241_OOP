#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void aaronShots(bool aaron, bool& bob, bool& charlie);
void bobShots(bool& aaron, bool bob, bool& charlie);
void charlieShots(bool& aaron, bool& bob, bool charlie);

int main(){

    srand(static_cast<int>(time(NULL)));

    // Aeron shots first

    const int looptime = 10000;
    int aaronHit = 0;
    int bobHit = 0;
    int charlieHit = 0;

    bool aaronAlive= true;
    bool bobAlive= true;
    bool charlieAlive= true;


    for(int i=1; i<looptime; i++){

        aaronAlive = true;
        bobAlive = true;
        charlieAlive = true;

        while((bobAlive == true) && (aaronAlive == true) ||
               (bobAlive == true) && (charlieAlive == true) ||
               (aaronAlive == true) && (charlieAlive == true)){

            aaronShots(aaronAlive, bobAlive, charlieAlive);
            bobShots(aaronAlive, bobAlive, charlieAlive);
            charlieShots(aaronAlive, bobAlive, charlieAlive);
    
        }

        if(aaronAlive) aaronHit++;
        else if(bobAlive) bobHit++;
        else if(charlieAlive) charlieHit++;

    }

    double percentA = static_cast<double>(aaronHit) / 100.0;
    double percentB = static_cast<double>(bobHit) / 100.0;
    double percentC = static_cast<double>(charlieHit) / 100.0;

    cout << "Aaron won "<< aaronHit << "/" << looptime << " duels or "<< percentA << "%" << endl;
    cout << "Bob won "<< bobHit << "/" << looptime << " duels or "<< percentB << "%" << endl;
    cout << "Charlie won "<< charlieHit << "/" << looptime << " duels or "<< percentC << "%" << endl;
    

}

void aaronShots(bool aaron, bool& bob, bool& charlie){


    if(aaron == false) //aaron dead
        return;
    
    int rNumber = rand()%3;

    if(rNumber == 0){ //aaron hits

        if(charlie) charlie = false;
        else if (bob) bob = false;
    }

}

void bobShots(bool& aaron, bool bob, bool& charlie){


    if(bob == false) //bob dead
        return;
    
    int rNumber = rand()%2;

    if(rNumber == 0){ //aaron hits

        if(charlie) charlie = false;
        else if (aaron) aaron = false;
    }

}

void charlieShots(bool& aaron, bool& bob, bool charlie){

    if(charlie == false) return; //charlie dead

    if(bob) bob = false;
    else if (aaron) aaron = false;

}