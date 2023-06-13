#include <iostream>
#include "Robocop.h"
#include "World.h"

using namespace std;

int Robocop::count = 0;

Robocop::Robocop() : Humanic(){
    hitpoint = ROBOCOPHIT;
    ID = count;
    count++;
}

Robocop::Robocop(World *wrld, int x, int y) : Humanic(wrld, x, y){
    hitpoint = ROBOCOPHIT;
    ID = count;
    count++;
}

string Robocop::getName(){
    return ("robocop_" + to_string(ID));
}

int Robocop::getStrength(){
    return ROBOCOPSTRENGTH;
}
int Robocop::getType(){
    return ROBOCOP;
}
int Robocop::getHitpoint(){
    return hitpoint;
}
