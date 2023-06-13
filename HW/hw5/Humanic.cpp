#include <iostream>
#include <time.h>
#include "Humanic.h"


Humanic::Humanic() : Robot(){

}

Humanic::Humanic(World *world, int x, int y) : Robot(world, x, y){

}

int Humanic::getDamage(){

    int damage = ((rand() % getStrength()) + 1);

    //tactical nuke
    if(rand() % 10 == 0){
        damage += 50;
    }

    //optimusprime strong attack
    if((getType() == OPTIMUSPRIME) && (rand() % 100 < 15)){
        damage *= 2;
    }


    return damage;
}