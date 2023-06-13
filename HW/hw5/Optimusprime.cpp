#include <iostream>
#include <string>
#include "Optimusprime.h"
#include "World.h"

using namespace std;

int Optimusprime::count = 0;

Optimusprime::Optimusprime() : Humanic() {
    hitpoint = OPTIMUSHIT;
    ID = count;
    count++;
}

Optimusprime::Optimusprime(World *wrld, int x, int y) : Humanic(wrld, x, y){
    hitpoint = OPTIMUSHIT;
    ID = count;
    count++;
}

string Optimusprime::getName(){
    return ("optimusprime_" + to_string(ID));
}

int Optimusprime::getStrength(){
    return OPTIMUSSTRENGTH;
}

int Optimusprime::getHitpoint(){
    return hitpoint;
}

int Optimusprime::getType(){
    return OPTIMUSPRIME;
}

