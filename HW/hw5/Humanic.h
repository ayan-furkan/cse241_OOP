
#ifndef HUMANIC_H
#define HUMANIC_H

#include <iostream>
#include <string>
#include "Robot.h"


using namespace std;

class World;

class Humanic : public Robot {
    friend class World;
    public:
    Humanic();
    Humanic(World *world, int x, int y);

    virtual string getName() = 0;
    virtual int getStrength() = 0;
    virtual int getHitpoint() = 0;
    virtual int getType() = 0;

    int getDamage();

};


#endif