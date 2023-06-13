#include <iostream>
#include "Roomba.h"
#include "time.h"
#include "World.h"

using namespace std;

int Roomba::count = 0;

Roomba::Roomba() : Robot(){
    hitpoint = ROOMBAHIT;
    ID = count;
    count++;
}

Roomba::Roomba(World *wrld, int x, int y) : Robot(wrld, x, y){
    hitpoint = ROOMBAHIT;
    ID = count;
    count++;
}

int Roomba::getDamage(){
    int damage;

    damage = (rand() % getStrength()) + 1; 
    return damage;
}

int Roomba::getType(){
    return ROOMBA;
}

int Roomba::getHitpoint(){
    return hitpoint;
}

int Roomba::getStrength(){
    return ROOMBASTRENGTH;
}

string Roomba::getName(){
    return ("roomba_" + to_string(ID));
}