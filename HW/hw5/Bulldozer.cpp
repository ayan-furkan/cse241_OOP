#include <iostream>
#include "Bulldozer.h"
#include "time.h"

using namespace std;

int Bulldozer::count = 0;

Bulldozer::Bulldozer() : Robot() {
    hitpoint = BULLDOZERHIT;
    ID = count;
    count++;
}

Bulldozer::Bulldozer(World *wrld, int x, int y) : Robot(wrld,x,y){
    hitpoint = BULLDOZERHIT;
    ID = count;
    count++;
}

int Bulldozer::getDamage(){

    int damage;

    damage = (rand() % getStrength()) + 1;

    return damage;
}

int Bulldozer::getType(){
    return BULLDOZER;
}

int Bulldozer::getHitpoint(){
    return hitpoint;
}

int Bulldozer::getStrength(){
    return BULLDOZERSTRENGTH;
}

string Bulldozer::getName(){
    return ("bulldozer_" + to_string(ID));
}



