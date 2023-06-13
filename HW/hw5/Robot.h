

#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <string>
#include "World.h"



using namespace std;

class World;

class Robot{
    friend class World;
    public:

        Robot();
        Robot(World *world, int x, int y);
        ~Robot();

        void setHitpoint(int newHit);


        virtual string getName() = 0;
        virtual int getStrength() = 0;
        virtual int getHitpoint() = 0;
        virtual int getType() = 0;
        virtual int getDamage() = 0;
        void move(); //Move robot until hit another robot the fight

        


    protected:
        int hitpoint;
        bool has_attacked;
        int x,y;
        World *world;
        static int count;
        

};

#endif