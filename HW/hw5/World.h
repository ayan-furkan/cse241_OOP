#ifndef WORLD_H
#define WORLD_H


#include <iostream>
#include "Robot.h"


using namespace std;



const int OPTIMUSPRIME = 1;
const int ROBOCOP = 2;
const int ROOMBA = 3;
const int BULLDOZER = 4;

const int WORLDSIZE = 10;

const int OPTIMUSSTRENGTH = 100;
const int ROBOCOPSTRENGTH = 30;
const int ROOMBASTRENGTH = 3;
const int BULLDOZERSTRENGTH = 50;

const int OPTIMUSHIT = 100;
const int ROBOCOPHIT = 40;
const int ROOMBAHIT = 10;
const int BULLDOZERHIT = 200;

class Robot;
class Humanic;
class Optimusprime;
class Robocop;
class Bulldozer;
class Roomba;

class World{
    friend class Robot;
    friend class Humanic;
    friend class Optimusprime;
    friend class Robocop;
    friend class Bulldozer;
    friend class Roomba;
    public:
        World(); //Constructor
        ~World(); //Destructor
        
        void setAt(int x, int y, Robot *robot);
        Robot* getAt(int x, int y);
        void Simulate(); //Simulation
        void Display() const;
        void hitMessage(Robot* attacker, Robot* victim, int damage) const;

    private:
        Robot* grid[WORLDSIZE][WORLDSIZE];
};


#endif